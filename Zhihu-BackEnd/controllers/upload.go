package controllers

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"io"
	_ "io/ioutil"
	"log"
	"net/http"
	"os"
)
func UploadFile(c *gin.Context) {
	// FormFile方法会读取参数“upload”后面的文件名，返回值是一个File指针，和一个FileHeader指针，和一个err错误。
	file, header, err := c.Request.FormFile("upload")
	if err != nil {
		fmt.Println(1)
		fmt.Println(err)
		fmt.Println(header.Filename)
		c.String(http.StatusBadRequest, "Bad request")
		return
	}
	// header调用Filename方法，就可以得到文件名
	filename := header.Filename
	fmt.Println(filename)
	// 创建一个文件，文件名为filename，这里的返回值out也是一个File指针
	out, err := os.Create("C:/Users/11790/Desktop/gotry/zhihu/static/" + filename)
	if err != nil {
		log.Fatal(err)
	}
	defer out.Close()
	// 将file的内容拷贝到out
	_, err = io.Copy(out, file)
	if err != nil {
		log.Fatal(err)
	}
	c.String(http.StatusCreated, "上传成功\n")
}