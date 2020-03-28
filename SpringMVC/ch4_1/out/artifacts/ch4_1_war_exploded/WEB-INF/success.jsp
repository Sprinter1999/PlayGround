<%--
  Created by IntelliJ IDEA.
  User: wzl
  Date: 2019/10/24
  Time: 22:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Success</title>
    <link href="http://apps.bdimg.com/libs/bootstrap/3.3.0/css/bootstrap.min.css" rel="stylesheet">
    <script src="http://apps.bdimg.com/libs/jquery/2.0.0/jquery.min.js"></script>
    <script src="http://apps.bdimg.com/libs/bootstrap/3.3.0/js/bootstrap.min.js"></script>
</head>
<body>
<div class="wrapper">
    <div class="row">
        <div class="col-md-8 col-md-offset-2">
            <h1>操作成功！</h1>
            <hr>
                <form action="<%=request.getContextPath()%>/success" method="post">
                    <button type="submit" class="btn btn-success" onclick="location.href='/'">返回</button>
                </form>

        </div>
    </div>
</div>
</body>
</html>
