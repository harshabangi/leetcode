package main

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
