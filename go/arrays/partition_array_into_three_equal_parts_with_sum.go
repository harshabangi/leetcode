package main

import "fmt"

func canThreePartsEqualSum(arr []int) bool {
	cum := make([]int, len(arr))
	c := 0
	for i := 0; i < len(arr); i++ {
		c += arr[i]
		cum[i] = c
	}

	n := len(arr)

	for i := 0; i < n-2; i++ {
		x1 := cum[i]
		for j := i + 1; j < n-1; j++ {
			x2 := cum[j] - cum[i]
			x3 := cum[n-1] - cum[j]
			if x1 == x2 && x2 == x3 {
				return true
			}
		}
	}
	return false
}

func main() {
	fmt.Println(canThreePartsEqualSum([]int{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1}))
}
