package cn.edu.bupt.ch9_2.controller;

import cn.edu.bupt.ch9_2.dao.ProductRepository;
import cn.edu.bupt.ch9_2.entity.Comment;
import cn.edu.bupt.ch9_2.entity.Product;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

@Controller
@RequestMapping("/product")
public class ProductController {
    @Autowired
    ProductRepository productRepository;

//    public ProductController() {
//    }

    @GetMapping("/list")
    String list(Model model){
       List<Product> allProducts = productRepository.findAll();
        model.addAttribute("prods",allProducts);
        return "product/list";

    }

    @GetMapping("/comments")
    String comments(Model model, Long prodId){
        Product product = productRepository.getOne(prodId);
        model.addAttribute("prod",product);
        return "product/comments";
    }

}
