package cn.edu.bupt.ch9_2.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class SubscribeController {

    @GetMapping("subscribe")
    String get(){
        return "subscribe";
    }
}
