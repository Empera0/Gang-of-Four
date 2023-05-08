#include <iostream>

// Araba imalatı için bir arayüz belirliyoruz
class ICarWorkshop {
public:
    virtual void manufacture() = 0;
};

// Farklı arabaların üretiminde kullanılacak
// farklı atölyeler için soyut bir sınıf oluşturuyoruz
class ICarAssemblyWorkshop {
public:
    virtual void assemble() = 0;
};

class ICarProductionWorkshop {
public:
    virtual void produce() = 0;
};

// Araba tiplerini temsil eden sınıflarımız
class Sedan : public ICarWorkshop {
public:
    Sedan(ICarAssemblyWorkshop* assemblyWorkshop, ICarProductionWorkshop* productionWorkshop)
        : mAssemblyWorkshop(assemblyWorkshop), mProductionWorkshop(productionWorkshop) {}

    void manufacture() override {
        std::cout << "Sedan manufacture\n";
        mAssemblyWorkshop->assemble();
        mProductionWorkshop->produce();
    }
private:
    ICarAssemblyWorkshop* mAssemblyWorkshop;
    ICarProductionWorkshop* mProductionWorkshop;
};

class SUV : public ICarWorkshop {
public:
    SUV(ICarAssemblyWorkshop* assemblyWorkshop, ICarProductionWorkshop* productionWorkshop)
        : mAssemblyWorkshop(assemblyWorkshop), mProductionWorkshop(productionWorkshop) {}

    void manufacture() override {
        std::cout << "SUV manufacture\n";
        mAssemblyWorkshop->assemble();
        mProductionWorkshop->produce();
    }
private:
    ICarAssemblyWorkshop* mAssemblyWorkshop;
    ICarProductionWorkshop* mProductionWorkshop;
};

// Farklı atölyeleri temsil eden sınıflarımız
class BodyShop : public ICarAssemblyWorkshop {
public:
    void assemble() override {
        std::cout << "BodyShop assemble\n";
    }
};

class EngineShop : public ICarProductionWorkshop {
public:
    void produce() override {
        std::cout << "EngineShop produce\n";
    }
};

int main() {
    ICarAssemblyWorkshop* sedanAssemblyWorkshop = new BodyShop();
    ICarProductionWorkshop* sedanProductionWorkshop = new EngineShop();
    ICarWorkshop* sedan = new Sedan(sedanAssemblyWorkshop, sedanProductionWorkshop);

    ICarAssemblyWorkshop* suvAssemblyWorkshop = new BodyShop();
    ICarProductionWorkshop* suvProductionWorkshop = new EngineShop();
    ICarWorkshop* suv = new SUV(suvAssemblyWorkshop, suvProductionWorkshop);

    // Üretim işlemleri
    sedan->manufacture();
    suv->manufacture();

    // Belleği serbest bırak
    delete sedan;
    delete suv;
    delete sedanAssemblyWorkshop;
    delete sedanProductionWorkshop;
    delete suvAssemblyWorkshop;
    delete suvProductionWorkshop;
    return 0;
}