package main

import "math"

func findSecondMinimumValue(root *TreeNode) int {
	firstMin := math.MaxInt
	secondMin := math.MaxInt

	findSecondMinimumValueHelper(root, &firstMin, &secondMin)

	if firstMin == secondMin {
		return -1
	}
	return secondMin
}

func findSecondMinimumValueHelper(root *TreeNode, firstMin *int, secondMin *int) {
	if root == nil {
		return
	}
	findSecondMinimumValueHelper(root.Left, firstMin, secondMin)
	if root.Val < *firstMin {
		*secondMin = *firstMin
		*firstMin = root.Val
	}
	if root.Val < *secondMin && root.Val != *firstMin {
		*secondMin = root.Val
	}
	findSecondMinimumValueHelper(root.Right, firstMin, secondMin)
}
