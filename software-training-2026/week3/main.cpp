#include <vector>
#include <iostream>

#include "robot.hpp"
#include "sorter.hpp"

int main() {
    std::vector<Robot> robots = {
        {2, 1.4, "apple"},
        {0, 2.2, "pineapple"},
        {5, 1.9, "mango"},
        {4, 2.8, "banana"},
        {1, 2.4, "circle"},
        {3, 1.7, "apple"},
    };

    std::cout << "Unsorted Robots:\n";
    for (const auto& robot : robots) {
        std::cout << "Robot{id=" << robot.robot_id << ", weight=" << robot.weight << ", name=" << robot.name << "}\n";
    }

    sort::Sorter sorter;
    robots = sorter.sort(robots);

    std::cout << "Sorted Robots:\n";
    for (const auto& robot : robots) {
        std::cout << "Robot{id=" << robot.robot_id << ", weight=" << robot.weight << ", name=" << robot.name << "}\n";
    }
}
