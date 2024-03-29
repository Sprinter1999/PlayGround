<%@ page import="beans.Staff" %>
<%@ page import="beans.Customer" %>
<%@ page import="java.util.List" %><%--
  Created by IntelliJ IDEA.
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>修改客户信息</title>
    <link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="css/master.css">
    <style type="text/css">
        ul.nav li:nth-child(6) a{
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
        <form class="form-inline text-center" action="searchCustomerJump">
            <div class="form-group">
                <label for="exampleInputName2">输入查询</label>
                <input type="text" class="form-control" id="exampleInputName2" name="search" placeholder="在这里输入">
            </div>
            <label class="radio-inline">
                <input type="radio" name="inlineRadioOptions" id="inlineRadio1" value="option1" checked> 根据姓名
            </label>
            <label class="radio-inline">
                <input type="radio" name="inlineRadioOptions" id="inlineRadio2" value="option2"> 根据ID
            </label>
            <button type="submit" class="btn btn-primary">搜索</button>
        </form>
        <table class="table table-bordered table table-striped">
            <tr>
                <th>CLIENTID</th>
                <th>NAME</th>
                <th>PHONE</th>
                <th>修改</th>
                <th>删除</th>
            </tr>
            <%
                List<Customer> customers=(List<Customer>) request.getAttribute("Customers");
                for (Customer customer : customers) {
            %>
            <tr>
                <td><%=customer.getCustomerID()%></td>
                <td><%=customer.getCustomerName()%></td>
                <td><%=customer.getCustomerPhone()%></td>
                <td><a type="button" class="btn btn-warning btn-xs btn-block" href="updateCustom?uid=<%=customer.getCustomerID()%>">修改</a></td>
                <td><a type="button" class="btn btn-danger btn-xs btn-block" href="deleteByCusId?pid=<%=customer.getCustomerID()%>">删除</a></td>
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

