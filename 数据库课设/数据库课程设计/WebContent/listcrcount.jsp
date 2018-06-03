    <%@ page language="java" contentType="text/html; charset=utf-8"  
        pageEncoding="utf-8"%>   
    <%@page import="java.util.ArrayList" %> 
    <%@page import="com.bean.Crtongji" %>  
    <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
    <html>  
    <head>  
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
    <title>出入库统计</title>  
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
    }     
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
    <div> 
        <h1>出库统计信息</h1> 
        <table style="border: 1px">  
            <tr>  
                <th>产品编号</th>  
                <th>产品名称</th>  
                <th>出库次数</th>  
            </tr>  
            <%  ArrayList<Crtongji> cc =(ArrayList<Crtongji>)request.getAttribute("result1");   
                for(Crtongji c : cc){  
            %>  
            <tr>  
                <td><%=c.getPno()%></td>  
                <td><%=c.getPname()%></td>  
                <td><%=c.getCount() %></td>  
            </tr>  
            <%   
                }  
            %>  
        </table>
        </div>  
        
        <div> 
        <h1>入库统计信息</h1> 
        <table style="border: 1px">  
            <tr>  
                <th>产品编号</th>  
                <th>产品名称</th>  
                <th>入库次数</th>  
            </tr>  
            <%  ArrayList<Crtongji> rr =(ArrayList<Crtongji>)request.getAttribute("result2");   
                for(Crtongji r : rr){  
            %>  
            <tr>  
                <td><%=r.getPno()%></td>  
                <td><%=r.getPname()%></td>  
                <td><%=r.getCount() %></td>  
            </tr>  
            <%   
                }  
            %>  
        </table>
        </div>  
        
    </body>  
    </html>  