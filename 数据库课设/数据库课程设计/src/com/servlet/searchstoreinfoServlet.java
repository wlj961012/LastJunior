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

import com.bean.Storeinfo;
  
public class searchstoreinfoServlet extends HttpServlet {  
      
     protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {    
        //第一步，先把字符集设定成utf-8，否则万一浏览器送来的是中文就会出现乱码  
        request.setCharacterEncoding("utf-8");     
        
        try {  
        	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=company";
            String username="sa";
            String password="19970710"; 
			Connection dbConn=null;
			
			dbConn= DriverManager.getConnection(dbURL,username,password);
			PreparedStatement ps;
			String sql="select * from kucun";
			ps=dbConn.prepareStatement(sql);
             
            ResultSet rs=ps.executeQuery();  
            ArrayList<Storeinfo> sinfo_list=new ArrayList<Storeinfo>();
            while(rs.next()){
            	Storeinfo p=new Storeinfo();
            	p.setKno(rs.getString("kno"));
            	p.setPno(rs.getString("pno"));
            	p.setSno(rs.getString("sno"));
            	p.setPnum(rs.getInt("pnum"));
            	p.setPdate(rs.getDate("pdate"));
            	sinfo_list.add(p);
            }
            request.setAttribute("result", sinfo_list);
            request.getRequestDispatcher("liststoreinfo.jsp").forward(request, response);
            rs.close();
            ps.close();
            dbConn.close();
        } catch (SQLException e) {  
            e.printStackTrace();  
        } catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}    
    }    
    
    protected void doPost(HttpServletRequest request,    
            HttpServletResponse response) throws ServletException, IOException {    
        doGet(request, response);    
    }    
}