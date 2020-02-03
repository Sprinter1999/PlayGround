package database

import (
	"fmt"
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
	_ "os"
)

var db *gorm.DB
var err error

func GetDB() *gorm.DB {
	return db
}

func CloseDB() {
	db.Close()
}

func Init() {
	//这里需要设置为你本机的数据库信息
	db, err = gorm.Open("mysql", "root:qq131313@tcp(127.0.0.1:3306)/RUNOOB?" +
		"charset=utf8&parseTime=True&loc=Local&timeout=10ms")
	if err != nil{
		fmt.Printf("mysql connet error %v", err)
	}
	if db.Error != nil{
		fmt.Printf("database error %v", db.Error)
	}

}
