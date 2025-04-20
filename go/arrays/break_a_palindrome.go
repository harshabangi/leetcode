package main

import "fmt"

func breakPalindrome(palindrome string) string {
	if len(palindrome) <= 1 {
		return ""
	}

	r := []rune(palindrome)
	for i := 0; i < len(r)/2; i++ {
		if r[i] != 'a' {
			r[i] = 'a'
			return string(r)
		}
	}

	r[len(r)-1] = 'a'
	return string(r)
}

func main() {
	fmt.Println(breakPalindrome("a"))
	fmt.Println(breakPalindrome("bccb"))
	fmt.Println(breakPalindrome("cffc"))
	fmt.Println(breakPalindrome("cdccccdc"))
	fmt.Println(breakPalindrome("aacddcaa"))
	fmt.Println(breakPalindrome("aacaa"))
	fmt.Println(breakPalindrome("aacaaaacaa"))
	fmt.Println(breakPalindrome("aaa"))
}
