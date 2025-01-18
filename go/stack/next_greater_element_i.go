package main

type Stack[T any] struct {
	data []T
}

func (s *Stack[T]) Size() int {
	return len(s.data)
}

func (s *Stack[T]) IsEmpty() bool {
	return s.Size() == 0
}

func (s *Stack[T]) Push(x T) {
	s.data = append(s.data, x)
}

func (s *Stack[T]) Top() T {
	if s.IsEmpty() {
		panic("stack is empty")
	}
	return s.data[s.Size()-1]
}

func (s *Stack[T]) Pop() T {
	if s.IsEmpty() {
		panic("stack is empty")
	}
	n := s.Size() - 1
	t := s.data[n]
	s.data = s.data[:n]
	return t
}

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
