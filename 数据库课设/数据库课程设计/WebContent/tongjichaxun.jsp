<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="com.bean.*" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>统计查询</title>
</head>
<style type="text/css">
body {  
        background-image:url(9.jpg);  
        background-size: cover;  /* 图片平铺拉伸，适应屏幕 */  
    } 
    h3{
	margin:80px auto;
	text-align:center;
	color:white;
}
a{
	color:white;
}
#bg1{
   	position:relative;
   	top:25px;
   	left:300px;
   	height:200px;
   	width:200px;
   	background:rgba(255,255,255,0.2); 
   	background-size:cover;  
   	border-bottom-style:solid;
   	border-bottom-color:#FFFACD;
   	border-bottom-width:5px;
   	border-top-style:solid;
   	border-top-color:#FFFACD;
   	border-top-width:5px;
}
  #bg2{
 position:relative;
   top:-180px;
   left:800px;
   height:200px;
   width:200px;
   background:rgba(255,255,255,0.2);
   background-size:cover;
   border-bottom-style:solid;
   border-bottom-color:#FFFACD;
   border-bottom-width:5px;
   border-top-style:solid;
   border-top-color:#FFFACD;
   border-top-width:5px;
 }    
    a:link {color:#FFFACD;
    text-decoration: none;
    }      /* 未访问链接*/  
    a:visited {color:#FFFACD;
    text-decoration: none;}   
    a:hover {color:#FF6A6A;
    text-decoration: none;}  /* 鼠标移动到链接上 */  
    a:active {color:#FF6A6A;
    text-decoration: none;}  /* 已点击 */  
      
#toAdd{ text-align: center;}  
</style>
<body>
<br><br><br><br><br><br>
<div id="bg1"><h3><a href="CrcountServlet">出入库统计报表</a></h3></div>
<div id="bg2"><h3><a href="KucuntongjiServlet">库存流水统计报表</a></h3></div>
</body>
</html>