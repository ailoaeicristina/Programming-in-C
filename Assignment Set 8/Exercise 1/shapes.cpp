#include "shapes.h"
#include <math.h>
using namespace std;

Rectangle::Rectangle(double h, double w) {
    this->h = h;
    this->w = w;
}

double Rectangle::area() {
    return this->h * this->w;
}

double Rectangle::perimeter() {
    return 2*(this->h + this->w);
}

double Rectangle::height() {
    return this->h;
}

double Rectangle::width() {
    return this->w;
}

void Rectangle::rotate() {
    double temp = this->h;
    this->h = this->w;
    this->w = temp;
}

Square::Square(double lengthOfSides) : Rectangle(lengthOfSides, lengthOfSides) { }

Circle::Circle(double radius) {
    this->radius = radius;
}

double Circle::area() {
    return M_PI * pow(this->radius, 2);
}

double Circle::perimeter() {
    return 2 * M_PI * this->radius;
}

double Circle::height() {
    return 2 *  this->radius;
}

double Circle::width() {
    return 2 *  this->radius;
}

void Circle::rotate() {

}