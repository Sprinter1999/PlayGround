package controllers

import (
	"../models"
	_ "encoding/json"
	"fmt"
	_ "fmt"
	"github.com/gin-gonic/gin"
	"github.com/jinzhu/gorm"
)

// 创建用户
func CreateUser(c *gin.Context) {
	var user models.User
	c.BindJSON(&user)
	user.Superuser = "0"
	db.Save(&user)
	c.JSON(200, gin.H{
		"code" : 0,
		"message": "创建成功",
	})
}

// 将用户列表
func ListUsers(c *gin.Context) {
	//gin的绑定必须是绑定结构体
	type userinfo struct{
		Token string 	
	}
	var info userinfo
	c.BindJSON(&info)
	//解析用户token
	parse, _ := ParseToken(info.Token)
	var user models.User
	if err := db.First(&user, "account = ?", parse.Username).Error; err != nil {
		c.JSON(200,gin.H{
			"code" : 1,
			"message" : "还未登陆",
		})
	} else if (user.Superuser == "0") {
		c.JSON(200, gin.H{
			"code" : 1,
			"message" : "您没有展示用户的权限",
		})
	} else {
		var users []models.User
		if err := db.Find(&users).Error; err != nil {
			c.JSON(200, gin.H{
				"code" : 1,
				"message" : "用户列表不存在",
			})
		} else {
			c.JSON(200, gin.H{
				"code" : 0,
				"message" : "用户列表",
				"user" : users,
			})
		}
	}
}

// 删除用户
func DeleteUser(c *gin.Context){
	type userinfo struct{
		gorm.Model
		Token string
		Account string
	}
	var info userinfo
	c.BindJSON(&info)
	parse, _ := ParseToken(info.Token)
	var user models.User
	if err := db.First(&user, "account = ?", parse.Username).Error; err != nil{
		c.JSON(200,gin.H{
			"code" : 1,
			"message" : "登陆状态已过期，请重新登录",
		})
	} else if (user.Superuser == "0") {
		c.JSON(200, gin.H{
			"code" : 1,
			"message" : "您没有删除用户的权限",
		})
	} else {
		var victim models.User
		if err1 := db.First(&victim, "account = ?", info.Account).Error; err1 != nil{
			c.JSON(200, gin.H{
				"code" : 1,
				"message" : "该用户不存在",
			})
		} else {
			if(victim.Superuser == "1"){
				c.JSON(200, gin.H{
					"code" : 1,
					"message" : "您不可以删除管理员!",
				})
			} else {
				db.Delete(&victim)
				c.JSON(200, gin.H{
					"code" : 0,
					"message" : "删除成功",
				})
			}
		}
	}
}

// 登陆用户
func LoginUser(c *gin.Context) {
	var user models.User
	//Postman的JSON每行之间必须有逗号，最后一行不能有逗号！
	c.BindJSON(&user)
	fmt.Println(user.Account)
	fmt.Println(user.Password)
	token, _ := GenerateToken(user.Account, user.Password)
	if err := db.First(&user, "account = ? AND password = ?",  user.Account, user.Password).Error; err != nil{
		fmt.Println(err)
		c.JSON(200, gin.H{
			"code" : 1,
			"message" : "账号或密码错误",
		})
	} else {
		c.JSON(200, gin.H{
			"code" : 0,
			"token" : token,
			"message" : "登陆成功",
		})
	}
}