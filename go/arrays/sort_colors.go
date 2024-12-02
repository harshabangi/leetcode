package main

func sortColors(nums []int) {
	numZeroes := 0
	numOnes := 0
	numTwos := 0

	for _, val := range nums {
		if val == 0 {
			numZeroes++
		} else if val == 1 {
			numOnes++
		} else {
			numTwos++
		}
	}

	for i := 0; i < len(nums); i++ {
		if numZeroes > 0 {
			nums[i] = 0
			numZeroes--
		} else if numOnes > 0 {
			nums[i] = 1
			numOnes--
		} else {
			nums[i] = 2
		}
	}
}
