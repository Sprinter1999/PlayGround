function jiecheng(n) {
    if (n == 1) {//跳出条件
        return 1;
    }
    return n * jiecheng(n - 1); //5*jie(4)
}


$(document).ready(function () {
    $(".button-item").click(function () {
        var num = $(this).attr("value");
        if (typeof num == "undefined")
            num = $(this).html();
        $("#result").text(function (i, origText) {
            return origText + num;
        });
    });

    $("#cal").click(function () {
        $("#result").text(function (i, origText) {
            if (origText.indexOf("!") >= 0) {
                tanhao = origText.indexOf("!");
                var str = origText.slice(0, tanhao);
                var num = eval(str);
                var result = jiecheng(num);
                return new String(result);
            }
            else if (origText.indexOf("log") >= 0) {
                log = origText.indexOf("g");
                var target = ")";
                var begin = log + 1, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = Math.log(eval(digits));
                return new String(logger);
            }
            else if (origText.indexOf("tan") >= 0) {
                log = origText.indexOf("tan");
                var target = ")";
                var begin = log + 3, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = Math.log(eval(digits));
                return new String(logger);
            }
            else if (origText.indexOf("sin") >= 0) {
                log = origText.indexOf("sin");
                var target = ")";
                var begin = log + 3, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = Math.sin(eval(digits));
                return new String(logger);
            }
            else if (origText.indexOf("cos") >= 0) {
                log = origText.indexOf("cos");
                var target = ")";
                var begin = log + 3, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = Math.cos(eval(digits));
                return new String(logger);
            }
            else if (origText.indexOf("sqrt") >= 0) {
                log = origText.indexOf("sqrt");
                var target = ")";
                var begin = log + 4, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = Math.sqrt(eval(digits));
                return new String(logger);
            }
            else if (origText.indexOf("±") >= 0) {
                log = origText.indexOf("±");
                var target = ")";
                var begin = log + 1, curr = log;
                while (origText.charAt(curr) != ")") {
                    curr = curr + 1;
                    if (curr == origText.length)
                        return "";
                }
                digits = origText.slice(begin + 1, curr);
                //alert(digits);
                logger = eval(digits);
                logger = (-1) * logger;
                return new String(logger);
            }
            return new String(eval(origText));
        });
    });

    $("#ce").click(function () {
        $("#result").text(function (i,origText) {
            var curr=origText.length-1;
            // alert(origText.charAt(curr-1));
            if(origText.charAt(curr)==")"||"("||"+"||"-"||"*"||"/"||"%")
                return origText.slice(0,curr-2);
            if(origText.charAt(curr)=="n"||"g")
                return origText.slice(0,curr-4);
            if(origText.charAt(curr)=="t")
                return origText.slice(0,curr-5);
            while( (eval(origText.charAt(curr))<=9) && (eval(origText.charAt(curr))>=1) )
            {
                curr=curr-1;
                // alert("in cycle")
                if(curr==")"||"("||"+"||"-"||"*"||"/"||"%")
                    break;
            }
            
            return origText.slice(0,curr-1);
        });
    });

    $("#c").click(function () {
        $("#result").text(function () {
            return "";
        });
    });



    $("#del").click(function () {
        $("#result").text(function (i, origText) {
            return origText.slice((-origText.length), -1);
        });
    });
});
