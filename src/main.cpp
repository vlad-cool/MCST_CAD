#include <iostream>

#include <vector>

#include "geometry_objects.hpp"
#include "loader.hpp"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <path> <x> <y> <distance>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    double x = std::stod(argv[2]);
    double y = std::stod(argv[3]);
    double distance = std::stod(argv[4]);

    std::vector<Circle> circles;
    std::vector<Line> lines;
    objects_from_json(path, circles, lines);

    for (auto iter = circles.begin(); iter != circles.end(); iter++)
    {
        if (iter->get_min_distance(x, y) < distance)
            std::cout << *iter << std::endl;
    }

    for (auto iter = lines.begin(); iter != lines.end(); iter++)
    {
        if (iter->get_min_distance(x, y) < distance)
            std::cout << *iter << std::endl;
    }
}