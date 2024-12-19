#ifndef REAL_H
#define REAL_H

#include "Number.h"
//#include <cmath>

class Real : public Number {
public:
    Real(double val = 0.0);
    double root(double degree) const;
    double power(double exponent) const;
};

#endif // REAL_H