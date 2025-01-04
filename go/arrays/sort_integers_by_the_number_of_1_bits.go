package main

import "sort"

type integerNumBits struct {
	number  int
	numBits int
}

func sortByBits(arr []int) []int {
	newArr := make([]integerNumBits, len(arr))
	for i := 0; i < len(arr); i++ {
		n := arr[i]
		k := 0
		for n != 0 {
			if n&1 == 1 {
				k++
			}
			n >>= 1
		}
		newArr[i] = integerNumBits{number: arr[i], numBits: k}
	}

	sort.Slice(newArr, func(i, j int) bool {
		if newArr[i].numBits == newArr[j].numBits {
			return newArr[i].number < newArr[j].number
		}
		return newArr[i].numBits < newArr[j].numBits
	})

	ans := make([]int, len(arr))
	for i := 0; i < len(arr); i++ {
		ans[i] = newArr[i].number
	}
	return ans
}
