package com.servlet;  
  
import java.io.IOException;  
import java.sql.Connection;  
import java.sql.DriverManager;  
import java.sql.PreparedStatement;  
import java.sql.ResultSet;  
import java.sql.SQLException;  
  

import java.util.ArrayList;
import java.sql.Date;

import javax.servlet.ServletException;  
import javax.servlet.http.HttpServlet;  
import javax.servlet.http.HttpServletRequest;  
import javax.servlet.http.HttpServletResponse;  

import com.bean.Inoutstoreinfo;
  
public class Addcrinfo2Servlet extends HttpServlet {  
      
     @SuppressWarnings("resource")
	protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {    
        //第一步，先把字符集设定成utf-8，否则万一浏览器送来的是中文就会出现乱码  
        request.setCharacterEncoding("utf-8");     
        String kno=request.getParameter("kno").trim();
        String cztype = request.getParameter("cztype");  
        String pno = request.getParameter("pno").trim();  
        String pdate=request.getParameter("pdate").trim();  
        int pcrprice = Integer.parseInt(request.getParameter("pcrprice").trim()); 
        int pcrnum = Integer.parseInt(request.getParameter("pcrnum").trim());
        String cno=request.getParameter("cno").trim();
        String sno=request.getParameter("sno").trim();
        String operator=request.getParameter("operator").trim();
        String crdate=request.getParameter("crdate").trim();
        String crtag=request.getParameter("crtag").trim();
        int flag=0;
        try {  
        	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=company";
            String username="sa";
            String password="19970710"; 
			Connection dbConn=null;
			dbConn= DriverManager.getConnection(dbURL,username,password); 
			String sql="select pno p,pupnum upnum from product";
			PreparedStatement ps = dbConn.prepareStatement(sql);
			ResultSet rs=ps.executeQuery(); 
			
			String pp;
			int num=0;
			while(rs.next()){
			   pp=rs.getString("p").trim();
			   if(pp.equals(pno)){
			      num=rs.getInt("upnum");
			      flag=1;
			      if(pcrnum>num){
			    	  flag=3;
			      }
			   }
			}
			
			sql="select pno p2,pnum pn from kucun";
			ps = dbConn.prepareStatement(sql);
			rs=ps.executeQuery(); 
			
			String p2;
			int num2=pcrnum;
			while(rs.next()){
			   p2=rs.getString("p2").trim();
			   if(p2.equals(pno)){
			      num2+=rs.getInt("pn");
			   }
			}
			if(num2>num){
				flag=3;
			}
			
			sql="select cno c from client";
			ps = dbConn.prepareStatement(sql);
			rs=ps.executeQuery(); 
			int flag2=0;
			String p3;
			while(rs.next()){
			   p3=rs.getString("c").trim();
			   if(p3.equals(cno)){
				   flag2=1;
			   }
			}
			if(flag2==0){
				flag=0;
			}
			
			sql="select sno s from store";
			ps = dbConn.prepareStatement(sql);
			rs=ps.executeQuery(); 
			int flag3=0;
			String p4;
			while(rs.next()){
			   p4=rs.getString("s").trim();
			   if(p4.equals(sno)){
				   flag3=1;
			   }
			}
			if(flag3==0){
				flag=0;
			}
			
			
			
		    if(flag==1){
			 sql="insert into crinfo(cztype,pno,pdate,pcrprice,pcrnum,cno,sno,operator,crdate,crtag) values(?,?,?,?,?,?,?,?,?,?)";
			 ps=dbConn.prepareStatement(sql);
			 ps.setString(1,cztype);
			 ps.setString(2,pno);
			 ps.setString(3,pdate);
			 ps.setInt(4,pcrprice);
			 ps.setInt(5,pcrnum);
			 ps.setString(6,cno);
			 ps.setString(7, sno);
			 ps.setString(8, operator);
			 ps.setString(9,crdate);
			 ps.setString(10,crtag);
			 ps.executeUpdate();
			 sql="insert into kucun(kno,pno,sno,prprice,pnum,pdate) values(?,?,?,?,?,?)";
			 ps=dbConn.prepareStatement(sql);
			 ps.setString(1,kno);
		     ps.setString(2,pno);
			 ps.setString(3,sno);
			 ps.setInt(4,pcrprice);
			 ps.setInt(5,pcrnum);
			 ps.setString(6,pdate);
		     ps.executeUpdate();
			//关闭连接  
	         ps.close();   
			 dbConn.close();
		    }
        }catch (SQLException e) {  
            e.printStackTrace();  
        } catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        if(flag==1){
          response.sendRedirect("SearchcrinfoServlet");
        }
        else if(flag==3){
        	response.sendRedirect("error2.jsp");
        }
        else{
        	response.sendRedirect("error1.jsp");
        }
    }    
    
    protected void doPost(HttpServletRequest request,    
            HttpServletResponse response) throws ServletException, IOException {    
        doGet(request, response);    
    }    
}


