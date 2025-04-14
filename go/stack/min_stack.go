package main

type MinStack struct {
	minimums []int
	data     []int
}

func (this *MinStack) Push(val int) {
	if len(this.data) == 0 {
		this.minimums = append(this.minimums, val)
	} else {
		this.minimums = append(this.minimums, min(this.minimums[len(this.data)-1], val))
	}
	this.data = append(this.data, val)
}

func (this *MinStack) Pop() {
	n := len(this.data)
	this.data = this.data[0 : n-1]
	this.minimums = this.minimums[0 : n-1]
}

func (this *MinStack) Top() int {
	n := len(this.data)
	return this.data[n-1]
}

func (this *MinStack) GetMin() int {
	n := len(this.data)
	return this.minimums[n-1]
}
