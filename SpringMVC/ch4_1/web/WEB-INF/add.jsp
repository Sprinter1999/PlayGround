<%--
  Created by IntelliJ IDEA.
  User: wzl
  Date: 2019/10/24
  Time: 21:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <head>
        <title>ToDoList</title>
        <link href="http://apps.bdimg.com/libs/bootstrap/3.3.0/css/bootstrap.min.css" rel="stylesheet">
        <script src="http://apps.bdimg.com/libs/jquery/2.0.0/jquery.min.js"></script>
        <script src="http://apps.bdimg.com/libs/bootstrap/3.3.0/js/bootstrap.min.js"></script>
    </head>
<body>
<div class="wrapper">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <h1>新建联系人</h1>
            <hr>
            <form action="<%=request.getContextPath()%>/add" method="POST">
                <label>请输入联系人信息：</label><hr>
                <input type="text" name="username"  placeholder="username" value=""><hr>
                <input type="text" name="telephone"  placeholder="telephone" value=""><hr>
                <input type="text" name="emailAddress"  placeholder="emailAddress" value=""><hr>
                <button type="submit" class="btn btn-success">添加</button>
                <button type="reset" class="btn btn-success" onclick="location.href='/'">取消</button>
            </form>
        </div>
    </div>
</div>
</body>
</html>
