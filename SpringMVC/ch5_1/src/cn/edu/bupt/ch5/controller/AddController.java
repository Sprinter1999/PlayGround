package cn.edu.bupt.ch5.controller;

import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.UnsupportedEncodingException;
import java.util.List;

public class AddController implements Controller {
    @Override
    public String handleRequest( HttpServletRequest request, HttpServletResponse response) {
        if(request.getMethod().equals("GET")){
            return "/WEB-INF/add.jsp";
        }else if (request.getMethod().equals("POST")){
            HttpSession session = request.getSession();
            List<String> todos = (List<String>) session.getAttribute("todos");
            try {
                request.setCharacterEncoding("utf-8");
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
            String todo = request.getParameter("todo");
            todos.add(todo);
            return "/WEB-INF/success.jsp";
        }
        return null;
    }
}
