package main

func isValid(s string) bool {
	st := &Stack[rune]{}
	r := []rune(s)

	for i := 0; i < len(s); i++ {
		if st.IsEmpty() {
			st.Push(r[i])
			continue
		}

		if r[i] == '(' || r[i] == '{' || r[i] == '[' {
			st.Push(r[i])
			continue
		}

		if r[i] == ')' && st.Top() == '(' {
			st.Pop()
		} else if r[i] == '}' && st.Top() == '{' {
			st.Pop()
		} else if r[i] == ']' && st.Top() == '[' {
			st.Pop()
		} else {
			return false
		}
	}

	return st.Size() == 0
}
