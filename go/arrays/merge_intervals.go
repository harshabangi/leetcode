package main

import "sort"

type Stack[T any] []T

func (s *Stack[T]) Size() int {
	if s == nil {
		return 0
	}
	return len(*s)
}

func (s *Stack[T]) IsEmpty() bool {
	return s.Size() == 0
}

func (s *Stack[T]) Push(inp T) {
	if s == nil {
		return
	}
	*s = append(*s, inp)
}

func (s *Stack[T]) Top() *T {
	if s.Size() == 0 {
		return nil
	}
	return &(*s)[s.Size()-1]
}

func (s *Stack[T]) Pop() *T {
	size := s.Size()
	if size == 0 {
		return nil
	}
	top := (*s)[size-1]
	*s = (*s)[:size-1]
	return &top
}

func mergeIntervals(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] < intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})

	st := Stack[[]int]{}

	for _, in := range intervals {
		if st.IsEmpty() {
			st.Push(in)
			continue
		}

		top := st.Top()
		if (*top)[1] >= in[0] {
			st.Pop()
			st.Push([]int{(*top)[0], max((*top)[1], in[1])})
		} else {
			st.Push(in)
		}
	}
	return st
}
