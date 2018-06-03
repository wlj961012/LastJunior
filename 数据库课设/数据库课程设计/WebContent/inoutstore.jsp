<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="com.bean.*" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>出入库选择</title>
</head>
<style type="text/css">
body {  
        background-image:url(1.jpg); 
        background-size:100% 800px;  /* 图片平铺拉伸，适应屏幕 */  
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
   	background:rgba(255,255,255,0.4); 
   	background-size:cover;  
   	border-bottom-style:solid;
   	border-bottom-color:#FFFFFF;
   	border-bottom-width:5px;
   	border-top-style:solid;
   	border-top-color:#FFFFFF;
   	border-top-width:5px;
   	border-radius:6px;
}
  #bg2{
 position:relative;
   top:-180px;
   left:800px;
   height:200px;
   width:200px;
   background:rgba(255,255,255,0.4);
   background-size:cover;
   border-bottom-style:solid;
   border-bottom-color:#FFFFFF;
   border-bottom-width:5px;
   border-top-style:solid;
   border-top-color:#FFFFFF;
   border-top-width:5px;
   border-radius:6px;
 }
 a:link {
    	color:#6495ED;
    	text-decoration: none;
    }      /* 未访问链接*/  
    a:visited {
    	color:#6495ED;
    	text-decoration: none;
    	}   
    a:hover {
    	color:#FFE7BA;
    	text-decoration: none;
    	}   
    a:active {
    	color:#FFE7BA;
    	text-decoration: none;
    }       
</style>
<body>
<br><br><br><br><br><br>
<div id="bg1"><h3><a href="searchstoreinfoServlet">出库管理</a></h3></div>
<div id="bg2"><h3><a href="instore.jsp">入库管理</a></h3></div>
</body>
</html>