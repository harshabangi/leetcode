package main

import "fmt"

func romanToInt(s string) int {
	r := []rune(s)

	sum := 0

	m := map[rune]int{
		'I': 1, 'V': 5, 'X': 10, 'L': 50,
		'C': 100, 'D': 500, 'M': 1000,
	}

	prevValue := 0

	for i := len(s) - 1; i >= 0; i-- {
		if i == len(s)-1 {
			prevValue = m[r[i]]
			sum += prevValue
			continue
		}

		l := m[r[i]]
		if l >= prevValue {
			sum += l
		} else {
			sum -= l
		}
		prevValue = l
	}
	return sum
}

func main() {
	fmt.Println(romanToInt("MCMXCIV"))
}
