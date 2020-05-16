package beans;


public class Producer {
    /**
     * FACTORYID
     */
    private String producerID;
    /**
     * FACTORYNAME
     */
    private String producerName;
    /**
     * ADDRESS
     */
    private String producerAddress;
    /**
     * PHONE
     */
    private String producerPhone;

    public String getProducerID() {
        return producerID;
    }

    public void setProducerID(String producerID) {
        this.producerID = producerID;
    }

    public String getProducerName() {
        return producerName;
    }

    public void setProducerName(String producerName) {
        this.producerName = producerName;
    }

    public String getProducerAddress() {
        return producerAddress;
    }

    public void setProducerAddress(String producerAddress) {
        this.producerAddress = producerAddress;
    }

    public String getProducerPhone() {
        return producerPhone;
    }

    public void setProducerPhone(String producerPhone) {
        this.producerPhone = producerPhone;
    }
}
