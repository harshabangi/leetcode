package main

func majorityElement(nums []int) int {
	ele := nums[0]
	t := 1

	for i := 1; i < len(nums); i++ {
		if t == 0 {
			ele = nums[i]
			t = 1
		} else if ele == nums[i] {
			t++
		} else {
			t--
		}
	}
	return ele
}
