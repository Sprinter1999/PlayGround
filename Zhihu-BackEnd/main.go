package main

import (
	"./controllers"
	"./database"
	"net/http"
	"./models"
	"github.com/gin-gonic/gin"
)

func main() {
	database.Init()
	models.Init()
	controllers.Init()
	r := gin.Default()
	//r.Use(CorsMiddleware())
	r.StaticFS("/static", http.Dir("C:/Users/11790/Desktop/gotry/zhihu/static"))
	r.NoRoute()
	mountRoutes(r)
	r.Run() // listen and serve on 0.0.0.0:8080
}

func mountRoutes(r *gin.Engine) {
	//POST
	r.POST("/api/upload", controllers.UploadFile)
	//r.OPTIONS("/api/upload", controllers.UploadFile)
	r.POST("/api/register", controllers.CreateUser)
	r.POST("/api/login", controllers.LoginUser)
	r.POST("/api/question", controllers.CreateQuestion)
	r.POST("/api/findquestion", controllers.FindQuestions)
	r.POST("/api/answer",controllers.CreateAnswer)
	r.POST("/api/user",controllers.ListUsers)
	//GET
	r.GET("/api/answer", controllers.ListAnswers)
	r.GET("/api/question", controllers.ListQuestions)
	//DELETE
	r.DELETE("/api/user", controllers.DeleteUser) //删除用户
}

//
//func CorsMiddleware() gin.HandlerFunc {
//	return func(c *gin.Context) {
//		method := c.Request.Method
//		// 核心处理方式
//		c.Header("Access-Control-Allow-Origin", "*")
//		c.Header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept")
//		c.Header("Access-Control-Allow-Methods", "GET, OPTIONS, POST, PUT, DELETE")
//		//c.Header("Content-Type", "multipart/form-data")
//		//放行所有OPTIONS方法
//		if method == "OPTIONS" {
//			c.JSON(http.StatusOK, "Options Request!")
//		}
//		c.Next()
//	}
//}