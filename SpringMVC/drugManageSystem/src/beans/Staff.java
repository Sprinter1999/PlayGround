package beans;


public class Staff {
    /**
     * EMPLOYEEID
     */
    private String ID;
    /**
     * 员工姓名
     */
    private String name;
    /**
     * 员工密码
     */
    private String Psd;
    /**
     * 员工电话
     */
    private String Phone;
    /**
     * 员工职位
     */
    private String position;
    /**
     * LEADERID
     */
    private String leaderID;


    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPsd() {
        return Psd;
    }

    public void setPsd(String psd) {
        Psd = psd;
    }

    public String getPhone() {
        return Phone;
    }

    public void setPhone(String phone) {
        Phone = phone;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public String getLeaderID() {
        return leaderID;
    }

    public void setLeaderID(String leaderID) {
        this.leaderID = leaderID;
    }
}
