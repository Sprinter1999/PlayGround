package cn.edu.bupt.ch5.servlet;

import cn.edu.bupt.ch5.controller.AddController;
import cn.edu.bupt.ch5.controller.DelController;
import cn.edu.bupt.ch5.controller.IndexController;
import cn.edu.bupt.ch5.controller.UpdateController;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "DispatchServlet",urlPatterns = {"/"})
public class DispatchServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        process(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        process(request,response);
    }
    private void process(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String uri = request.getRequestURI();
        int lastIndex = uri.lastIndexOf("/");
        String action = uri.substring(lastIndex+1);
        String dispatchUrl = null;
        if(action.equals("add")){
            AddController controller = new AddController();
            dispatchUrl = controller.handleRequest(request,response);
        }else if(action.equals("update")){
            UpdateController controller = new UpdateController();
            dispatchUrl = controller.handleRequest(request,response);
        }else if(action.equals("del")){
            DelController controller = new DelController();
            dispatchUrl = controller.handleRequest(request,response);
        }else{
            IndexController controller = new IndexController();
            dispatchUrl = controller.handleRequest(request,response);
        }
        if(dispatchUrl != null){
            RequestDispatcher rd = request.getRequestDispatcher(dispatchUrl);
            rd.forward(request,response);
        }
    }
}
