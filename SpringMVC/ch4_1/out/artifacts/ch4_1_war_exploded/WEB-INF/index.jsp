<%@ page import="java.util.List" %>
<%@ page import="java.net.http.HttpResponse" %><%--
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
        <title>通讯录</title>
        <link href="http://apps.bdimg.com/libs/bootstrap/3.3.0/css/bootstrap.min.css" rel="stylesheet">
        <script src="http://apps.bdimg.com/libs/jquery/2.0.0/jquery.min.js"></script>
        <script src="http://apps.bdimg.com/libs/bootstrap/3.3.0/js/bootstrap.min.js"></script>
    </head>
<body>
<div class="wrapper">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <h1>通讯录</h1>
            <hr>
            <a href="<%=request.getContextPath()%>/login" type="button" class="btn btn-success pull-left">登录</a>
            <a href="<%=request.getContextPath()%>/add" type="button" class="btn btn-success pull-right">添加</a>
            <a type="button" class="btn btn-success pull-middle" href="<%=request.getContextPath()%>/login" > 注销 </a>
            <table class="table table-hover">
                <thead>
                <tr>
                    <th class="text-center" style="width:10%">序号</th>
                    <th class="text-left" style="width:60%">联系人</th>
                    <th class="text-center" style="width:30%">操作</th>
                </tr>
                </thead>
                <tbody>
                <%
                    List<String> userinfos = (List<String>)session.getAttribute("userinfos");
                    if(userinfos!=null)
                    {
                        for(int index = 0; index < userinfos.size(); index++)
                        {
                            String userinfo = userinfos.get(index);
                %>
<%--                <a><%=session.getAttribute("userinfos")%></a>--%>
                <tr>
                    <td><%=index%></td>
                    <td><%=userinfo%></td>
                    <td class="text-center">
                        <a type="button" class="btn  btn-xs btn-success" href="<%=request.getContextPath()%>/update?index=<%=index%>">编辑</a>
                        <a type="button" class="btn  btn-xs btn-danger" href="<%=request.getContextPath()%>/del?index=<%=index%>">删除</a>
                    </td>
                </tr>
                <%
                        }
                    }
                %>
                </tbody>
            </table>
            <hr>
        </div>
    </div>
</div>
</body>
<div class="wrapper">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
        <a type="button" class="btn btn-success pull-right">当前用户为<%=session.getAttribute("login")%></a>
        </div>
    </div>
</div>
</html>
