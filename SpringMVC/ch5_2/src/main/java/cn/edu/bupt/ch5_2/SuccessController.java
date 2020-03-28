package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

@Controller
@RequestMapping("/success")
public class SuccessController {
    @GetMapping
    String get() {
        return "success";
    }

    @PostMapping
    public String index(Model model, HttpServletRequest rq) {
        model.addAttribute("personList", rq.getSession().getAttribute("personinfos"));
        System.out.println("EEE" +rq.getSession().getAttribute("personinfos"));
        return "index";
    }
}
