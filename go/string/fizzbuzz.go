package main

import (
	"strconv"
)

func fizzBuzz(n int) []string {
	r := make([]string, n)
	for i := 1; i <= n; i++ {
		switch {
		case i%3 == 0 && i%5 == 0:
			r[i-1] = "FizzBuzz"
		case i%3 == 0:
			r[i-1] = "Fizz"
		case i%5 == 0:
			r[i-1] = "Buzz"
		default:
			r[i-1] = strconv.FormatInt(int64(i), 10)
		}
	}
	return r
}
