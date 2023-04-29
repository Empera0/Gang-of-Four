#include <iostream>
#include <string>
using namespace std;

// Product class representing the pizza
class Pizza{
    private:
        string dough;
        string sauce;  
        string topping;
    public:
    void setDough(const string& dough){ this ->dough = dough;}
    void setSauce(const string& sauce){ this ->sauce = sauce;}
    void setTopping(const string& topping){ this ->topping = topping;}
    void showPizza(){
        cout << "Pizza with " << dough << " dough, " << sauce << " sauce, " << topping << " topping." << endl;    
    }


};

// Abstract Builder class providing the interface for building the pizza
class PizzaBuilder{
    protected:
        Pizza* pizza;

    public:
    virtual ~PizzaBuilder(){}

    Pizza* getPizza(){ return pizza;}
    void createNewPizza(){ pizza = new Pizza();}

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
};

// Concrete Builder class for building a Hawaiian pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    virtual ~HawaiianPizzaBuilder() {}

    virtual void buildDough() {
        pizza->setDough("cross");
    }

    virtual void buildSauce() {
        pizza->setSauce("mild");
    }

    virtual void buildTopping() {
        pizza->setTopping("ham and pineapple");
    }
};

// Concrete Builder class for building a Spicy pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    virtual ~SpicyPizzaBuilder() {}

    virtual void buildDough() {
        pizza->setDough("pan baked");
    }

    virtual void buildSauce() {
        pizza->setSauce("hot");
    }

    virtual void buildTopping() {
        pizza->setTopping("pepperoni and salami");
    }
};

// Director class responsible for managing the construction of the pizza
class Cook {
private:
    PizzaBuilder* pizzaBuilder;

public:
    void setPizzaBuilder(PizzaBuilder* pb) {
        pizzaBuilder = pb;
    }

    Pizza* getPizza() {
        return pizzaBuilder->getPizza();
    }

    void constructPizza() {
        pizzaBuilder->createNewPizza();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
    }
};

// Main function to demonstrate the use of the Builder pattern
int main() {
    // Create a cook to manage the construction of the pizza
    Cook cook;

    // Create a Hawaiian pizza builder and build the pizza
    PizzaBuilder* hawaiianPizzaBuilder = new HawaiianPizzaBuilder();
    cook.setPizzaBuilder(hawaiianPizzaBuilder);
    cook.constructPizza();
    Pizza* hawaiianPizza = cook.getPizza();
    hawaiianPizza->showPizza();
    delete hawaiianPizzaBuilder;
    delete hawaiianPizza;

    // Create a Spicy pizza builder and build the pizza
    PizzaBuilder* spicyPizzaBuilder = new SpicyPizzaBuilder();
    cook.setPizzaBuilder(spicyPizzaBuilder);
    cook.constructPizza();
    Pizza* spicyPizza = cook.getPizza();
    spicyPizza->showPizza();
    delete spicyPizzaBuilder;
    delete spicyPizza;

    return 0;
}