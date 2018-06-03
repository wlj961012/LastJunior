    <%@ page language="java" contentType="text/html; charset=utf-8"  
        pageEncoding="utf-8"%>   
    <%@page import="java.util.ArrayList" %> 
    <%@page import="com.bean.Inoutstoreinfo" %>  
    <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">  
    <html>  
    <head>  
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">  
    <title>出入库基本信息表</title>  
    <style>  
     body {  
    	background-image:url(4.jpg);
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
    	}  /* 鼠标移动到链接上 */  
    a:active {
    	color:#f60;
    	text-decoration: none;
    }   
    #toAdd{
		background: rgba(255,255,255,0.5);
		display: inline-block;
		padding: 5px 10px 6px;
		color:white;
		text-decoration: none;
		-moz-border-radius: 6px;
		-webkit-border-radius: 6px;
		-moz-box-shadow: 0 1px 3px rgba(255,255,255,0.6);
		-webkit-box-shadow: 0 1px 3px rgba(255,255,255,0.6);
		text-shadow: 0 -1px 1px rgba(255,255,255,0.25);
		border-bottom: 1px solid rgba(255,255,255,0.25);
		cursor: pointer;
		position:relative;
  		top:0px;
   		left:45%;
   		height:20px;
   		width:100px;
   		text-align:center;
   		font-size:110%
	}  

      
    </style>  
      
    </head>  
    <body>  
        <h1>以下为出入库信息表</h1> 
        <table style="border: 1px">  
            <tr>  
                <th>出入库操作类型</th>  
                <th>出入库产品编号</th>  
                <th>生产日期</th>    
                <th>出入库产品单价</th>
                <th>出入库产品数量</th>
                <th>客户编号</th>
                <th>仓库编号</th>
                <th>经办人</th>
                <th>出入库日期</th>
                <th>出入库标记</th>   
            </tr>  
            <%  ArrayList<Inoutstoreinfo> ss =(ArrayList<Inoutstoreinfo>)request.getAttribute("result");   
                for(Inoutstoreinfo s : ss){  
            %>  
            <tr>  
                <td><%=s.getCrtype()%></td>
                <td><%=s.getPno() %></td>
                <td><%=s.getPdate() %></td>
                <td><%=s.getPcrprice() %></td>
                <td><%=s.getPcrnum() %> </td>
                <td><%=s.getCno() %></td>
                <td><%=s.getSno() %></td>
                <td><%=s.getOperator() %></td>
                <td><%=s.getCrdate() %></td>
                <td><%=s.getCrtag() %></td>
            </tr>  
            <%   
                }  
            %>  
        </table>
        <div id="toAdd"><a href="searchstoreinfoServlet">库存信息</a></div>  
    </body>  
    </html>  