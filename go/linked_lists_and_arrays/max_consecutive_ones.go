package main

func findMaxConsecutiveOnes(nums []int) int {
	mx := 0
	inter := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			inter++
		} else {
			mx = max(mx, inter)
			inter = 0
		}
	}
	return mx
}
