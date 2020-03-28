package cn.edu.bupt.ch4;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@WebServlet(name = "UpdateServlet",urlPatterns = {"/update"})
public class UpdateServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        List<String> userinfos = (List<String>) session.getAttribute("userinfos");
        int index = Integer.parseInt(request.getParameter("index"));
        String userinfo = userinfos.get(index);
        request.setAttribute("index",index);
        request.setAttribute("userinfo",userinfo);
        RequestDispatcher rq = request.getRequestDispatcher("/WEB-INF/update.jsp");
        rq.forward(request,response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        List<String> userinfos = (List<String>) session.getAttribute("userinfos");
        request.setCharacterEncoding("utf-8");
        String userinfo = request.getParameter("userinfo");
        int index = Integer.parseInt(request.getParameter("index"));
        userinfos.set(index,userinfo);
        RequestDispatcher rq = request.getRequestDispatcher("/WEB-INF/success.jsp");
        rq.forward(request,response);
    }
}
