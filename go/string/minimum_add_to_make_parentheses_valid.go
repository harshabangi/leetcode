package main

//type Stack[T any] struct {
//	data []T
//}
//
//func (s *Stack[T]) Size() int {
//	return len(s.data)
//}
//
//func (s *Stack[T]) IsEmpty() bool {
//	return s.Size() == 0
//}
//
//func (s *Stack[T]) Push(x T) {
//	s.data = append(s.data, x)
//}
//
//func (s *Stack[T]) Top() T {
//	if s.IsEmpty() {
//		panic("stack is empty")
//	}
//	return s.data[s.Size()-1]
//}
//
//func (s *Stack[T]) Pop() T {
//	if s.IsEmpty() {
//		panic("stack is empty")
//	}
//	n := s.Size() - 1
//	t := s.data[n]
//	s.data = s.data[:n]
//	return t
//}

func minAddToMakeValid(s string) int {
	r := []rune(s)
	st := &Stack[rune]{}

	for i := 0; i < len(r); i++ {
		if i == 0 || st.IsEmpty() {
			st.Push(r[i])
			continue
		}
		top := st.Top()
		if top == '(' && r[i] == ')' {
			st.Pop()
		} else {
			st.Push(r[i])
		}
	}

	return st.Size()
}
