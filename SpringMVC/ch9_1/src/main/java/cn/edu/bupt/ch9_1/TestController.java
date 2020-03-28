package cn.edu.bupt.ch9_1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class TestController {
    @Autowired
    CustomerRepository customerRepository;
    @GetMapping("/add")
    String add(String firstName, String lastName){
        Customer customer = new Customer(firstName,lastName);
        customerRepository.save(customer);
        return "ok";
    }

    @GetMapping("/find")
    List<Customer> find(String lastName){
        List<Customer> customerList = customerRepository.findByLastName(lastName);
        return customerList;
    }
    @GetMapping("/page")
    Page<Customer> page(String firstName, Integer pageNo, Integer pageSize){
        Pageable pageable = PageRequest.of(pageNo,pageSize);
        Page<Customer> customerPage = customerRepository.findAllByFirstName(firstName,pageable);
        return customerPage;
    }
}
