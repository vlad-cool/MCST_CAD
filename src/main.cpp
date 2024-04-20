#include <iostream>

#include <vector>

#include "geometry_objects.hpp"
#include "loader.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path> <distance>" << std::endl;
        return 1;
    }

    std::string path = argv[1];
    double distance = std::stod(argv[2]);

    std::vector<Circle> circles;
    std::vector<Line> lines;
    objects_from_json(path, circles, lines);

    std::cout << circles.size() << " " << lines.size() << std::endl;

    for (auto iter_c1 = circles.begin(); iter_c1 != circles.end(); iter_c1++)
    {
        for (auto iter_c2 = iter_c1 + 1; iter_c2 != circles.end(); iter_c2++)
        {
            double eval_dist = iter_c1->get_min_distance(*iter_c2);
            if (eval_dist >= 0 && eval_dist < distance)
                std::cout << "Distance between " << *iter_c1 << " and " << *iter_c2 << " is " << eval_dist << " < " << distance << std::endl;
        }
    }

    for (auto iter_c = circles.begin(); iter_c != circles.end(); iter_c++)
    {
        for (auto iter_l = lines.begin(); iter_l != lines.end(); iter_l++)
        {
            double eval_dist = iter_c->get_min_distance(*iter_l);
            if (eval_dist >= 0 && eval_dist < distance)
                std::cout << "Distance between " << *iter_c << " and " << *iter_l << " is " << eval_dist << " < " << distance << std::endl;
        }
    }
    
    for (auto iter_l1 = lines.begin(); iter_l1 != lines.end(); iter_l1++)
    {
        for (auto iter_l2 = iter_l1 + 1; iter_l2 != lines.end(); iter_l2++)
        {
            double eval_dist = iter_l1->get_min_distance(*iter_l2);
            if (eval_dist >= 0 && eval_dist < distance)
                std::cout << "Distance between " << *iter_l1 << " and " << *iter_l2 << " is " << eval_dist << " < " << distance << std::endl;
        }
    }
}