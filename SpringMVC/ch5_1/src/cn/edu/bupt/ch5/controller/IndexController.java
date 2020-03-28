package cn.edu.bupt.ch5.controller;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.util.ArrayList;
import java.util.List;

public class IndexController implements Controller {
    @Override
    public String handleRequest(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession();
        List<String> todos =(List<String>)session.getAttribute("todos");
        if(todos == null){
            todos = new ArrayList<String>();
            session.setAttribute("todos",todos);
        }
        return "/WEB-INF/index.jsp";
    }
}
