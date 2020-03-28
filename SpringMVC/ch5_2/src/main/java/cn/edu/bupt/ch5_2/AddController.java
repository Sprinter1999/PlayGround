package cn.edu.bupt.ch5_2;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
@Controller
@RequestMapping("/add")
public class AddController
{
    @GetMapping
    String getForm(){
        return "add";
    }
    @PostMapping
    String addDone(@ModelAttribute("person") Person person,HttpServletRequest rq){
        HttpSession session = rq.getSession();
        List<String> personinfos = (List<String>)session.getAttribute("personinfos");
        if(personinfos == null)
        {
            personinfos=new ArrayList<String>();
            session.setAttribute("personinfos",personinfos);
        }
        System.out.println(personinfos);
        Person ps=new Person(rq.getParameter("username"),rq.getParameter("telephone"),rq.getParameter("emailAddress"));
        personinfos.add(ps.toString());
        System.out.println(personinfos);
        session.setAttribute("personinfos",personinfos);
        return "success";
    }
}