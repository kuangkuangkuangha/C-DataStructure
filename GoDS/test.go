package main

import "fmt"

func main() {
	var a *[3]int
	var b []int

	a = new([3]int)
	b = make([]int, 4)

	fmt.Println((*a)[2])
	fmt.Println(":haha")
	fmt.Println(b)
}
