#include "loader.hpp"

void objects_from_json(std::string path, std::vector<Circle> &circles, std::vector<Line> &lines)
{
    std::ifstream data_file(path, std::ifstream::binary);
    if (data_file.is_open())
    {
        nlohmann::json data;
        data_file >> data;
        data_file.close();

        for (auto iter = data["Base"]["Objects map"].begin(); iter != data["Base"]["Objects map"].end(); iter++)
        {
            if (iter.key().size() >= 6 && iter.key().compare(0, 6, "Circle") == 0)
            {
                circles.push_back(Circle(std::stod(iter.value()["X"].dump()), std::stod(iter.value()["Y"].dump()), std::stod(iter.value()["Diameter"].dump()), std::stoi(iter.value()["Id"].dump())));
                continue;
            }
            if (iter.key().size() >= 4 && iter.key().compare(0, 4, "Line") == 0)
            {
                lines.push_back(Line(std::stod(iter.value()["X1"].dump()), std::stod(iter.value()["Y1"].dump()), std::stod(iter.value()["X2"].dump()), std::stod(iter.value()["Y2"].dump()), std::stod(iter.value()["Linewidth"].dump()), std::stoi(iter.value()["Id"].dump())));
                continue;
            }
        }
    }
    else
    {
        std::cerr << "Failed to open the file: " << path << std::endl;
    }
}
