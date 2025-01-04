package binary_tree

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return areTwoNodesSymmetric(root.Left, root.Right)
}

func areTwoNodesSymmetric(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}
	return left.Val == right.Val &&
		areTwoNodesSymmetric(left.Left, right.Right) &&
		areTwoNodesSymmetric(left.Right, right.Left)
}
