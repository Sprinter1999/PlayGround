package beans;

public class DrugType {
    /**
     * TYPEID
     */
    private String ID;
    /**
     * 种类名称
     */
    private String typeName;
    /**
     * FATHERID
     */
    private String parentID;

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getTypeName() {
        return typeName;
    }

    public void setTypeName(String typeName) {
        this.typeName = typeName;
    }

    public String getParentID() {
        return parentID;
    }

    public void setParentID(String parentID) {
        this.parentID = parentID;
    }
}
