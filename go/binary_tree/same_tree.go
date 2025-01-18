package main

func isSameTree(p *TreeNode, q *TreeNode) bool {
	switch {
	case p == nil && q == nil:
		return true
	case p == nil && q != nil:
		return false
	case p != nil && q == nil:
		return false
	default:
		return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
	}
}
