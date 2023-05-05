#include <iostream>
#include <string>

class IProduct {
public:
  virtual ~IProduct() {}
  virtual std::string GetName() const = 0;
};

class ConcreteProductA : public IProduct {
public:
  std::string GetName() const override { return "ConcreteProductA"; }
};

class ConcreteProductB : public IProduct {
public:
  std::string GetName() const override { return "ConcreteProductB"; }
};

class Creator {
public:
  virtual ~Creator() {}
  virtual IProduct* CreateProduct() = 0;
};

class ConcreteCreatorA : public Creator {
public:
  IProduct* CreateProduct() override { return new ConcreteProductA(); }
};

class ConcreteCreatorB : public Creator {
public:
  IProduct* CreateProduct() override { return new ConcreteProductB(); }
};

int main() {
  Creator* creatorA = new ConcreteCreatorA();
  IProduct* productA = creatorA->CreateProduct();
  std::cout << productA->GetName() << std::endl;

  Creator* creatorB = new ConcreteCreatorB();
  IProduct* productB = creatorB->CreateProduct();
  std::cout << productB->GetName() << std::endl;

  delete creatorA;
  delete productA;
  delete creatorB;
  delete productB;
  return 0;
}