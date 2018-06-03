<%@ page language="java" contentType="text/html; charset=utf-8"  
    pageEncoding="utf-8"%>  
<%@page import="com.bean.productinfo"%>  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
<html>  
<head>  
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
<title>修改产品信息</title>  
<style type="text/css">  
body {  
    background-image:url(5.jpg);  
    background-size: cover;  
}  
h1{  
        margin:50px auto;  
        text-align: center;
        color:white;
        font-style:italic; 
}
h2{
	font: 400 130px/0.8 'Cookie', Helvetica, sans-serif;
    color: #fff;
    text-shadow: 4px 4px 3px rgba(0,0,0,0.1);
    text-align:center;
}  
  
form{ 
	top:0px; 
	left:-300px;
    width:800px;  
    margin: 0px auto;  
}  
#bg1{
   position:relative;
   top:0px;
   left:0px;
   height:400px;
   width:600px;
   background:rgba(255,255,255,0.2);   
   border-bottom-style:solid;
   border-bottom-color:#FFFFFF;
   border-bottom-width:5px;
   border-top-style:solid;
   border-top-color:#FFFFFF;
   border-top-width:5px;
   text-align:center;
   margin:auto;
}
.item{  
    color:#4682B4;  
    width:100px;  
    display:inline-block;   
    text-align:right;  
}  
  
.btn1{  
    	width:80px;
   	 	background: rgba(255,255,255,0.2);
		display: inline-block;
		color:#4682B4;
		text-decoration: none;
		-moz-border-radius: 6px;
		-webkit-border-radius: 6px;
		text-shadow: 0 -1px 1px rgba(255,255,255,0.25);
		border: 1px solid rgba(0,255,0,0.5);
		cursor: pointer;
		position:relative;
  		top:0px;
   		left:2%;
   		height:30px;
   		text-align:center;
   		font-size:110%;
   		font:15px Calibri, Arial, sans-serif;  
} 
.btn2{
        width:80px;
   	 	background: rgba(255,255,255,0.2);
		display: inline-block;
		color:#4682B4;
		text-decoration: none;
		-moz-border-radius: 6px;
		-webkit-border-radius: 6px;
		text-shadow: 0 -1px 1px rgba(250,128,114,0.25);
		border: 1px solid rgba(255,0,0,0.5);
		cursor: pointer;
		position:relative;
  		top:0px;
   		left:8%;
   		height:30px;
   		text-align:center;
   		font-size:110% ;
   		font:15px Calibri, Arial, sans-serif;
			
}
#toadd{
	border:1px solid rgba(255,250,205,1);
	background: rgba(255,255,255,0.2);
} 
</style>  
  
</head>  
<body>  
    <%  
        String pno = request.getParameter("pno");  
        String pname = request.getParameter("pname"); 
        pname=new String(pname.getBytes("ISO-8859-1"), "utf-8");
        String psize = request.getParameter("psize");  
        int pprize=Integer.valueOf(request.getParameter("pprize"));
        int pupnum=Integer.valueOf(request.getParameter("pupnum"));
        int pdownnum=Integer.valueOf(request.getParameter("pdownnum"));
    %>  
    <h1>请修改产品基本信息</h1>  
    <form action="UpdateproinfoServlet" method="post"> 
    <div id=bg1>
    <br><br>
        <span class="item">产品编号:</span>       <span><input type="text" id="toadd" name="pno" value="<%=pno %>" readonly="readonly"/></span><br><br>  
        <span class="item">产品名称:</span> <span><input type="text" id="toadd" name="pname" value="<%=pname%>" /></span><br><br>  
        <span class="item">产品规格:</span> <span><input type="text" id="toadd" name="psize" value="<%=psize %>" /></span><br><br>  
        <span class="item">参考价格:</span>      <span><input type="text" id="toadd" name="pprize" value="<%=pprize %>" /></span><br><br>  
        <span class="item">数量上限:</span>  <span><input type="text" id="toadd" name="pupnum" value="<%=pupnum %>" /></span><br><br>
        <span class="item">数量下限:</span>  <span><input type="text" id="toadd" name="pdownnum" value="<%=pdownnum %>" /></span><br><br>  
        <br><br>  
        <center>  
            <input class="btn1" type="submit" value="提交" />  
            <input class="btn2" type="reset" value="重置" />  
        </center> 
        </div> 
    </form>  
  
  
</body>  
</html>