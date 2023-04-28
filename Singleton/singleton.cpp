#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void showMessage() {
        std::cout << "Singleton Pattern" << std::endl;
    }
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();

    if (&instance1 == &instance2) {
        std::cout << "Aynı örnektir" << std::endl;
    }
    else {
        std::cout << "Farklı örneklerdir" << std::endl;
    }
    instance1.showMessage();
    instance2.showMessage();

    return 0;
}