package main

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	m := make(map[int]int)
	st := &Stack[int]{}

	for i := 0; i < len(nums2); i++ {
		if st.IsEmpty() {
			st.Push(nums2[i])
			continue
		}
		for !st.IsEmpty() && nums2[i] > st.Top() {
			m[st.Pop()] = nums2[i]
		}
		st.Push(nums2[i])
	}

	for !st.IsEmpty() {
		m[st.Pop()] = -1
	}

	res := make([]int, len(nums1))
	for i := 0; i < len(nums1); i++ {
		res[i] = m[nums1[i]]
	}
	return res
}
