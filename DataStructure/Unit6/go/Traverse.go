package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归生成一棵二叉树
func dfs(p *TreeNode, depth int) {
	if depth < 3 {
		left := &TreeNode{Val: 2 * depth}
		right := &TreeNode{Val: 4 * depth}
		p.Left = left
		p.Right = right
		dfs(p.Left, depth+1)
		dfs(p.Right, depth+1)
	}
}

// 先序遍历二叉树
func dfsbrAhead(p *TreeNode, res *[]int) {
	if p != nil {
		*res = append(*res, p.Val)
		dfsbrAhead(p.Left, res)
		dfsbrAhead(p.Right, res)
	}
}

// 中序遍历二叉树
func dfsbrIn(p *TreeNode, res *[]int) {
	if p != nil {
		dfsbrIn(p.Left, res)
		*res = append(*res, p.Val)
		dfsbrIn(p.Right, res)
	}
}

// 后序遍历二叉树
func dfsbrBehind(p *TreeNode, res *[]int) {
	if p != nil {
		dfsbrBehind(p.Left, res)
		dfsbrBehind(p.Right, res)
		*res = append(*res, p.Val)
	}
}

func main() {
	root := &TreeNode{}
	dfs(root, 1)
	fmt.Println(root.Left)

}
