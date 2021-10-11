#ifndef FRACTION_H_
#define FRACTION_H_

class fraction {

    private:
        int numerator;
        int denominator;

    public:
        fraction(int n, int d);

        void add(fraction f);
        void mult(fraction f);
        void div(fraction f);

        void display(void);
};

#endif
