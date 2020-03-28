package cn.edu.bupt.thymeleafexamples.filter;

import cn.edu.bupt.thymeleafexamples.entities.User;
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
