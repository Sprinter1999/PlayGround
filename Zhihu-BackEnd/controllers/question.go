package controllers

import (
	"../models"
	"fmt"
	_ "fmt"
	"github.com/gin-gonic/gin"
	"github.com/jinzhu/gorm"
	"math/rand"
	_ "net/http"
	"strconv"
	"time"
)

//创建问题
func CreateQuestion(c *gin.Context){
	type questioninfo struct{
		gorm.Model
		Token string
		Title string
		Qcontent string
	}
	var question questioninfo
	c.BindJSON(&question)
	parse, _ := ParseToken(question.Token)
	var q models.Question
	q.Model = question.Model
	rand.Seed(time.Now().UnixNano())
	//初始化问题
	q.QuestionID = strconv.Itoa(rand.Intn(99999))
	q.UserAccount = parse.Username
	q.Title = question.Title
	q.Qcontent = question.Qcontent
	q.AnswerNum = 0
	db.Save(&q)
	c.JSON(200, gin.H{
		"code": 0,
		"message": "创建成功",
	})
}

//列出问题列表
func ListQuestions(c *gin.Context) {
	var question []models.Question
	if err := db.Order("answer_num desc").Find(&question).Error; err != nil {
		c.JSON(200, gin.H{
			"code": 1,
			"message": "问题列表为空",
		})
	} else {
		c.JSON(200, gin.H{
			"code": 0,
			"message": "问题列表",
			"question": question,
		})
	}
}

//按标题搜索某个问题
func FindQuestions(c *gin.Context){
	var question models.Question
	c.BindJSON(&question)
	fmt.Println(question.Title)
	if err:= db.First(&question, "title = ?", question.Title).Error;err !=nil{
		c.JSON(200, gin.H{
			"code": 1,
			"message": "不存在该问题",
		})
	}else{
		c.JSON(200, gin.H{
			"code": 0,
			"message": "查找成功",
			"question": question,
		})
	}
}