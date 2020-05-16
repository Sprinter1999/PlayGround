package utils;

import beans.Staff;
import utils.DBconn;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import static utils.Constant.*;

/*
* 用于对员工进行登录检查
 */
public class StaffOper {
    public static Staff check(Staff staff){
        Staff returnStaff = new Staff();
        String sql = "SELECT * FROM EMPLOYEE WHERE EMPLOYEEID = ? AND PASSWORD = ? AND POSITION = ?";
        String sid = staff.getID();
        String pass = staff.getPsd();
        String pos = staff.getPosition();
        Connection conn = DBconn.getConnInstance();
        switch (pos) {
            case "ADMIN":
                conn = DBconn.getConnInstance(Administrator);
                break;
            case "MEDMANAGER":
                conn = DBconn.getConnInstance(drugManager);
                break;
            case "SALER":
                conn = DBconn.getConnInstance(saler);
                break;
            case "BUYER":
                conn = DBconn.getConnInstance(buyer);
                break;
            case "RETURNER":
                conn = DBconn.getConnInstance(returnGooder);
                break;
        }

        try{
            assert conn != null;
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,sid);
            pstmt.setString(2,pass);
            pstmt.setString(3,pos);
            ResultSet rs = pstmt.executeQuery();
            if (rs.next()){

                returnStaff.setID(sid);
                returnStaff.setPsd(pass);
                String name = rs.getString("NAME");
                returnStaff.setName(name);
                String position = rs.getString("POSITION");
                returnStaff.setPosition(position);

                returnStaff.setPhone(rs.getString(4));
                returnStaff.setLeaderID(rs.getString(6));

                return returnStaff;
            }else {
                return null;
            }
        }catch (Exception e){
            return null;
        }

    }
}
