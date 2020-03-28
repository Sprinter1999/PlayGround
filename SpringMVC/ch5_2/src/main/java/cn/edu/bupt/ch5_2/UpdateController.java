package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.List;
        @Controller
        @RequestMapping("/update")
        public class UpdateController
        {
            @GetMapping
            public String doGet(HttpServletRequest request,Model model)
            {
                System.out.println("yyy");
                HttpSession session = request.getSession();
                List<String> personinfos = (List<String>) session.getAttribute("personinfos");
                int index = Integer.parseInt(request.getParameter("index"));
                System.out.println("yy"+request.getParameter("index"));
                String personinfo = personinfos.get(index);
//        request.setAttribute("index",index);
                model.addAttribute("index",index);
                System.out.println("GET Update index"+request.getAttribute("index"));
//        request.setAttribute("personinfo",personinfo);
        return "update";
    }
    @PostMapping
    public String doPost(HttpServletRequest request) throws UnsupportedEncodingException {
        HttpSession session = request.getSession();
        System.out.println("index&personinfo:"+request.getParameter("index")+" "+ request.getParameter("personinfo"));
        int index = Integer.parseInt(request.getParameter("index"));
        List<String> personinfos = (List<String>) session.getAttribute("personinfos");
        request.setCharacterEncoding("utf-8");
        String personinfo = request.getParameter("personinfo");
        personinfos.set(index,personinfo);
        return "success";
    }
}
