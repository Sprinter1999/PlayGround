<%@ page import="beans.Staff" %>
<%@ page import="java.io.*,java.util.*" %>
<%@ page import="javax.servlet.*,java.text.*" %>
<%--
  Created by IntelliJ IDEA.
  User: beauw
  Date: 2018/1/6
  Time: 9:37
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>管理员后台管理</title>
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/master.css">
    <style type="text/css">
        ul.nav li:nth-child(1) a{
            background-color: #a89b9b;
            color: #f8f8f8;
        }
    </style>
</head>
<body>
<!-- 顶部状态栏 -->
<div class="navbar navbar-default">
    <div class="container-fluid">
        <div class="navbar-header">
            <a href="" class="navbar-brand">药品后台管理</a>
        </div>

        <p class="navbar-text">当前登录用户</p>
        <p class="navbar-text">
        <%
            Staff staff = (Staff) session.getAttribute("staff");
            out.println(staff.getName());
        %>
        </p>
        <p class="navbar-text navbar-right"></p>
        <a href="managermaster?id=11" type="button" class="btn btn-default navbar-btn navbar-right">退出</a>
    </div>
</div>
<!-- 左侧导航 -->
<div class="navbox">
    <ul class="nav">
        <li><a href="managermaster?id=1">管理主页</a></li>
        <li><a href="managermaster?id=2">员工管理</a></li>
        <li><a href="managermaster?id=3">查看库存</a></li>
        <li><a href="managermaster?id=4">查看进货</a></li>
        <li><a href="managermaster?id=5">查看售货</a></li>
        <li><a href="managermaster?id=6">查看退厂</a></li>
        <li><a href="managermaster?id=7">查看客户</a></li>
        <li><a href="managermaster?id=8">查看厂商</a></li>
    </ul>
</div>
<!-- 右侧数据显示区 -->
<div class="mainArea">
    <div class="showArea">
        <div class="jumbotron myjumbotron">
            <h1>欢迎登录</h1>
            <h2>
                <%
                    out.println(staff.getName());
                %>
            </h2>

            <p>现在是</p>
            <p>
                <%
                    Date dNow = new Date( );
                    SimpleDateFormat ft =
                            new SimpleDateFormat ("yyyy-MM-dd HH:mm:ss");
                    out.print(ft.format(dNow));
                %>
            </p>
            <p>欢迎使用药品后台管理系统</p>
        </div>
    </div>
</div>

<script src="bootstrap/js/jquery.min.js" charset="utf-8"></script>
<script src="bootstrap/js/bootstrap.min.js" charset="utf-8"></script>

</body>
</html>