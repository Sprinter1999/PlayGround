package cn.edu.bupt.thymeleafexamples.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class UserProfileController {

    @GetMapping("userprofile")
    String get(){
        return "userprofile";
    }
}
