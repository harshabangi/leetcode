package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//type Queue[T any] struct {
//	data []T
//}
//
//func (q *Queue[T]) Empty() bool {
//	return q.Len() == 0
//}
//
//func (q *Queue[T]) Len() int {
//	return len(q.data)
//}
//
//func (q *Queue[T]) Push(inp T) {
//	q.data = append(q.data, inp)
//}
//
//func (q *Queue[T]) Pop() T {
//	if q.Len() == 0 {
//		panic("queue is empty")
//	}
//	e := q.data[0]
//	q.data = q.data[1:]
//	return e
//}
//
//func (q *Queue[T]) Front() T {
//	if q.Len() == 0 {
//		panic("queue is empty")
//	}
//	return q.data[0]
//}

func dfs(root *TreeNode, parentMap map[int]*TreeNode, startNode *TreeNode, start int) {
	if root.Val == start {
		*startNode = *root
	}

	if root.Left != nil {
		parentMap[root.Left.Val] = root
		dfs(root.Left, parentMap, startNode, start)
	}

	if root.Right != nil {
		parentMap[root.Right.Val] = root
		dfs(root.Right, parentMap, startNode, start)
	}
}

func bfs(root *TreeNode, parentMap map[int]*TreeNode) int {
	q := Queue[*TreeNode]{}
	q.Push(root)
	depth := 0
	visited := make(map[int]struct{})
	visited[root.Val] = struct{}{}

	for !q.Empty() {
		size := q.Len()

		for i := 0; i < size; i++ {
			t := q.Pop()
			if t.Left != nil {
				if _, ok := visited[t.Left.Val]; !ok {
					q.Push(t.Left)
					visited[t.Left.Val] = struct{}{}
				}
			}
			if t.Right != nil {
				if _, ok := visited[t.Right.Val]; !ok {
					q.Push(t.Right)
					visited[t.Right.Val] = struct{}{}
				}
			}
			parent := parentMap[t.Val]
			if parent != nil {
				if _, ok := visited[parent.Val]; !ok {
					q.Push(parent)
					visited[parent.Val] = struct{}{}
				}
			}
		}

		depth++
	}
	return depth - 1
}

func amountOfTime(root *TreeNode, start int) int {
	if root == nil {
		return 0
	}
	parentMap := make(map[int]*TreeNode)
	parentMap[root.Val] = nil

	startNode := &TreeNode{}
	dfs(root, parentMap, startNode, start)

	return bfs(startNode, parentMap)
}

func main() {
	var head *TreeNode = &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val: 5,
			Right: &TreeNode{
				Val:   4,
				Left:  &TreeNode{Val: 9},
				Right: &TreeNode{Val: 2},
			},
		},
		Right: &TreeNode{
			Val:   3,
			Left:  &TreeNode{Val: 10},
			Right: &TreeNode{Val: 6},
		},
	}
	fmt.Println(amountOfTime(head, 3))
}
