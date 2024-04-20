#include "geometry_objects.hpp"

Circle::Circle()
{
    cx = 0;
    cy = 0;
    d = 0;
}

Circle::Circle(double x, double y, double diameter, int id)
{
    this->id = id;
    cx = x;
    cy = y;
    d = diameter;
}

double Circle::get_min_distance(double x, double y) {
    double delta_x = cx - x;
    double delta_y = cy - y;
    return sqrt(delta_x * delta_x + delta_y * delta_y) - d / 2;
}

double Circle::get_min_distance(Circle & circle) {
    double delta_x = cx - circle.cx;
    double delta_y = cy - circle.cy;
    return sqrt(delta_x * delta_x + delta_y * delta_y) - d / 2 - circle.d / 2;
}

double Circle::get_min_distance(Line & line) {
    return line.get_min_distance(cx, cy) - d / 2;
}

double Circle::get_max_distance(double x, double y) {
    double delta_x = cx - x;
    double delta_y = cy - y;
    return sqrt(delta_x * delta_x + delta_y * delta_y) + d / 2;
}

double Circle::get_max_distance(Circle & circle) {
    double delta_x = cx - circle.cx;
    double delta_y = cy - circle.cy;
    return sqrt(delta_x * delta_x + delta_y * delta_y) + d / 2 + circle.d / 2;
}

double Circle::get_max_distance(Line & line) {
    return line.get_max_distance(cx, cy) + d / 2;
}

std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Circle #" << circle.id << " - Center: (" << circle.cx << ", " << circle.cy << "), Diameter: " << circle.d;
    return os;
}

Line::Line()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    width = 0;
}

Line::Line(double x1, double y1, double x2, double y2, double width, int id)
{
    this->id = id;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->width = width;
}

double Line::get_min_distance(double x, double y) {
    if ( // Determening if height of triangle is outside its base
        (x1 - x) * (x1 - x2) + (y1 - y) * (y1 - y2) < 0 ||
        (x2 - x) * (x2 - x1) + (y2 - y) * (y2 - y1) < 0
    )
    {
        double end_1_distance = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        double end_2_distance = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        return std::min(end_1_distance, end_2_distance) - width / 2;
    }
    else
    {
        double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double b = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
        double c = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's formula
        return s * 2 / a - width / 2;
    }
}

double Line::get_min_distance(Circle & circle)
{
    return circle.get_min_distance(*this);
}

double Line::get_min_distance(Line & line)
{
    double candidate_1 = get_min_distance(line.x1, line.y1);
    double candidate_2 = get_min_distance(line.x2, line.y2);
    double candidate_3 = line.get_min_distance(x1, y1);
    double candidate_4 = line.get_min_distance(x2, y2);

    return std::min(std::min(candidate_1, candidate_2), std::min(candidate_3, candidate_4)) - width / 2;
}

double Line::get_max_distance(double x, double y) {
    double end_1_distance = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    double end_2_distance = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    return std::max(end_1_distance, end_2_distance) + width / 2;
}

double Line::get_max_distance(Circle & circle)
{
    return circle.get_max_distance(*this);
}

double Line::get_max_distance(Line & line)
{
    double candidate_1 = get_max_distance(line.x1, line.y1);
    double candidate_2 = get_max_distance(line.x2, line.y2);
    double candidate_3 = line.get_max_distance(x1, y1);
    double candidate_4 = line.get_max_distance(x2, y2);

    return std::min(std::min(candidate_1, candidate_2), std::min(candidate_3, candidate_4)) + width / 2;
}

std::ostream& operator<<(std::ostream& os, const Line& line) {
    os << "Line #" << line.id << " - Start: (" << line.x1 << ", " << line.y1 << "), End: (" << line.x2 << ", " << line.y2 << "), Width: " << line.width;
    return os;
}
