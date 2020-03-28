package cn.edu.bupt.ch9_2.config;

import cn.edu.bupt.ch9_2.filter.GTVGInterceptor;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration
public class WebConfig implements WebMvcConfigurer {

    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        registry.addInterceptor(new GTVGInterceptor()).addPathPatterns("/**").excludePathPatterns();
    }
}
