package models

import (
	"github.com/jinzhu/gorm"
	"../database"
)

var db *gorm.DB

func Init() {
	db = database.GetDB()
	db.CreateTable(&User{})
	db.AutoMigrate(&User{})
	db.CreateTable(&Answer{})
	db.AutoMigrate(&Answer{})
	db.CreateTable(&Question{})
	db.AutoMigrate(&Question{})
}
