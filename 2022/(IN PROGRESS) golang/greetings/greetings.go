package greetings

import "fmt"

// Hello returns a greeting for the given name.

func Hello(name string) string {
	// return a gree
	message := fmt.Sprintf("Hello, %s. Welcome!", name)
	return message
}

