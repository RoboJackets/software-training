#ifndef PROPER_STRUCTURE_H
#define PROPER_STRUCTURE_H

#include <vector>

namespace proper_structure
{

class ProperStructure
{
public:
    ProperStructure(int something);
    std::vector<int> makeVectorOfSomething(int length);
private:
    int something;
};

}

#endif