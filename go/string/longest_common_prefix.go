package main

import (
	"fmt"
	"math"
)

func longestCommonPrefix(strs []string) string {
	minLength := math.MaxInt
	for _, s := range strs {
		minLength = min(minLength, len(s))
	}

	ans := ""

	for i := 0; i < minLength; i++ {
		r := strs[0][i]
		matched := true

		for j := 1; j < len(strs); j++ {
			if r != strs[j][i] {
				matched = false
				break
			}
		}
		if !matched {
			break
		}
		ans += string(r)
	}

	return ans
}

func main() {
	fmt.Println(longestCommonPrefix([]string{"flower", "flow", "flight"}))
}
