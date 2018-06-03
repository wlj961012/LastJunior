    <%@ page language="java" contentType="text/html; charset=utf-8"  
        pageEncoding="utf-8"%>   
    <%@page import="java.util.ArrayList" %> 
    <%@page import="com.bean.Kucuntongji" %>  
    <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
    <html>  
    <head>  
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
    <title>库存流水统计报表</title>  
    <style>  
   body {  
    	background-image:url(9.jpg);
        background-size: cover;  /* 图片平铺拉伸，适应屏幕 */
       /* background-color:white; */ 
    }  
    h1{  
        margin:50px auto;  
        text-align: center;
        color:white; 
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
    	}   
    a:active {
    	color:#f60;
    	text-decoration: none;
    }    
      
    </style>  
      
    </head>  
    <body>
        <h1>库存流水统计报表</h1> 
        <table style="border: 1px">  
            <tr>  
                <th>出入库日期</th>  
                <th>产品编号</th>  
                <th>产品名称</th>  
            </tr>  
            <%  ArrayList<Kucuntongji> rr =(ArrayList<Kucuntongji>)request.getAttribute("result");   
                for(Kucuntongji r : rr){  
            %>  
            <tr> 
            	<td><%=r.getCrdate() %></td> 
                <td><%=r.getPno()%></td>  
                <td><%=r.getPname()%></td>  
            </tr>  
            <%   
                }  
            %>  
        </table>  
        
    </body>  
    </html>  