package main

import "fmt"

func generateParenthesis(n int) []string {
	var ans []string
	generateParenthesisHelper(n, n, "", &ans)
	return ans
}

func generateParenthesisHelper(m, n int, s string, ans *[]string) {
	if m == 0 && n == 0 {
		*ans = append(*ans, s)
		return
	}
	if m > 0 {
		generateParenthesisHelper(m-1, n, s+"(", ans)
	}
	if n > m {
		generateParenthesisHelper(m, n-1, s+")", ans)
	}
}

func main() {
	fmt.Println(generateParenthesis(4))
}
