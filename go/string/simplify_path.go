package main

import "fmt"

type Stack[T any] struct {
	Elements []T
}

func (s *Stack[T]) Size() int {
	return len(s.Elements)
}

func (s *Stack[T]) IsEmpty() bool {
	return s.Size() == 0
}

func (s *Stack[T]) Push(x T) {
	s.Elements = append(s.Elements, x)
}

func (s *Stack[T]) Top() T {
	if s.IsEmpty() {
		panic("stack is empty")
	}
	return s.Elements[s.Size()-1]
}

func (s *Stack[T]) Pop() T {
	if s.IsEmpty() {
		panic("stack is empty")
	}
	n := s.Size() - 1
	t := s.Elements[n]
	s.Elements = s.Elements[:n]
	return t
}

func simplifyPath(path string) string {
	r := []rune(path)
	st := Stack[string]{}
	firstSlash := true
	var l []rune

	for i := 0; i < len(r); i++ {
		if r[i] == '/' {
			if firstSlash {
				firstSlash = false
				continue
			}
			s := string(l)
			if s == ".." {
				if !st.IsEmpty() {
					st.Pop()
				}
			} else if s != "" && s != "." {
				st.Push(s)
			}
			l = []rune{}
		} else {
			l = append(l, r[i])
		}
	}

	if len(l) > 0 {
		s := string(l)
		if s == ".." {
			if !st.IsEmpty() {
				st.Pop()
			}
		} else if s != "" && s != "." {
			st.Push(s)
		}
	}

	ans := ""
	for !st.IsEmpty() {
		k := st.Pop()
		ans = "/" + k + ans
	}
	if ans == "" {
		ans = "/"
	}
	return ans
}

func main() {
	fmt.Println(simplifyPath("/a//b////c/d//././/.."))
}
