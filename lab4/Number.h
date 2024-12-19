#ifndef NUMBER_H
#define NUMBER_H

class Number {
protected:
    double value;
public:
    Number(double val = 0.0);
    double getValue() const;
    void setValue(double val);

    double multiply(double other) const;
    double subtract(double other) const;
};

#endif // NUMBER_H