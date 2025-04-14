package main

type MyQueue struct {
	stack1 *Stack[int]
	stack2 *Stack[int]
}

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

func Constructor() MyQueue {
	return MyQueue{
		stack1: &Stack[int]{},
		stack2: &Stack[int]{},
	}
}

func (this *MyQueue) Push(x int) {
	for !this.stack1.IsEmpty() {
		this.stack2.Push(this.stack1.Pop())
	}
	this.stack1.Push(x)
	for !this.stack2.IsEmpty() {
		this.stack1.Push(this.stack2.Pop())
	}
}

func (this *MyQueue) Pop() int {
	return this.stack1.Pop()
}

func (this *MyQueue) Peek() int {
	return this.stack1.Top()
}

func (this *MyQueue) Empty() bool {
	return this.stack1.IsEmpty()
}
