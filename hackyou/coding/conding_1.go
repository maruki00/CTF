package main

import (
	"encoding/base64"
	"errors"
	"flag"
	"fmt"
	"io"
	"net/http"
	"os"
	"regexp"
	"strings"
	"time"
)

func request(url string, body string) ([]byte, error) {

	req, err := http.NewRequest("POST", url, strings.NewReader(body))
	if err != nil {
		return []byte{}, errors.New("Request error: " + err.Error())
	}
	req.Header.Add("Content-Type", "application/x-www-form-urlencoded")

	client := http.Client{
		//Timeout: time.Second * 1,
	}
	respone, err := client.Do(req)
	if err != nil {
		return []byte{}, errors.New("Client error : " + err.Error())
	}

	return io.ReadAll(respone.Body)
}
func getCode(body []byte) []string {
	r := regexp.MustCompile("<code>(.+)</code>")
	matches := r.FindStringSubmatch(string(body))
	return matches

}
func decode(payload string) string {
	sDec, _ := base64.StdEncoding.DecodeString(payload)
	return string(sDec)
}

func main() {
	var response []byte 
	var err error = nil
	var code []string
	var decodedCode string 
	var url string
	flag.StringVar(&url, "url", "", "url to attack")
	flag.Parse()
	if url == "" {
		println("invalid url")
		os.Exit(-1)
	}

	for {
		response, err = request(url, fmt.Sprintf(`{"answer", %s}`, decodedCode))
		if err != nil {
			println(err)
			break
		}
		code = getCode(response)
		decodedCode = decode(code[1])
		println(decodedCode)
	}
}
