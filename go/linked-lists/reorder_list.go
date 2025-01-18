package main

type Deque[T any] struct {
	data []T
}

func (d *Deque[T]) Len() int {
	return len(d.data)
}

func (d *Deque[T]) IsEmpty() bool {
	return d.Len() == 0
}

func (d *Deque[T]) PopFront() T {
	if d.IsEmpty() {
		panic("deque is empty")
	}
	e := d.data[0]
	d.data = d.data[1:]
	return e
}

func (d *Deque[T]) PopBack() T {
	if d.IsEmpty() {
		panic("deque is empty")
	}
	n := d.Len()
	e := d.data[n-1]
	d.data = d.data[0 : n-1]
	return e
}

func (d *Deque[T]) PushBack(inp T) {
	d.data = append(d.data, inp)
}

func (d *Deque[T]) Front() T {
	if d.IsEmpty() {
		panic("deque is empty")
	}
	return d.data[0]
}

func reorderList(head *ListNode) {
	dq := Deque[*ListNode]{}
	tmp := head
	for tmp != nil {
		dq.PushBack(tmp)
		tmp = tmp.Next
	}

	var back *ListNode

	for {
		if dq.IsEmpty() {
			break
		}
		front := dq.PopFront()
		if back != nil {
			back.Next = front
		}
		if dq.IsEmpty() {
			front.Next = nil
			break
		}
		back = dq.PopBack()
		front.Next = back
		back.Next = nil
	}
}

func main() {
	//head := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}}
	head2 := &ListNode{Val: 1, Next: &ListNode{Val: 2}}
	reorderList(head2)
	print(head2)
}
