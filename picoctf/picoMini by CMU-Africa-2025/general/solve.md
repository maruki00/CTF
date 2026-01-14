`
cat server.log | grep FLAGPART | awk -F: '{print $4}' | uniq
`
