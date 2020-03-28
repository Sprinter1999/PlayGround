package cn.edu.bupt.spring_boot_jsp;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class IndexController {

    @GetMapping("/")
    String index(Model model){
        model.addAttribute("msg","Hello World!");
        return "index";
    }
}
