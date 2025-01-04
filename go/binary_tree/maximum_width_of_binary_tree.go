package binary_tree

//type Queue[T any] struct {
//	Elements []T
//}
//
//func newQueue[T any]() *Queue[T] {
//	return &Queue[T]{}
//}
//
//func (q *Queue[T]) Size() int {
//	return len(q.Elements)
//}
//
//func (q *Queue[T]) IsEmpty() bool {
//	return q.Size() == 0
//}
//
//func (q *Queue[T]) Push(x T) {
//	q.Elements = append(q.Elements, x)
//}
//
//func (q *Queue[T]) Pop() *T {
//	if q.Size() == 0 {
//		return nil
//	}
//	top := q.Elements[0]
//	q.Elements = q.Elements[1:]
//	return &top
//}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type N struct {
	node   *TreeNode
	number int
}

func widthOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	maxWidth := 1
	q := newQueue[N]()
	q.Push(N{node: root, number: 1})

	for !q.IsEmpty() {
		n := len(q.Elements)

		if n == 1 {
			maxWidth = max(maxWidth, 1)
		} else {
			maxWidth = max(maxWidth, q.Elements[n-1].number-q.Elements[0].number)
		}

		for i := 0; i < n; i++ {
			node := q.Elements[i].node
			num := q.Elements[i].number

			if node.Left != nil {
				q.Push(N{node: node.Left, number: 2*num - 1})
			}
			if node.Right != nil {
				q.Push(N{node: node.Right, number: 2 * num})
			}
			q.Pop()
		}
	}

	return maxWidth
}
