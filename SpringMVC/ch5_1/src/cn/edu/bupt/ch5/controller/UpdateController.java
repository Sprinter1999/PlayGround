package cn.edu.bupt.ch5.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.UnsupportedEncodingException;
import java.util.List;

public class UpdateController implements Controller {
    @Override
    public String handleRequest(HttpServletRequest request, HttpServletResponse response) {
        if(request.getMethod().equals("GET")){
            HttpSession session = request.getSession();
            List<String> todos = (List<String>) session.getAttribute("todos");
            int index = Integer.parseInt(request.getParameter("index"));
            String todo = todos.get(index);
            request.setAttribute("index",index);
            request.setAttribute("todo",todo);
            return "/WEB-INF/update.jsp";
        }else if (request.getMethod().equals("POST")){
            HttpSession session = request.getSession();
            List<String> todos = (List<String>) session.getAttribute("todos");
            try {
                request.setCharacterEncoding("utf-8");
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
            String todo = request.getParameter("todo");
            int index = Integer.parseInt(request.getParameter("index"));
            todos.set(index,todo);
            return "/WEB-INF/success.jsp";
        }
        return null;
    }
}
