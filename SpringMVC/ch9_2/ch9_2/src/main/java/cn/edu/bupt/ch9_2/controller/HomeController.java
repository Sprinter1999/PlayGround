package cn.edu.bupt.ch9_2.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.HttpRequestHandler;
import org.springframework.web.bind.annotation.GetMapping;

import javax.servlet.http.HttpSession;
import java.util.Calendar;

@Controller
public class HomeController {

    @GetMapping("/")
    String getIndex(HttpRequestHandler req,Model model){
        model.addAttribute("today", Calendar.getInstance());
//        HttpSession session=req.
//        System.out.println();
        return "home";
    }
}
