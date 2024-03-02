
package demo;

import java.sql.*;

public class Demo  {

    
    public static void main(String[] args) throws Exception{
        
        
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/college","root","Pda@3210");
        PreparedStatement ps = con.prepareStatement("insert into student values(?,?,?,?)");
        ps.setString(1,"Sojal" );
        ps.setInt(2,69 );
        ps.setFloat(3,99 );
        ps.setString(4,"Fatehunj" );
        
        int x =ps.executeUpdate();
        
        if(x>0){System.out.println("Success");}
        else{System.out.println("Nothing");}
        
        
    }
    
}
