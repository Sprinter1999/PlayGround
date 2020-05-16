$(function () {
    var str = $("#myformcontrol").val();
    if (str == "ADMIN"){
        var String =
            "<option>MEDMANAGER</option>\n" +
            "<option>SALER</option>\n" +
            "<option>BUYER</option>\n" +
            "<option>RETURNER</option>";
        $("#myformcontrol").append(String);
    }
    else if (str == "MEDMANAGER") {
        var String =
            "<option>ADMIN</option>\n" +
            "<option>SALER</option>\n" +
            "<option>BUYER</option>\n" +
            "<option>RETURNER</option>";
        $("#myformcontrol").append(String);
    }
    else if (str == "SALER") {
        var String =
            "<option>ADMIN</option>\n" +
            "<option>MEDMANAGER</option>\n" +
            "<option>BUYER</option>\n" +
            "<option>RETURNER</option>";
        $("#myformcontrol").append(String);
    }
    else if (str == "BUYER") {
        var String =
            "<option>ADMIN</option>\n" +
            "<option>SALER</option>\n" +
            "<option>MEDMANAGER</option>\n" +
            "<option>RETURNER</option>";
        $("#myformcontrol").append(String);
    }
    else if (str == "RETURNER") {
        var String =
            "<option>ADMIN</option>\n" +
            "<option>SALER</option>\n" +
            "<option>BUYER</option>\n" +
            "<option>MEDMANAGER</option>";
        $("#myformcontrol").append(String);
    }

})