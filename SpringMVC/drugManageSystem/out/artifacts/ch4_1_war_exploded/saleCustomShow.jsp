<%--
  Created by IntelliJ IDEA.
  User: DL
  Date: 2018/1/9
  Time: 15:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="beans.Staff" %>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="beans.Customer" %>
<%@ page import="java.util.List" %>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>售货员后台管理</title>
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/master.css">
    <style type="text/css">
        ul.nav li:nth-child(3) a{
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
        <p class="navbar-text"><%
            Staff staff = (Staff) session.getAttribute("staff");
            out.println(staff.getName());
        %></p>

        <p class="navbar-text navbar-right"></p>
        <a href="managermaster?id=11" type="button" class="btn btn-default navbar-btn navbar-right">退出</a>    </div>
</div>
<!-- 左侧导航 -->
<div class="navbox">
    <ul class="nav">
        <li><a href="managesale?id=0">销售主页</a></li>
        <li><a href="managesale?id=1">修改资料</a></li>
        <li><a href="managesale?id=2">售货</a></li>
        <li><a href="managesale?id=3">查看客户</a></li>
        <li><a href="managesale?id=4">添加客户</a></li>
        <li><a href="managesale?id=5">修改客户</a></li>
    </ul>
</div>
<!-- 右侧数据显示区 -->
<div class="mainArea">
    <div class="showArea">
        <h3 class="text-center">请选择客户ID</h3>
        <table class="table table-bordered table table-striped">
            <tr>
                <th>CLIENTID</th>
                <th>名字</th>
                <th>PHONE</th>
            </tr>
            <%
                List<Customer> customers=(List<Customer>) request.getAttribute("Customers");
                for (Customer customer : customers) {
            %>
            <tr>
                <td><a class="btn btn-default btn-xs btn-block" href="customSelect?uid=<%=customer.getCustomerID()%>"><%=customer.getCustomerID()%></a></td>
                <td><%=customer.getCustomerName()%></td>
                <td><%=customer.getCustomerPhone()%></td>
            </tr>
            <%
                }
            %>
        </table>
    </div>
</div>






<script src="bootstrap/js/jquery.min.js" charset="utf-8"></script>
<script src="bootstrap/js/bootstrap.min.js" charset="utf-8"></script>
</body>
</html>
