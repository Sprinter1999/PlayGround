package cn.edu.bupt.thymeleafexamples.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.thymeleaf.context.Context;

import java.util.Calendar;

@Controller
public class HomeController {

    @GetMapping("/")
    String getIndex(Model model){
        model.addAttribute("today", Calendar.getInstance());
        return "home";
    }
}
