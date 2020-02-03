package controllers

import (
	"../database"
)

var db = database.GetDB()

func Init() {
	db = database.GetDB()
}
