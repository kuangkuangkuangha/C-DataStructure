package main

import "fmt"

// 人 基类
type Person struct {
	name    string
	sex     string
	id_card string
	birth   string
}

func (temp Person) Show() {
	fmt.Println("姓名:", temp.name)
	fmt.Println("性别:", temp.sex)
	fmt.Println("生份证号:", temp.id_card)
	fmt.Println("生日:", temp.birth)
}

// 学生 派生类
type Student struct {
	Person
	no    string
	grade int
}

func (temp Student) Show() {
	// temp.Show()
	fmt.Println("学号:", temp.no)
	fmt.Println("成绩:", temp.grade)
}

// 老师 派生类
type Teacher struct {
	Person
	position string
}

func (temp Teacher) Show() {
	println("职位:", temp.position)
}

func main() {
	mike := Person{
		name:    "mike",
		sex:     "男",
		id_card: "2020213791",
		birth:   "2020-5-1",
	}
	mike.Show()

	println()

	cyw := Student{Person{"cyw", "girl", "363401", "2002"}, "2020213", 100}

	cyw.Person.Show()
	cyw.Show()

	println()

	zk := Teacher{Person{"zk", "boy", "360802", "2002"}, "教授"}
	zk.Person.Show()
	zk.Show()
}
