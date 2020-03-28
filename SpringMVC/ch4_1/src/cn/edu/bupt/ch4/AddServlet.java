package cn.edu.bupt.ch4;
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

@WebServlet(name = "AddServlet",urlPatterns = {"/add"})
public class AddServlet extends HttpServlet
    {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        RequestDispatcher rq = request.getRequestDispatcher("/WEB-INF/add.jsp");
        rq.forward(request,response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        List<String> userinfos = (List<String>)session.getAttribute("userinfos");
        if(userinfos == null){
            userinfos = new ArrayList<String>();
            session.setAttribute("userinfos",userinfos);
        }
        request.setCharacterEncoding("utf-8");
        System.out.println(userinfos);
        user us=new user(request.getParameter("username"),request.getParameter("telephone"),request.getParameter("emailAddress"));
        userinfos.add(us.toString());
        System.out.println(userinfos);
        session.setAttribute("userinfos",userinfos);
        RequestDispatcher rq = request.getRequestDispatcher("/WEB-INF/success.jsp");
        rq.forward(request,response);
    }
}
