package cn.edu.bupt.ch5_2;

import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class DemoInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws IOException {
        System.out.println("++++++++++ preHandle ++++++++++");
        HttpSession session=request.getSession();
        if(session.getAttribute("USER")!=null||request.getRequestURI().contains("login"))
            return true;
        else
        {
            response.sendRedirect("/login");
            return false;
        }
    }

}
