package beans;

/**
 * 库存信息实体类
 */
public class Stock {
    /**
     * MEDICINEID
     */
    private String drugID;

    private String drugName;
    /**
     * PRODUCEDATE
     */
    private String produceDate;
    /**
     * EFFICIENTDATE
     */
    private String vaildDate;
    /**
     * 库存数量
     */
    private int quantity;

    public String getDrugID() {
        return drugID;
    }

    public void setDrugID(String drugID) {
        this.drugID = drugID;
    }

    public String getProduceDate() {
        return produceDate;
    }

    public void setProduceDate(String produceDate) {
        this.produceDate = produceDate;
    }

    public String getVaildDate() {
        return vaildDate;
    }

    public void setVaildDate(String vaildDate) {
        this.vaildDate = vaildDate;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }


    public String getDrugName() {
        return drugName;
    }

    public void setDrugName(String drugName) {
        this.drugName = drugName;
    }
}
