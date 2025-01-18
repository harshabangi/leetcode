package main

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil {
		return false
	}
	return (root.Val == subRoot.Val && isSameTree(root.Left, subRoot.Left) && isSameTree(root.Right, subRoot.Right)) ||
		isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}
