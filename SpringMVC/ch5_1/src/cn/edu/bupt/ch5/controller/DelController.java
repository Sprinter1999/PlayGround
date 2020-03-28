package cn.edu.bupt.ch5.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.util.List;

public class DelController implements Controller {
    @Override
    public String handleRequest(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession();
        List<String> todos = (List<String>) session.getAttribute("todos");
        int index = Integer.parseInt(request.getParameter("index"));
        todos.remove(index);
        return "/WEB-INF/success.jsp";
    }
}
