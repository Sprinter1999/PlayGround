package controllers

import (
	"../models"
	"fmt"
	_ "fmt"
	"github.com/gin-gonic/gin"
	"github.com/jinzhu/gorm"
	_ "net/http"

)

//发表回答
func CreateAnswer(c *gin.Context){
	type answerinfo struct{
		gorm.Model
		Token string
		Content string
		QuestionID string
	}
	var ans answerinfo
	c.BindJSON(&ans)
	parse, _ := ParseToken(ans.Token)
	var user models.User
	//更新问题的热度
	var question models.Question
	db.First(&question, "question_id = ?", ans.QuestionID);
	db.Model(&question).Update("AnswerNum", question.AnswerNum + 1)
	if err := db.First(&user, "account = ?", parse.Username).Error; err != nil{
		c.JSON(200, gin.H{
			"code" : 1,
			"message" : "不存在该用户",
		})
	} else {
		var answer models.Answer
		answer.QuestionID = ans.QuestionID
		answer.Content = ans.Content
		answer.Nickname = user.Nickname
		db.Save(&answer)
		c.JSON(200, gin.H{
			"code":  0,
			"message": "发表成功",
		})
	}
}

//列出某个问题下的回答
func ListAnswers(c *gin.Context){
	var answers []models.Answer
	var question models.Question
	fmt.Println(c.Query("questionid"))
	if err:=db.Table("answers").Find(&answers, "question_id = ?", c.Query("questionid")).Error; err !=nil{
		c.JSON(200, gin.H{
			"code" : 1,
			"message" : "不存在该问题ID",
		})
	} else {
		db.Find(&question, "question_id = ?", c.Query("questionid"))
		c.JSON(200, gin.H{
			"code" : 0,
			"message" : "回答列表",
			"answer" : answers,
			"question" : question,
		})
	}
}