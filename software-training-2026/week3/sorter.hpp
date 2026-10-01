#pragma once

#include <vector>

#include "robot.hpp"

namespace sort
{
class Sorter {
public:
    virtual ~Sorter() {}

    virtual std::vector<Robot> sort(std::vector<Robot>) = 0;
};
} // namespace sort
