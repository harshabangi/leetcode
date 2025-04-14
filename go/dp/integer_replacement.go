package main

import "fmt"

func integerReplacementHelper(n int, m map[int]int) int {
	if n == 1 {
		return 0
	}
	if v, ok := m[n]; ok {
		return v
	}
	if n%2 == 0 {
		m[n] = 1 + integerReplacementHelper(n/2, m)
	} else {
		m[n] = 1 + min(integerReplacementHelper(n+1, m), integerReplacementHelper(n-1, m))
	}
	return m[n]
}

func integerReplacement(n int) int {
	m := map[int]int{}
	return integerReplacementHelper(n, m)
}

func main() {
	fmt.Println(integerReplacement(8))
}
