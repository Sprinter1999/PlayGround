package cn.edu.bupt.ch4;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.net.http.HttpResponse;

@WebFilter(filterName = "DemoFilter",urlPatterns = {"/"})
public class DemoFilter implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException
    {
//        chain.doFilter(req, resp);
        HttpServletRequest httpRequest = (HttpServletRequest)req;
        HttpSession session = httpRequest.getSession();
        RequestDispatcher rd=httpRequest.getRequestDispatcher("WEB-INF/login.jsp");
        String key=(String)session.getAttribute("login");
        if(key!=null)
            chain.doFilter(httpRequest,resp);
        else
        {
            rd.forward(httpRequest,resp);
        }
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
