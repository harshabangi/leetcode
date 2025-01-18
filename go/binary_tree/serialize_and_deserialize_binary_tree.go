package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return "[]"
	}
	q := Queue[*TreeNode]{}
	q.Push(root)
	ans := []string{strconv.Itoa(root.Val)}

	for !q.IsEmpty() {
		size := q.Size()
		allNull := true
		var t []string

		for i := 0; i < size; i++ {
			front := q.Pop()

			if front.Left != nil {
				t = append(t, strconv.Itoa(front.Left.Val))
				q.Push(front.Left)
				allNull = false
			} else {
				t = append(t, "null")
			}

			if front.Right != nil {
				t = append(t, strconv.Itoa(front.Right.Val))
				allNull = false
				q.Push(front.Right)
			} else {
				t = append(t, "null")
			}
		}

		if !allNull {
			ans = append(ans, t...)
		}
	}
	return fmt.Sprintf("[%s]", strings.Join(ans, ","))
}

func toInt(inp string) int {
	out, _ := strconv.Atoi(inp)
	return out
}

func (this *Codec) deserialize(data string) *TreeNode {
	if data == "[]" {
		return nil
	}

	r := []rune(data)
	r = r[1 : len(r)-1]

	slices := strings.Split(string(r), ",")

	q1 := newQueue[string]()
	q2 := newQueue[*TreeNode]()
	for _, s := range slices {
		q1.Push(s)
	}

	root := &TreeNode{Val: toInt(q1.Pop())}
	recentParent := root
	j := 0

	for !q1.IsEmpty() {
		t := q1.Pop()
		var newNode *TreeNode
		if t == "null" {
			newNode = nil
		} else {
			newNode = &TreeNode{Val: toInt(t)}
			q2.Push(newNode)
		}

		if j == 0 {
			recentParent.Left = newNode
			j++
		} else {
			recentParent.Right = newNode
			j = 0
			recentParent = q2.Pop()
		}
	}
	return root
}

func main() {
	r := &TreeNode{Val: 1, Left: &TreeNode{Val: 2}, Right: &TreeNode{Val: 3, Right: &TreeNode{Val: 5, Left: &TreeNode{Val: 6}}}}
	codec := Codec{}
	fmt.Println(codec.serialize(r))
}
