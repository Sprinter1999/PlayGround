package beans;

public class SaleBill {
    /**
     * SALERECORDID
     */
    private String SaleBillID;
    /**
     * DATE
     */
    private String Date;
    /**
     * TIME
     */
    private String Time;
    /**
     * CLIENTID
     */
    private String customerID;

    /*
    * 客户姓名
     */
    private String customerName;

    /*
    * 售货员姓名
     */

    private String salerName;
    /**
     * SALERID
     */
    private String salerID;

    public SaleBill() {
    }

    public String getSaleBillID() {
        return SaleBillID;
    }

    public void setSaleBillID(String saleBillID) {
        SaleBillID = saleBillID;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }

    public String getTime() {
        return Time;
    }

    public void setTime(String time) {
        Time = time;
    }

    public String getCustomerID() {
        return customerID;
    }

    public void setCustomerID(String customerID) {
        this.customerID = customerID;
    }

    public String getSalerID() {
        return salerID;
    }

    public void setSalerID(String salerID) {
        this.salerID = salerID;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public String getSalerName() {
        return salerName;
    }

    public void setSalerName(String salerName) {
        this.salerName = salerName;
    }
}
