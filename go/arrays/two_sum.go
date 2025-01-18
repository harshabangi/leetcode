package main

import "sort"

type indexedData struct {
	data  int
	index int
}

func twoSum(nums []int, target int) []int {
	s := make([]indexedData, len(nums))
	for i := 0; i < len(nums); i++ {
		s[i] = indexedData{data: nums[i], index: i}
	}

	sort.Slice(s, func(i, j int) bool {
		return s[i].data < s[j].data
	})

	i, j := 0, len(nums)-1
	for i < j {
		if s[i].data+s[j].data == target {
			break
		} else if s[i].data+s[j].data < target {
			i++
		} else {
			j--
		}
	}
	return []int{s[i].index, s[j].index}
}
