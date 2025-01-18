package main

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	q := newQueue[*Node]()
	q.Push(root)

	for !q.IsEmpty() {
		size := q.Size()

		var prev *Node

		for i := 0; i < size; i++ {
			t := q.Pop()
			if prev != nil {
				prev.Next = t
			}
			prev = t

			if t.Left != nil {
				q.Push(t.Left)
			}
			if t.Right != nil {
				q.Push(t.Right)
			}
		}
	}

	return root
}
