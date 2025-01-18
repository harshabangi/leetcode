package main

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	t := head
	tn := 0
	for t != nil {
		t = t.Next
		tn++
	}

	if tn == 1 {
		return nil
	}

	k := tn - n - 1

	if k < 0 {
		head = head.Next
		return head
	}

	t = head
	for k > 0 {
		t = t.Next
		k--
	}

	t.Next = t.Next.Next
	return head
}
