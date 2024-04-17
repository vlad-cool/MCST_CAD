#ifndef LOADER
#define LOADER

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "geometry_objects.hpp"

void objects_from_json(std::string path, std::vector<Circle> &circles, std::vector<Line> &lines);

#endif