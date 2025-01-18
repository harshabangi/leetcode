package main

import "fmt"

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	aLen := 0
	bLen := 0

	tA := headA
	tB := headB

	for tA != nil {
		aLen++
		tA = tA.Next
	}

	for tB != nil {
		bLen++
		tB = tB.Next
	}

	if aLen > bLen {
		n := aLen - bLen
		for n > 0 {
			headA = headA.Next
			n--
		}
	} else {
		n := bLen - aLen
		for n > 0 {
			headB = headB.Next
			n--
		}
	}

	for headA != nil && headB != nil {
		if headA == headB {
			return headA
		}
		headA = headA.Next
		headB = headB.Next
	}
	return nil
}

func main() {
	t := &ListNode{Val: 8, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}
	headA := &ListNode{Val: 4, Next: &ListNode{Val: 1, Next: t}}
	headB := &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 1, Next: t}}}
	fmt.Println(getIntersectionNode(headA, headB))
}
