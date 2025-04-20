package main

import (
	"fmt"
)

func singleNumber(nums []int) int {
	var ans int
	for i := 0; i < 32; i++ {
		k := 1 << i
		t := 0
		for j := 0; j < len(nums); j++ {
			if nums[j]&k > 0 {
				t++
			}
		}
		if t%3 != 0 {
			ans += k
		}
	}

	if ans&(1<<31) > 0 {
		l := 1
		for j := 0; j < 32; j++ {
			t := 1 << j
			if ans&t == 0 {
				l += t
			}
		}
		return -l
	}
	return ans
}

func main() {
	fmt.Println(singleNumber([]int{-2, -2, 1, 1, 4, 1, 4, 4, -4, -2}))
}
