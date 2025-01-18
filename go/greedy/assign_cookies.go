package main

import (
	"fmt"
	"sort"
)

func findContentChildren(g []int, s []int) int {
	sort.Slice(g, func(i, j int) bool {
		return g[i] < g[j]
	})
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})

	ans := 0
	i, j := 0, 0

	for i < len(s) && j < len(g) {
		if s[i] >= g[j] {
			ans++
			i++
			j++
		} else {
			i++
		}
	}
	return ans
}

func main() {
	fmt.Println(findContentChildren([]int{7, 8, 9, 10}, []int{5, 6, 7, 8}))
}
