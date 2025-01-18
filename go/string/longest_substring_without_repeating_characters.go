package main

import "fmt"

type Deque[T any] struct {
	data []T
}

func (d *Deque[T]) Len() int {
	return len(d.data)
}

func (d *Deque[T]) IsEmpty() bool {
	return d.Len() == 0
}

func (d *Deque[T]) PopFront() T {
	if d.IsEmpty() {
		panic("deque is empty")
	}
	e := d.data[0]
	d.data = d.data[1:]
	return e
}

func (d *Deque[T]) Front() T {
	if d.IsEmpty() {
		panic("deque is empty")
	}
	return d.data[0]
}

func (d *Deque[T]) PushBack(t T) {
	d.data = append(d.data, t)
}

func lengthOfLongestSubstring(s string) int {
	runes := []rune(s)
	n := len(runes)
	m := make(map[rune]struct{})
	dq := Deque[rune]{}
	mx := 0

	for i := 0; i < n; i++ {
		if _, ok := m[runes[i]]; ok {
			mx = max(mx, dq.Len())
			for !dq.IsEmpty() {
				if dq.Front() == runes[i] {
					delete(m, dq.PopFront())
					break
				}
				delete(m, dq.PopFront())
			}
		}
		m[runes[i]] = struct{}{}
		dq.PushBack(runes[i])
	}
	return max(mx, dq.Len())
}

func lengthOfLongestSubstring2(s string) int {
	runes := []rune(s)
	n := len(runes)
	m := make(map[rune]struct{})
	i, j, mx := 0, 0, 0

	for i = 0; i < n; i++ {
		if _, ok := m[runes[i]]; ok {
			mx = max(mx, i-j)
			for {
				delete(m, runes[j])
				if runes[j] == runes[i] {
					j++
					break
				}
				j++
			}
		}
		m[runes[i]] = struct{}{}
	}
	return max(mx, i-j)
}

func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
}
