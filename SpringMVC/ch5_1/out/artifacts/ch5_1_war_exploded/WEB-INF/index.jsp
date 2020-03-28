<%@ page import="java.util.List" %><%--
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
            <a href="<%=request.getContextPath()%>/add" type="button" class="btn btn-success pull-right">添加</a>
            <table class="table table-hover">
                <thead>
                <tr>
                    <th class="text-center" style="width:10%">序号</th>
                    <th class="text-left" style="width:60%">内容</th>
                    <th class="text-center" style="width:30%">操作</th>
                </tr>
                </thead>
                <tbody>
                <%
                    List<String> todos = (List<String>)session.getAttribute("todos");
                    for (int index = 0; index < todos.size(); index++){
                        String todo = todos.get(index);
                %>
                <tr>
                    <td><%=index%></td>
                    <td><%=todo%></td>
                    <td class="text-center">
                        <a type="button" class="btn  btn-xs btn-success" href="<%=request.getContextPath()%>/update?index=<%=index%>">编辑</a>
                        <a type="button" class="btn  btn-xs btn-danger" href="<%=request.getContextPath()%>/del?index=<%=index%>">删除</a>
                    </td>
                </tr>
                <%
                    }
                %>
                </tbody>
            </table>
            <hr>
        </div>
    </div>
</div>
</body>
</html>
