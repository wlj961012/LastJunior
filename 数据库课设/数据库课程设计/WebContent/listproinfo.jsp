    <%@ page language="java" contentType="text/html; charset=utf-8"  
        pageEncoding="utf-8"%>   
    <%@page import="java.util.ArrayList" %> 
    <%@page import="com.bean.productinfo" %>  
    <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
    <html>  
    <head>  
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
    <title>产品信息</title>  
    <style>  
   body {  
    	background-image:url(5.jpg);
        background-size: cover;  /* 图片平铺拉伸，适应屏幕 */
       /* background-color:white; */ 
    }  
    h1{  
        margin:50px auto;  
        text-align: center;
        color:white; 
    }
    #bg1{
       position:relative;
       top:-10px;
       left:-10px;
       height:40px;
       width:1400px;
       background:rgba(255,255,255,0.2);
     } 
      
    table {  
      
         border-collapse: collapse;  
      
         font-family: Futura, Arial, sans-serif;  
      
      	 text-align: center;  
      	 
      	 width:800px; 
      	  
       	 margin:50px auto;
    }  
      
    caption {  
      
         font-size: larger;  
      
         margin: 1em auto;  
      
    } 
    th{
    	padding: .65em;
    	color:white;
    	border-bottom: 1px solid #ddd;  
        border-top: 1px solid #ddd;  
        text-align: center;
    } 
      
    td {  
    
    	color:white;
      
         padding: .65em;  
      
         border-bottom: 1px solid #ddd;  
      
         border-top: 1px solid #ddd;  
      
         text-align: center;  
      
    }   
      
    a:link {
    	color:white;
    	text-decoration: none;
    }      /* 未访问链接*/  
    a:visited {
    	color:white;
    	text-decoration: none;
    	}   
    a:hover {
    	color:#f00;
    	text-decoration: none;
    	}  /* 鼠标移动到链接上 */  
    a:active {
    	color:#f60;
    	text-decoration: none;
    }   
     #toAdd{
		background: rgba(255,255,255,0);
		display: inline-block;
		padding: 5px 10px 6px;
		color:black;
		text-decoration: none;
		cursor: pointer;
		position:relative;
  		top:5px;
   		left:2%;
   		height:20px;
   		width:80px;
   		text-align:bottom;
   		font-size:100%
	}  
  
      
    </style>  
      
    </head>  
    <body>  
    <div id="bg1">
    <span id="toAdd"><a href="addproinfo.jsp">增加产品</a></span>
    <span id="toAdd"><a href="login2.jsp">返回首页</a></span>
    </div> 
    
        <h1>产品基本信息表</h1> 
        <table style="border: 1px">  
            <tr>  
                <th>产品编号</th>  
                <th>产品名称</th>  
                <th>产品规格</th>  
                <th>参考价格</th>  
                <th>数量上限</th>
                <th>数量下限</th>
                <th>操作</th>    
            </tr>  
            <%  ArrayList<productinfo> pp =(ArrayList<productinfo>)request.getAttribute("result");   
                for(productinfo p : pp){  
            %>  
            <tr>  
                <td><%=p.getPno()%></td>  
                <td><%=p.getPname()%></td>  
                <td><%=p.getPsize() %></td>  
                <td><%=p.getPprize() %></td>  
                <td><%=p.getUppernum() %></td> 
                <td><%=p.getDownnum() %> </td>
                <td colspan="3">  
                <a href="updateproinfo.jsp?pno=<%=p.getPno()%>&pname=<%=p.getPname()%>&psize=<%=p.getPsize()%>&pprize=<%=p.getPprize()%>&pupnum=<%=p.getUppernum()%>&pdownnum=<%=p.getDownnum()%>">修改</a>  
                    
                <a href="DeleteproinfoServlet?pno=<%=p.getPno()%>" onclick="return confirm('确定删除？')">删除</a>  
            </td>  
            </tr>  
            <%   
                }  
            %>  
        </table>  
    </body>  
    </html>  