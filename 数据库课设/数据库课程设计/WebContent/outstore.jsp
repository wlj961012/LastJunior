<%@ page language="java" contentType="text/html; charset=utf-8"  
    pageEncoding="utf-8"%>  
<%@page import="com.bean.Storeinfo"%>  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
<html>  
<head>  
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
<title>出库信息管理</title>  
<style type="text/css">  
body {  
    background-image:url(4.jpg);  
    background-size: cover;  
}  
h1{  
    	margin:50px auto;  
        text-align:center;
        color:white; 
}
h2{
	text-align:center;
}  
  
form{  
   top:0px; 
	left:-300px;
    width:800px;  
    margin: 0px auto;   
}  
  
.item{  
    color:white;  
    width:100px;  
    display:inline-block;   
    text-align:right;  
}
.item2{
    color:black;  
    width:140px;
    height:18px;  
    display:inline-block;   
    text-align:right;
}
 
.select1{
	width:150px;
}   
 #bg1{
   position:relative;
   top:0px;
   left:-250px;
   height:400px;
   width:500px;
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
#bg2{
   position:relative;
   top:-410px;
   left:250px;
   height:400px;
   width:500px;
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
 .btn1{  
    	width:80px;
   	 	background: rgba(255,255,255,0.2);
		display: inline-block;
		color:white;
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
		color:white;
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
  

</style>  
  
</head>  
<body>  
    <%  
    	String type="出";
    	String kno=request.getParameter("kno");
        String pno=request.getParameter("pno");
    	String sno=request.getParameter("sno");
    	String pdate=request.getParameter("pdate");
    %>  
    <h1>请填写出库信息</h1>  
    <form action="AddcrinfoServlet" method="post">
    <div id=bg1>
    <br><br>
    	<span class="item">存储编号:</span>
    	<span><input type="text" name="kno" value="<%=kno %>" readonly="readonly"></span><br><br> 
    	<span class="item">出入库类型:</span>
    	<span><input type="text" name="crtype" value="<%=type %>" readonly="readonly"></span><br><br> 
        <span class="item">产品编号:</span>       
        <span><input type="text" name="pno" value="<%=pno %>" readonly="readonly"/></span><br><br>  
        <span class="item">生产日期:</span> 
        <span><input type="text" name="pdate" value="<%=pdate%>" readonly="readonly" /></span><br><br>  
        <span class="item">仓库编号:</span>  
        <span><input type="text" name="sno" value="<%=sno %>" readonly="readonly" /></span><br><br>  
        <span class="item">出库产品单价:</span> 
        <span><input type="text" name="pcrprice"/></span><br><br>
        </div>
        <div id=bg2>
        <br><br> 
        <span class="item">出库产品数量:</span>      
        <span><input type="text" name="pcrnum"/></span><br><br>  
        <span class="item">客户编号:</span>  
        <span><input type="text" name="cno" /></span><br><br>
        <span class="item">经办人:</span>
        <span><input type="text" name="operator"></span><br><br>
        <span class="item">出入库日期:</span>
        <span><input class="item2" type="date" name="crdate" value="2018-01-01"></span><br><br>
        <span class="item">出入库标记:</span>
        <span>
        <select name="crtag" class="select1">
		<option value="销售出库">销售出库</option>
		<option value="退货出库">退货出库</option>
		<option value="用料出库">用料出库</option>
		</select></span><br><br>
        <span>  
            <input class="btn1" type="submit" value="提交" />  
            <input class="btn2" type="reset" value="重置" />  
        </span> 
        </div> 
    </form>  
  
  
</body>  
</html>