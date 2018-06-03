package com.servlet;  
  
import java.io.IOException;  
import java.sql.Connection;  
import java.sql.DriverManager;  
import java.sql.PreparedStatement;  
import java.sql.ResultSet;  
import java.sql.SQLException;  
  

import java.util.ArrayList;
import java.util.Date;

import javax.servlet.ServletException;  
import javax.servlet.http.HttpServlet;  
import javax.servlet.http.HttpServletRequest;  
import javax.servlet.http.HttpServletResponse;  

import com.bean.Inoutstoreinfo;
import com.bean.Storeinfo;

  
public class DeletestoreinfoServlet extends HttpServlet {  
      
     protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {    
        //第一步，先把字符集设定成utf-8，否则万一浏览器送来的是中文就会出现乱码  
        request.setCharacterEncoding("utf-8");     
        
        String kno=request.getParameter("kno");
        String pno=request.getParameter("pno");
        String sno=request.getParameter("sno");
        Date pdate=new Date(request.getParameter("pdate"));
        
        try {  
        	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=company";
            String username="sa";
            String password="19970710"; 
			Connection dbConn=null;
			dbConn= DriverManager.getConnection(dbURL,username,password);    
            String sql="delete from kucun where kno=?";
			PreparedStatement ps = dbConn.prepareStatement(sql);
			ps.setString(1,kno);
            ps.executeUpdate();  
            //关闭连接  
            ps.close();    
            dbConn.close();    
        } catch (SQLException e) {  
            e.printStackTrace();  
        } catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        response.sendRedirect("searchproinfoServlet");  
    }    
    
    protected void doPost(HttpServletRequest request,    
            HttpServletResponse response) throws ServletException, IOException {    
        doGet(request, response);    
    }    
}

