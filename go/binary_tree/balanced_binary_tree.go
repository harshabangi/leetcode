package main

import "math"

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return math.Abs(float64(height(root.Left)-height(root.Right))) <= 1 &&
		isBalanced(root.Left) &&
		isBalanced(root.Right)
}

func height(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + max(height(root.Left), height(root.Right))
}
