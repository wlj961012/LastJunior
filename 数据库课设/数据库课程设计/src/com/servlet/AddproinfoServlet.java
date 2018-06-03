package com.servlet;  
  
import java.io.IOException;  
import java.sql.Connection;  
import java.sql.DriverManager;  
import java.sql.PreparedStatement;  
import java.sql.ResultSet;  
import java.sql.SQLException;  
  

import java.util.ArrayList;

import javax.servlet.ServletException;  
import javax.servlet.http.HttpServlet;  
import javax.servlet.http.HttpServletRequest;  
import javax.servlet.http.HttpServletResponse;  

import com.bean.productinfo;
  
public class AddproinfoServlet extends HttpServlet {  
      
     protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {    
        //第一步，先把字符集设定成utf-8，否则万一浏览器送来的是中文就会出现乱码  
        request.setCharacterEncoding("utf-8");     
        
        String pronon = request.getParameter("pronon");  
        String proname = request.getParameter("proname");  
        String prosize = request.getParameter("prosize");
        Boolean flag=true;
        int proprize = Integer.valueOf(request.getParameter("proprize")); 
        int uppernum = Integer.valueOf(request.getParameter("uppernum"));
        int downnum = Integer.valueOf(request.getParameter("downnum"));
        try {  
        	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=company";
            String username="sa";
            String password="19970710"; 
			Connection dbConn=null;
			dbConn= DriverManager.getConnection(dbURL,username,password);
			
			String sql = "select pno p from product";    
            PreparedStatement ps = dbConn.prepareStatement(sql);    
            ResultSet rs=ps.executeQuery();  
            while(rs.next()){
            	if(pronon.equals(rs.getString("p").trim())){
            		flag=false;
            	}
            }
            
            if(flag){
				sql = "insert into product(pno,pname,psize,pckprize,pupnum,pdownnum) values('"+pronon+"','"+proname+"','"+prosize+"','"+proprize+"','"+uppernum+"','"+downnum+"')";    
	            ps = dbConn.prepareStatement(sql);    
	            ps.executeUpdate(); 
            }
              
            //关闭连接  
            ps.close();    
            dbConn.close();    
        } catch (SQLException e) {  
            e.printStackTrace();  
        } catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        if(flag){
        	response.sendRedirect("searchproinfoServlet");
        }
        else{
        	response.sendRedirect("error3.jsp");
        }
    }    
    
    protected void doPost(HttpServletRequest request,    
            HttpServletResponse response) throws ServletException, IOException {    
        doGet(request, response);    
    }    
}
