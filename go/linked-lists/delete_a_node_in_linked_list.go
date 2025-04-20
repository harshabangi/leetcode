package main

import "fmt"

func deleteNode(node *ListNode) {
	t := node.Next.Val
	node.Next.Val = node.Val
	node.Val = t
	node.Next = node.Next.Next
}

func print(inp *ListNode) {
	if inp == nil {
		return
	}
	for inp != nil {
		fmt.Print(inp.Val, " ")
		inp = inp.Next
	}
}

func main() {
	head := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}}
	deleteNode(head)
	print(head)
}
