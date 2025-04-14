package main

import "fmt"

func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	var odd, even, evenHead *ListNode
	tmp := head

	i := 1
	for tmp != nil {
		switch {
		case i == 1:
			odd = tmp
		case i == 2:
			evenHead = tmp
			even = tmp
		case i%2 == 1:
			odd.Next = tmp
			odd = odd.Next
		default:
			even.Next = tmp
			even = even.Next
		}
		i++
		tmp = tmp.Next
	}
	if even != nil {
		even.Next = nil
	}
	odd.Next = evenHead
	return head
}

func oddEvenList2(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	odd := head
	even := head.Next
	evenHead := even

	for even != nil && even.Next != nil {
		odd.Next = odd.Next.Next
		even.Next = even.Next.Next
		odd = odd.Next
		even = even.Next
	}
	odd.Next = evenHead
	return head
}

func printList(head *ListNode) {
	for head != nil {
		fmt.Print(head.Val, "->")
		head = head.Next
	}
}

func main() {
	printList(oddEvenList(&ListNode{Val: 1, Next: &ListNode{Val: 2}}))
}
