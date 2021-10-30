package model

import (
	"fmt"
)

// 头节点不存数据

type Node struct {
	data int
	next *Node
}

// 初始化一个链表
func (head *Node) Init() {
	var a int
	head.next = nil

	fmt.Println("请输入一组数据的个数:")
	fmt.Scanf("%d", &a)

	pst := head

	fmt.Println("")

	for i := 0; i < a; i++ {
		temp := new(Node)
		fmt.Scanf("%d", &temp.data)

		pst.next = temp

		pst = temp
	}

	pst.next = nil
}

// 销毁链表

// 在第i个元素前插入一个元素
func (head *Node) ListInsert(i int, data int) {

	pst := head
	temp := new(Node)
	temp.data = data

	for k := 1; k < i; k++ {
		pst = pst.next
	}

	temp.next = pst.next
	pst.next = temp
}

// 获取链表的长度
func (head *Node) ListLength() int {
	count := 0
	temp := head.next

	for temp != nil {
		count++
		temp = temp.next
	}

	return count
}

// 输出链表的所有元素
func (head *Node) ListTraverse() {

	temp := head.next
	fmt.Println("链表元素是:")

	for temp != nil {
		fmt.Println(temp.data)
		temp = temp.next
	}
}
