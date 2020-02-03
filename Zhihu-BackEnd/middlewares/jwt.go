package middlewares

import (
	"fmt"
	"os"
	"time"

	"github.com/appleboy/gin-jwt"
	"github.com/gin-gonic/gin"
	"../models"
)

var authMiddleware = &jwt.GinJWTMiddleware{
	Realm:      "test zone",
	Key:        []byte(os.Getenv("SECRET_KEY")),
	Timeout:    1<<63 - 1,
	MaxRefresh: time.Hour,
	PayloadFunc: func(data interface{}) jwt.MapClaims {
		if v, ok := data.(*models.WxUser); ok {
			return jwt.MapClaims{
				"id": v.ID,
			}
		}
		return jwt.MapClaims{}
	},
	Authenticator: func(c *gin.Context) (interface{}, error) {
		return nil, nil
	},
	Authorizator: func(data interface{}, c *gin.Context) bool {
		fmt.Println(data)
		return true
	},
	Unauthorized: func(c *gin.Context, code int, message string) {
		c.JSON(code, gin.H{
			"code":    code,
			"message": message,
		})
	},

	TokenLookup: "header: Authorization",

	TokenHeadName: "Bearer",

	TimeFunc: time.Now,
}

func JWTMiddleware() *jwt.GinJWTMiddleware {
	return authMiddleware
}
