package main

import (
	"fmt"
)

type Array struct {
	elem   []int
	length int
}

// 初始化
func (arr *Array) Init() {
	var temp int
	fmt.Println("请输入一组数据的个数:")
	fmt.Scanln(&temp)
	fmt.Println()

	arr.length = temp

	arr.elem = make([]int, 20)

	// arr.elem = new([]int)

	for i := 0; i < temp; i++ {
		fmt.Scanf("%d", &arr.elem[i])
	}
}

// 在第i个元素前插入元素e
func (arr *Array) LinkInsert(i int, e int) {

	temp := arr.length - 1

	for ; temp >= i-1; temp-- {
		arr.elem[temp+1] = arr.elem[temp]
	}

	arr.elem[temp+1] = e

}

// 删除线性表中第i个元素
func (arr *Array) LinkDelete(i int) {

	arr.elem = append(arr.elem[:i-1], arr.elem[i:]...)
}

// 输出链表所有的元素
func (arr *Array) ListTraverse() {

	fmt.Println(arr.elem)
}

func main() {
	var la Array
	pst := &la

	pst.Init()
	// pst.LinkInsert(1, 5)
	pst.LinkDelete(3)
	pst.ListTraverse()
}
