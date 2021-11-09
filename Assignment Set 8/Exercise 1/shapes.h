#ifndef SHAPES_H_
#define SHAPES_H_

class Shape {

    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual double height() = 0;
        virtual double width() = 0;
        virtual void rotate() = 0;
};

class Rectangle : public Shape {
    protected:
        double h, w;
    
    public: 
        Rectangle(double h, double w);
        double area();
        double perimeter();
        double height();
        double width();
        void rotate();
};

class Square : public Rectangle {
    public:
        Square(double lengthOfSides);
};

class Circle : public Shape {
    private:
        double radius;
    
    public: 
        Circle(double radius);
        double area();
        double perimeter();
        double height();
        double width();
        void rotate();
};

#endif