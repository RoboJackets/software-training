#include "../include/proper_structure.hpp"
#include <iostream>

namespace proper_structure
{
    ProperStructure::ProperStructure(int num1, int num2) {
        this->num1 = num1;
        this->num2 = num2;
    }
}

int main(int argc, char *argv[]) {
    auto proper = proper_structure::ProperStructure(5, 5);
}