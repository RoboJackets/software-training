#include "../include/proper_structure.hpp"
#include <iostream>

namespace proper_structure
{
    ProperStructure::ProperStructure(int something) {
        this->something = something;
    }

    std::vector<int> ProperStructure::makeVectorOfSomething(int length) {
        return std::vector<int>(something, length);
    }

}

int main(int argc, char *argv[]) {
    auto proper = proper_structure::ProperStructure(5);
    std::vector<int> arr = proper.makeVectorOfSomething(5);

    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}