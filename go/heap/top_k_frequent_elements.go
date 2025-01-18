package main

import (
	"container/heap"
	"fmt"
)

type data struct {
	num  int
	freq int
}

type minHeap struct {
	data []data
}

func (m *minHeap) Len() int {
	return len(m.data)
}

func (m *minHeap) Less(i, j int) bool {
	return m.data[i].freq < m.data[j].freq
}

func (m *minHeap) Swap(i, j int) {
	m.data[i], m.data[j] = m.data[j], m.data[i]
}

func (m *minHeap) Push(x any) {
	m.data = append(m.data, x.(data))
}

func (m *minHeap) Pop() any {
	n := m.Len()
	e := m.data[n-1]
	m.data = m.data[0 : n-1]
	return e
}

func topKFrequent(nums []int, k int) []int {
	mp := make(map[int]int)
	for _, num := range nums {
		mp[num]++
	}

	m := &minHeap{data: []data{}}
	j := 0
	for p, q := range mp {
		if j < k {
			heap.Push(m, data{num: p, freq: q})
			j++
		} else {
			top := m.data[0]
			if top.freq < q {
				heap.Pop(m)
				heap.Push(m, data{num: p, freq: q})
			}
		}
	}

	result := make([]int, k)
	j = 0
	for m.Len() > 0 {
		e := heap.Pop(m)
		result[j] = e.(data).num
		j++
	}

	return result
}

func main() {
	fmt.Println(topKFrequent([]int{1, 1, 1, 2, 2, 3}, 2))
}
