package main

import "fmt"

func reverse(inp *ListNode) *ListNode {
	curr := inp
	next := inp
	var prev *ListNode

	for curr != nil {
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}

func traverse(head *ListNode, t int) *ListNode {
	tmp := head
	for t > 0 {
		tmp = tmp.Next
		t--
	}
	return tmp
}

func checkPalindrome(head1, head2 *ListNode, t int) bool {
	for t > 0 {
		if head1.Val != head2.Val {
			return false
		}
		head1 = head1.Next
		head2 = head2.Next
		t--
	}
	return true
}

func isPalindrome(head *ListNode) bool {
	n := 0
	tmp := head
	for tmp != nil {
		n++
		tmp = tmp.Next
	}

	if n%2 == 0 {
		tmp = traverse(head, n/2)
		return checkPalindrome(head, reverse(tmp), n/2)
	} else {
		if n == 1 {
			return true
		}
		tmp = traverse(head, n/2+1)
		return checkPalindrome(head, reverse(tmp), n/2)
	}
}

func main() {
	head := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 2}}}
	fmt.Println(isPalindrome(head))
}
