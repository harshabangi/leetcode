package binary_search

func searchRange(nums []int, target int) []int {
	s, e := 0, len(nums)-1

	for s <= e {
		mid := s + (e-s)/2
		if nums[mid] == target {
			i := mid
			j := mid
			for i >= 0 && nums[i] == target {
				i--
			}
			for j < len(nums) && nums[j] == target {
				j++
			}
			return []int{i + 1, j - 1}
		} else if nums[mid] < target {
			s = mid + 1
		} else {
			e = mid - 1
		}
	}

	return []int{-1, -1}
}
