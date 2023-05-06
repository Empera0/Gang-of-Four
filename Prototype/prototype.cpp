#include <iostream>
#include <unordered_map>

class Shape {
public:
  virtual void draw() = 0;
  virtual Shape* clone() = 0;
};

class Rectangle : public Shape {
public:
  void draw() {
    std::cout << "Drawing a rectangle" << std::endl;
  }
  Shape* clone() {
    return new Rectangle(*this);
  }
};

class Circle : public Shape {
public:
  void draw() {
    std::cout << "Drawing a circle" << std::endl;
  }
  Shape* clone() {
    return new Circle(*this);
  }
};

class ShapeCache {
public:
  static void loadCache() {
    Rectangle* rect = new Rectangle();
    Circle* cir = new Circle();
    shapeMap["rect"] = rect;
    shapeMap["circle"] = cir;
  }

  static Shape* getShape(std::string shapeName) {
    return shapeMap[shapeName]->clone();
  }

private:
  static std::unordered_map<std::string, Shape*> shapeMap;
};

std::unordered_map<std::string, Shape*> ShapeCache::shapeMap;

int main() {
  ShapeCache::loadCache();

  Shape* clonedShape1 = ShapeCache::getShape("rect");
  Shape* clonedShape2 = ShapeCache::getShape("circle");

  clonedShape1->draw();
  clonedShape2->draw();

  delete clonedShape1;
  delete clonedShape2;

  return 0;
}