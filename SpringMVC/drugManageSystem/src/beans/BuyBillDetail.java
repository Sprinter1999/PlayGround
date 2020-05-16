package beans;

public class BuyBillDetail {
    /**
     * BUYRECORDID
     */
    private String BuyBillID;


    /**
     * MEDICINEID
     */
    private String BuyBillName;
    /*
    * 对，不要怀疑，这是药品名称
     */
    private String drugID;
    /**
     * 进货数量
     */
    private int number;
    /**
     * BUYPRICE
     */

    private double buyPrice;

    /*
     * DATE
     */
    private String date;

    public String getBuyBillID() {
        return BuyBillID;
    }

    public void setBuyBillID(String buyBillID) {
        BuyBillID = buyBillID;
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

    public double getBuyPrice() {
        return buyPrice;
    }

    public void setBuyPrice(double buyPrice) {
        this.buyPrice = buyPrice;
    }

    public String getBuyBillName() {
        return BuyBillName;
    }

    public void setBuyBillName(String buyBillName) {
        BuyBillName = buyBillName;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

}
