package models

import (
	"github.com/jinzhu/gorm"
)

type Question struct {
	gorm.Model
	QuestionID		string  `gorm:"primary_key"`//问题ID
	UserAccount   	string //创建者
	Title    		string //问题名
	Qcontent 		string //问题内容
	AnswerNum   	uint   //回答数(热点数)
	//URL      string
}
