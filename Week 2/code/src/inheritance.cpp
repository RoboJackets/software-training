#include <iostream>

class Animal
{
public:
    virtual int getNumberOfLegs() = 0;
};

class Moose : Animal
{
public:
    Moose(int legs = 4, int antlers = 2) {
        this->numLegs = legs;
        this->numAntlers = antlers;
    }
    
    int getNumberOfLegs() {
        return numLegs;
    }

    int getNumberOfAntlers() {
        return numAntlers;
    }

private:
    int numLegs;
    int numAntlers;
};

int main(int argc, char *argv[]) {
    //Animal a = Animal();

    Moose moose = Moose();
    std::cout << "Number of Legs = " << moose.getNumberOfLegs() << '\n';
}