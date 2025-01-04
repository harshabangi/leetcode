package binary_tree

func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}
	parentMap := make(map[TreeNode]*TreeNode)
	parentMap[*root] = nil

	fillParentMap(root, parentMap)

	doDepthFirstSearch(root, parentMap)

}

func fillParentMap(root *TreeNode, pMap map[TreeNode]*TreeNode) {
	if root == nil {
		return
	}
	if root.Left != nil {
		pMap[*root.Left] = root
		fillParentMap(root.Left, pMap)
	}
	if root.Right != nil {
		pMap[*root.Right] = root
		fillParentMap(root.Right, pMap)
	}
}

func doDepthFirstSearch(root *TreeNode, pMap map[TreeNode]*TreeNode) {
	if root == nil {
		return
	}
	1 + height2(root.Left, pMap) + height2(root.Right, pMap)
	doDepthFirstSearch(root.Left, pMap)
	doDepthFirstSearch(root.Right, pMap)
}

func height2(node *TreeNode, pMap map[TreeNode]*TreeNode) int {
	if node == nil {
		return 0
	}
	return 1 + max(max(height2(node.Left, pMap), height2(node.Right, pMap)), height2(pMap[*node], pMap))
}
