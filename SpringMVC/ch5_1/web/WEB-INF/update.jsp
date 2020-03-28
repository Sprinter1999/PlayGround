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
            <h1>ToDoList</h1>
            <hr>
            <form action="<%=request.getContextPath()%>/update" method="POST">
                <label>请输入备忘事项：</label>
                <input type="hidden" name="index" value="<%=request.getAttribute("index")%>">
                <input type="text" name="todo"  id="todo"  value="<%=request.getAttribute("todo")%>"><hr>                
                <button type="submit" class="btn btn-success">确定</button>
                <button type="reset" class="btn btn-success" onclick="location.href='/'">取消</button>
            </form>
        </div>
    </div>
</div>
</body>
</html>
