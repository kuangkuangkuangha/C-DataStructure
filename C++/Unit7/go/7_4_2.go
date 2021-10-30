package main

import (
	"fmt"
)

type Shape interface {
	area() float32
	show()
}

// 点类
type Point struct {
	x int
	y int
}

func (model Point) area() float32 {
	return 0
}

func (model Point) show() {
	fmt.Println("圆心: ", "X: ", model.x, "Y: ", model.y)
}

// 圆类
type Circle struct {
	radius float32
}

func (model Circle) area() float32 {
	return 3.14 * model.radius * model.radius
}

func (model Circle) show() {
	fmt.Println("圆的半径是:", model.radius)
}

// 圆柱累
type Cylinder struct {
	Circle
	height float32
}

func (model Cylinder) area() float32 {
	return model.Circle.area() * model.height
}

func (model Cylinder) show() {
	model.Circle.show()
	fmt.Println("圆柱的高是: ", model.height)
}

func main() {
	var a Shape
	mod := Circle{20}
	a = mod
	a.area()
	a.show()

	mod2 := Point{8, 8}
	a = mod2
	a.area()
	a.show()

	mod3 := Cylinder{Circle{2}, 8}
	mod3.show()
	mod3.area()
}
