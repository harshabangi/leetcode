package binary_tree

type Queue[T any] struct {
	Elements []T
}

func (q *Queue[T]) Size() int {
	return len(q.Elements)
}

func (q *Queue[T]) IsEmpty() bool {
	return q.Size() == 0
}

func (q *Queue[T]) Push(inp T) {
	q.Elements = append(q.Elements, inp)
}

func (q *Queue[T]) Pop() *T {
	if q.IsEmpty() {
		return nil
	}
	top := q.Elements[0]
	q.Elements = q.Elements[1:]
	return &top
}

func newQueue[T any]() *Queue[T] {
	return &Queue[T]{}
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	q := newQueue[TreeNode]()
	q.Push(*root)

	var result [][]int

	for !q.IsEmpty() {
		size := q.Size()

		out := make([]int, size)
		for i := 0; i < size; i++ {
			t := q.Pop()
			out[i] = t.Val
			if t.Left != nil {
				q.Push(*t.Left)
			}
			if t.Right != nil {
				q.Push(*t.Right)
			}
		}
		result = append(result, out)
	}
	return result
}
