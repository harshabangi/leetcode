package main

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
		n := len(q.data)

		if n == 1 {
			maxWidth = max(maxWidth, 1)
		} else {
			maxWidth = max(maxWidth, q.data[n-1].number-q.data[0].number)
		}

		for i := 0; i < n; i++ {
			node := q.data[i].node
			num := q.data[i].number

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
