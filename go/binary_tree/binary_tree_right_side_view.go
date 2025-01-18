package main

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	var ans []int
	q := newQueue[*TreeNode]()
	q.Push(root)

	for !q.IsEmpty() {
		size := q.Size()

		for i := 0; i < size; i++ {
			t := q.Pop()
			if i == size-1 {
				ans = append(ans, t.Val)
			}
			if t.Left != nil {
				q.Push(t.Left)
			}
			if t.Right != nil {
				q.Push(t.Right)
			}
		}
	}
	return ans
}

func main() {

}
