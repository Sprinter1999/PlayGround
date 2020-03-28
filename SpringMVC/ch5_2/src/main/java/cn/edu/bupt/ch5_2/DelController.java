package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/del")
public class DelController {
    @GetMapping
    public String doGet(HttpServletRequest request)
    {
        HttpSession session = request.getSession();
        List<String> personinfos = (List<String>)session.getAttribute("personinfos");
        int index = Integer.parseInt(request.getParameter("index"));
        personinfos.remove(index);
        return "success";
    }
}
