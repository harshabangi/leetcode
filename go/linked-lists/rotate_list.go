package main

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	tmp := head
	n := 0
	for tmp != nil {
		n++
		tmp = tmp.Next
	}

	if k >= n {
		k %= n
	}

	if k == 0 {
		return head
	}

	l := n - k
	tmp = head
	var prev *ListNode
	var newHead *ListNode

	for l > 0 {
		prev = tmp
		tmp = tmp.Next
		l--
	}
	prev.Next = nil
	newHead = tmp

	for tmp.Next != nil {
		tmp = tmp.Next
	}
	tmp.Next = head
	return newHead
}

func main() {
	head := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}}
	print(rotateRight(head, 10))
}
