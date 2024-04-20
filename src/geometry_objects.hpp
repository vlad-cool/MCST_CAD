#ifndef GEOMETRY_OBJECTS
#define GEOMETRY_OBJECTS

#include <cmath>
#include <ostream>

class Circle;
class Line;

class Circle
{
private:
    double cx, cy, d;
    int id;
public:
    Circle();
    Circle(double x, double y, double d, int id);
    double get_min_distance(double x, double y);
    double get_min_distance(Circle & circle);
    double get_min_distance(Line & line);
    double get_max_distance(double x, double y);
    double get_max_distance(Circle & circle);
    double get_max_distance(Line & line);
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
};

class Line
{
private:
    double x1, y1, x2, y2, width;
    int id;
public:
    Line();
    Line(double x1, double y1, double x2, double y2, double width, int id);
    double get_min_distance(double x, double y);
    double get_min_distance(Circle & circle);
    double get_min_distance(Line & line);
    double get_max_distance(double x, double y);
    double get_max_distance(Circle & circle);
    double get_max_distance(Line & line);
    friend std::ostream& operator<<(std::ostream& os, const Line& line);
};

#endif
