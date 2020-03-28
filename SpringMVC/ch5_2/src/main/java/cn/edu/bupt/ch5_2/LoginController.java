package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;


@Controller
@RequestMapping("/login")
public class LoginController {
    @GetMapping
    public String getForm()
    {
        return "login";
    }
    @PostMapping
    public String addDone(@ModelAttribute("user") User user, HttpSession session,HttpServletRequest request, HttpServletResponse response) throws IOException {
//        rq.getSession().setAttribute("USER",user);
        session.setAttribute("USER",user);
        System.out.println("有一次新的请求在login");
        response.sendRedirect("/index");
        return "index";
    }
}
