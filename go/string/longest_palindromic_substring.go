package main

import "fmt"

func longestPalindrome(s string) string {
	sr := []rune(s)

	n := len(sr)
	mxLength := -1
	var str []rune

	for i := 0; i < n; i++ {
		ln, j, k := 1, i, 0

		for j, k = i-1, i+1; j >= 0 && k < n; j, k = j-1, k+1 {
			if sr[j] != sr[k] {
				break
			}
			ln += 2
		}
		if ln > mxLength {
			mxLength = ln
			str = sr[j+1 : k]
		}

		ln = 0
		for j, k = i, i+1; j >= 0 && k < n; j, k = j-1, k+1 {
			if sr[j] != sr[k] {
				break
			}
			ln += 2
		}
		if ln > mxLength {
			mxLength = ln
			str = sr[j+1 : k]
		}
	}

	return string(str)
}

func main() {
	fmt.Println(longestPalindrome("babad"))
}
