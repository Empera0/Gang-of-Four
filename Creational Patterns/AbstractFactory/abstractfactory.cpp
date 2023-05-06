#include <iostream>
using namespace std;

// Abstract Product
class Button {
public:
  virtual void paint() = 0; // An abstract method that will be implemented by the concrete products
};

// Concrete Product A
class WindowsButton : public Button {
public:
  void paint() { cout << "Windows Button\n"; } // Implementation of the abstract method for WindowsButton
};

// Concrete Product B
class MacOSButton : public Button {
public:
  void paint() { cout << "MacOS Button\n"; } // Implementation of the abstract method for MacOSButton
};

// Abstract Factory
class GUIFactory {
public:
  virtual Button* createButton() = 0; // An abstract method that will be implemented by the concrete factories
};

// Concrete Factory A
class WindowsFactory : public GUIFactory {
public:
  Button* createButton() {
    return new WindowsButton(); // Implementation of the abstract method for WindowsFactory, returns a WindowsButton object
  }
};

// Concrete Factory B
class MacOSFactory : public GUIFactory {
public:
  Button* createButton() {
    return new MacOSButton(); // Implementation of the abstract method for MacOSFactory, returns a MacOSButton object
  }
};

// Client
class Application {
private:
  GUIFactory* factory; // A reference to a GUIFactory object
  Button* button; // A reference to a Button object
public:
  Application(GUIFactory* factory) : factory(factory) {} // Constructor, sets the factory reference

  void createUI() {
    button = factory->createButton(); // Uses the factory reference to create a new Button object
  }

  void paint() {
    button->paint(); // Calls the paint() method on the created Button object to display it on the screen
  }
};

int main() {
  Application* app;
  GUIFactory* factory;
  bool OSCreate = true;  
  // Create GUIFactory as per the requirement
  if (OSCreate) {
    factory = new WindowsFactory(); // Creates a new WindowsFactory object if the OS is Windows
  } else if (OSCreate) {
    factory = new MacOSFactory(); // Creates a new MacOSFactory object if the OS is MacOS
  }

  // Create Application object using the factory
  app = new Application(factory); // Creates a new Application object with the specified factory

  app->createUI(); // Calls the createUI() method on the Application object to create a new Button object
  app->paint(); // Calls the paint() method on the Application object to display the created Button object on the screen

  return 0;
}