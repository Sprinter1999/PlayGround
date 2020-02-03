package models

import (
	"github.com/jinzhu/gorm"
)

type Answer struct {
	gorm.Model
	QuestionID  string `gorm:"primary_key"`//问题ID
	Nickname	string	//用户名字
	Content     string `sql:"size:999999"`  //回答的内容
	//Verify     bool
}
