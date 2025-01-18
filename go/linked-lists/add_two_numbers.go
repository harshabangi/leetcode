package main

import "fmt"

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	tmp := head
	carry := 0
	b := true

	for l1 != nil || l2 != nil {
		s := carry
		if l1 != nil {
			s += l1.Val
		}
		if l2 != nil {
			s += l2.Val
		}

		r1 := s % 10
		s = s / 10
		carry = s % 10

		if b {
			b = false
			tmp.Val = r1
		} else {
			tmp.Next = &ListNode{Val: r1}
			tmp = tmp.Next
		}

		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if carry == 1 {
		tmp.Next = &ListNode{Val: carry}
		tmp = tmp.Next
	}

	return head
}

func main() {
	m1 := &ListNode{Val: 2, Next: &ListNode{Val: 4, Next: &ListNode{Val: 3}}}
	m2 := &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 4}}}

	head := addTwoNumbers(m1, m2)

	for head != nil {
		fmt.Println(head.Val)
		head = head.Next
	}
}
