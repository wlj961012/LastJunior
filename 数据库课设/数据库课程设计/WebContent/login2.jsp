<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="com.bean.*" %>
<%@ page import="java.util.ArrayList" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>login</title>
</head>
<style type="text/css">
body {  
		background-image:url(login2.jpg);
        background-size:100% 100%;  /* 图片平铺拉伸，适应屏幕 */  
    }  

h1{  /* 标题居中  */  
        margin:100px auto;  
        text-align: center;
        color:#8DEEEE; 
        font-size:250%;
    }
h3{
	margin:80px auto;
	text-align:center;
	color:#8DEEEE;
}
a{
	color:white;
} 
#bg1{
   position:relative;
   top:25px;
   left:250px;
   height:200px;
   width:200px;
   background:rgba(255,231,186,0.2);   
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
   top:-190px;
   left:600px;
   height:200px;
   width:200px;
   background:rgba(255,231,186,0.2);
   border-bottom-style:solid;
   border-bottom-color:#FFFFFF;
   border-bottom-width:5px;
   border-top-style:solid;
   border-top-color:#FFFFFF;
   border-top-width:5px;
   border-radius:6px;
 }
 #bg3{
   position:relative;
   top:-400px;
   left:950px;
   height:200px;
   width:200px;
   background:rgba(255,231,186,0.2);
   border-bottom-style:solid;
   border-bottom-color:#FFFFFF;
   border-bottom-width:5px;
   border-top-style:solid;
   border-top-color:#FFFFFF;
   border-top-width:5px;
   border-radius:6px;
 }
 a:link {
    	color:#8DEEEE;
    	text-decoration: none;
    }      /* 未访问链接*/  
    a:visited {
    	color:#8DEEEE;
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
<h1>欢迎来到企业库存管理系统</h1>
	<div id=bg1><h3><a href="inoutstore.jsp">出入库管理</a></h3></div>
	<div id=bg2><h3><a href="searchproinfoServlet">产品基本信息管理</a></h3></div>
	<div id=bg3><h3><a href="tongjichaxun.jsp">统计查询</a></h3></div>
</body>
</html>