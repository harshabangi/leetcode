package main

import "fmt"

func middleNode(head *ListNode) *ListNode {
	n := 0
	tmp := head
	for tmp != nil {
		n++
		tmp = tmp.Next
	}

	middle := n / 2

	tmp = head
	for ; middle > 0; middle-- {
		tmp = tmp.Next
	}
	return tmp
}

func main() {
	head := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4}}}}
	fmt.Println(middleNode(head).Val)
}
