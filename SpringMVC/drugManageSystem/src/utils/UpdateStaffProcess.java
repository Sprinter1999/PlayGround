package utils;

import beans.Staff;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import static utils.Constant.Administrator;

public class UpdateStaffProcess {
    public static boolean  check(Staff staff){
        try{

            String str =
                    String.format("UPDATE EMPLOYEE SET NAME = '%s',PASSWORD = '%s',PHONE = '%s',POSITION = '%s',LEADERID = '%s' WHERE EMPLOYEEID = '%s';", staff.getName(), staff.getPsd(), staff.getPhone(), staff.getPosition(), staff.getLeaderID(), staff.getID());
            Connection conn = DBconn.getConnInstance(Administrator);
            PreparedStatement pstm = null;
            if (conn != null) {
                pstm = conn.prepareStatement(str);
            }
            int row = pstm.executeUpdate();
            if (row > 0) {
                System.out.println("修改成功");
                return true;
            } else {
                System.out.println("修改失败1");
                return false;
            }
        }catch (Exception e){
            System.out.println("修改失败2");
            return false;
        }
    }
}
