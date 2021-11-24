#pragma once
#include <iostream>
#include <memory>
#include <string>
// Product
class Pizza
{
private:
    std::string dough;
    std::string sauce;
    std::string topping;

public:
    Pizza() { }
    ~Pizza() { }

    void SetDough(const std::string& d) { dough = d; };
    void SetSauce(const std::string& s) { sauce = s; };
    void SetTopping(const std::string& t) { topping = t; }

    void ShowPizza()
    {
        std::cout << " Yummy !!!" << std::endl
            << "Pizza with Dough as " << dough
            << ", Sauce as " << sauce
            << " and Topping as " << topping
            << " !!! " << std::endl;
    }
};
