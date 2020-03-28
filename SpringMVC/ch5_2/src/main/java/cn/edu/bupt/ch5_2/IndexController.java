package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpSession;


@Controller
@RequestMapping(value ={"/","/index"})
public class IndexController {
    @GetMapping
    public String index(Model model, HttpSession session){
//        model.addAttribute("personList", session.getAttribute("personinfos"));
        System.out.println("有一次新的请求");
        return "index";
}


}

