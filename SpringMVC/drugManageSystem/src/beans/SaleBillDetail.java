package beans;

public class SaleBillDetail {
    /**
     * SALERECORDID
     */
    private String SaleBillID;

    /**
     * MEDICINEID
     */
    private String SaleBillName;
    /*
    * 对，不要怀疑，这是药品名称
     */

    private String drugID;
    /**
     * 售货数量
     */
    private int number;
    /**
     * SALEPRICE
     */
    private double salePrice;
    /*
     * DATE
     */
    private String date;

    public String getSaleBillID() {
        return SaleBillID;
    }

    public void setSaleBillID(String saleBillID) {
        SaleBillID = saleBillID;
    }

    public String getDrugID() {
        return drugID;
    }

    public void setDrugID(String drugID) {
        this.drugID = drugID;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public double getSalePrice() {
        return salePrice;
    }

    public void setSalePrice(double salePrice) {
        this.salePrice = salePrice;
    }

    public String getSaleBillName() {
        return SaleBillName;
    }

    public void setSaleBillName(String saleBillName) {
        SaleBillName = saleBillName;
    }
    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }
}
