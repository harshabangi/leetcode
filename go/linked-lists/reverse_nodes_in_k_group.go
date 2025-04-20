package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseHelper(head *ListNode, k int) (*ListNode, *ListNode) {
	curr := head
	next := head
	var prev *ListNode

	for k > 0 {
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
		k--
	}

	return prev, curr
}

func reverseKGroupHelper(head *ListNode, k int, numGroups int) *ListNode {
	if numGroups == 0 {
		return head
	}
	prev, curr := reverseHelper(head, k)
	head.Next = reverseKGroupHelper(curr, k, numGroups-1)
	return prev
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	tmp := head
	n := 0
	for tmp != nil {
		n++
		tmp = tmp.Next
	}
	return reverseKGroupHelper(head, k, n/k)
}
