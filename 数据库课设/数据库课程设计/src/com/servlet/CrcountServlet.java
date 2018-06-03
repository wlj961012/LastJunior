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

import com.bean.Crtongji;
  
public class CrcountServlet extends HttpServlet {  
      
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
			String sql="select product.pno p1,COUNT(*) c,pname pn from product,crinfo where product.pno=crinfo.pno and crinfo.cztype='出'group by product.pno,pname";
			ps=dbConn.prepareStatement(sql);
           
            ResultSet rsc=ps.executeQuery();  
            ArrayList<Crtongji> cinfo_list=new ArrayList<Crtongji>();
            while(rsc.next()){
            	Crtongji p=new Crtongji();
            	p.setPno(rsc.getString("p1"));
            	p.setCount(Integer.parseInt(rsc.getString("c")));
            	p.setPname(rsc.getString("pn"));
            	cinfo_list.add(p);
            }
            request.setAttribute("result1", cinfo_list);
            
            sql="select product.pno p1,COUNT(*) c,pname pn from product,crinfo where product.pno=crinfo.pno and crinfo.cztype='入'group by product.pno,pname";
			ps=dbConn.prepareStatement(sql);
             
            ResultSet rsr=ps.executeQuery();  
            ArrayList<Crtongji> rinfo_list=new ArrayList<Crtongji>();
            while(rsr.next()){
            	Crtongji p=new Crtongji();
            	p.setPno(rsr.getString("p1"));
            	p.setCount(Integer.parseInt(rsr.getString("c")));
            	p.setPname(rsr.getString("pn"));
            	rinfo_list.add(p);
            }
            request.setAttribute("result2", rinfo_list);

            
            request.getRequestDispatcher("listcrcount.jsp").forward(request, response);
            rsc.close();
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

