package main

import "fmt"

type Queue[T any] struct {
	data []T
}

func (q *Queue[T]) Push(inp T) {
	q.data = append(q.data, inp)
}

func (q *Queue[T]) Len() int {
	return len(q.data)
}

func (q *Queue[T]) IsEmpty() bool {
	return q.Len() == 0
}

func (q *Queue[T]) Pop() T {
	if q.IsEmpty() {
		panic("queue is empty")
	}
	e := q.data[0]
	q.data = q.data[1:]
	return e
}

func (q *Queue[T]) Top() T {
	if q.IsEmpty() {
		panic("queue is empty")
	}
	return q.data[0]
}

type MyStack struct {
	q *Queue[int]
}

func (this *MyStack) Push(x int) {
	this.q.Push(x)
	n := this.q.Len()
	for i := 0; i < n-1; i++ {
		this.q.Push(this.q.Pop())
	}
}

func (this *MyStack) Pop() int {
	return this.q.Pop()
}

func (this *MyStack) Top() int {
	return this.q.Top()
}

func (this *MyStack) Empty() bool {
	fmt.Println(this.q.data)
	return this.q.IsEmpty()
}

func main() {
	m := &MyStack{q: &Queue[int]{}}
	m.Push(1)
	fmt.Println(m.Pop())
	fmt.Println(m.Empty())
}
