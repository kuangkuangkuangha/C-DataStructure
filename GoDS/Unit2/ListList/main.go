package main

import "GoDS/Unit2/model"

// 头节点不包含数据

func main() {
	var head1 *model.Node
	head1 = new(model.Node)

	head1.Init()
	head1.ListInsert(2, 4)
	head1.ListTraverse()

}
