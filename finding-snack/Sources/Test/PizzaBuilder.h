#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Pizza.h"
// Abstract Builder
class PizzaBuilder
{
protected:
    std::auto_ptr<Pizza> pizza;
public:
    PizzaBuilder() {}
    virtual ~PizzaBuilder() {}
    std::auto_ptr<Pizza> GetPizza() { return pizza; }

    void createNewPizzaProduct() { pizza.reset(new Pizza); }

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
};
