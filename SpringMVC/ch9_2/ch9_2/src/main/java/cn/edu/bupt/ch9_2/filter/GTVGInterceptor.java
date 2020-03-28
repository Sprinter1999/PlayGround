package cn.edu.bupt.ch9_2.filter;

import cn.edu.bupt.ch9_2.entity.User;
import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class GTVGInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) {
        request.getSession(true).setAttribute("user", new User("John", "Apricot", "Antarctica", null));
        return true;
    }
}
