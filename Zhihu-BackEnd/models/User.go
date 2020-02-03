package models

import (
	"github.com/jinzhu/gorm"
)

type User struct {
	gorm.Model
	Account	string `gorm:"primary_key"` //用户账号
	Password string						//用户密码
	Nickname string						//用户名字
	Superuser string 					//用户权限，1表示是超极用户
}
