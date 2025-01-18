package main

func kthSmallest(root *TreeNode, k int) int {
	ans := -1
	kthSmallestHelper(root, &k, &ans)
	return ans
}

func kthSmallestHelper(root *TreeNode, k *int, ans *int) {
	if root == nil {
		return
	}
	kthSmallestHelper(root.Left, k, ans)
	*k = *k - 1
	if *k == 0 && *ans != -1 {
		*ans = root.Val
		return
	}
	kthSmallestHelper(root.Right, k, ans)
}
