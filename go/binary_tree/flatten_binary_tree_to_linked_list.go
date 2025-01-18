package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Queue[T any] struct {
	data []T
}

func newQueue[T any]() *Queue[T] {
	return &Queue[T]{}
}

func (q *Queue[T]) Size() int {
	return len(q.data)
}

func (q *Queue[T]) IsEmpty() bool {
	return q.Size() == 0
}

func (q *Queue[T]) Push(x T) {
	q.data = append(q.data, x)
}

func (q *Queue[T]) Pop() T {
	if q.Size() == 0 {
		panic("queue is empty")
	}
	top := q.data[0]
	q.data = q.data[1:]
	return top
}

func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	q := newQueue[*TreeNode]()
	postOrder(root, q)

	var prev *TreeNode

	for !q.IsEmpty() {
		t := q.Pop()
		t.Left = nil
		t.Right = nil

		if prev == nil {
			prev = t
			continue
		}

		prev.Right = t
		prev = prev.Right
	}
}

func postOrder(root *TreeNode, q *Queue[*TreeNode]) {
	if root == nil {
		return
	}
	q.Push(root)
	postOrder(root.Left, q)
	postOrder(root.Right, q)
}

func main() {
	flatten(&TreeNode{Val: 1, Left: &TreeNode{Val: 2, Left: &TreeNode{Val: 3}, Right: &TreeNode{Val: 4}}, Right: &TreeNode{Val: 5, Right: &TreeNode{Val: 6}}})
}
