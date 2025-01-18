package main

import (
	"container/heap"
	"fmt"
)

type minHeap struct {
	arr []int
}

func (m *minHeap) Push(x any) {
	m.arr = append(m.arr, x.(int))
}

func (m *minHeap) Pop() any {
	n := m.Len()
	ele := m.arr[n-1]
	m.arr = m.arr[0 : n-1]
	return ele
}

func (m *minHeap) Len() int {
	return len(m.arr)
}

func (m *minHeap) Less(i, j int) bool {
	return m.arr[i] < m.arr[j]
}

func (m *minHeap) Swap(i, j int) {
	m.arr[i], m.arr[j] = m.arr[j], m.arr[i]
}

func findKthLargest(nums []int, k int) int {
	m := &minHeap{arr: []int{}}

	for i := 0; i < len(nums); i++ {
		if i < k {
			heap.Push(m, nums[i])
			continue
		}

		if nums[i] > m.arr[0] {
			heap.Pop(m)
			heap.Push(m, nums[i])
		}
	}

	return m.arr[0]
}

func main() {
	fmt.Println(findKthLargest([]int{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4))
}
