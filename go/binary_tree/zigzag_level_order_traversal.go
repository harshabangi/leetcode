package binary_tree

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	q := newQueue[TreeNode]()

	q.Push(*root)
	var result [][]int

	j := 0

	for !q.IsEmpty() {
		size := q.Size()

		out := make([]int, size)

		for i := 0; i < size; i++ {
			t := q.Pop()
			if j%2 != 0 {
				out[size-1-i] = t.Val
			} else {
				out[i] = t.Val
			}

			if t.Left != nil {
				q.Push(*t.Left)
			}
			if t.Right != nil {
				q.Push(*t.Right)
			}
		}

		result = append(result, out)
		j++
	}
	return result
}
