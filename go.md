Install Go

https://medium.com/@patdhlk/how-to-install-go-1-8-on-ubuntu-16-04-710967aa53c9
https://www.digitalocean.com/community/tutorials/how-to-install-go-1-6-on-ubuntu-16-04

After install

test go write:

```
// main.go
package main

import "fmt"

func main() {	
	fmt.Println("Hello from GO")
}
```

to run on cmd

```
go run main.go
```

## Create a simple static web server

```
// main.go
package main

import (
	"net/http"
	"os"
)

func main() {	
	dir, _ := os.Getwd()
	http.ListenAndServe(":3000", http.FileServer(http.Dir(dir)))
}
```

to run on cmd

```
go run main.go
```

check on localhost:3000
