#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    const int gcd(int numerator, int denominator)
    {
        while (denominator != 0)
        {
            const int temp = denominator;
            denominator = numerator % denominator;
            numerator = temp;
        }

        return numerator;
    }

    void reduce()
    {
        const int divisor = gcd(this->numerator, this->denominator);

        this->numerator /= divisor;
        this->denominator /= divisor;

        if (this->denominator < 0)
        {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
    }

public:
    Fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }

    Fraction(const int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;

        if (denominator == 0)
        {
            cerr << "Error: denominator cannot be zero! Using 1 instead..." << endl;
            denominator = 1;
        }

        this->reduce();
    }

    Fraction operator+(const Fraction &fractionToAdd)
    {
        const int numerator = this->numerator * fractionToAdd.denominator + fractionToAdd.numerator * this->denominator;
        const int denominator = this->denominator * fractionToAdd.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction &fractionToSubtract)
    {
        const int numerator = this->numerator * fractionToSubtract.denominator - fractionToSubtract.numerator * this->denominator;
        const int denominator = this->denominator * fractionToSubtract.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator*(const Fraction &fractionToMultiply)
    {
        const int numerator = this->numerator * fractionToMultiply.numerator;
        const int denominator = this->denominator * fractionToMultiply.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator/(const Fraction &fractionToDivide)
    {
        if (fractionToDivide.numerator == 0)
        {
            cerr << "Error: division by zero!" << std::endl;
            return Fraction(0, 1);
        }
        const int numerator = this->numerator * fractionToDivide.denominator;
        const int denominator = this->denominator * fractionToDivide.numerator;

        return Fraction(numerator, denominator);
    }

    bool operator==(const Fraction &otherFraction)
    {
        return this->numerator == otherFraction.numerator && this->denominator == otherFraction.denominator;
    }

    bool operator!=(const Fraction &otherFraction)
    {
        return !(*this == otherFraction);
    }

    bool operator<(const Fraction &otherFraction)
    {
        return this->numerator * otherFraction.denominator < otherFraction.numerator * this->denominator;
    }

    bool operator>(const Fraction &otherFraction) const
    {
        return this->numerator * otherFraction.denominator > otherFraction.numerator * this->denominator;
    }

    Fraction &operator=(const Fraction &otherFraction)
    {
        if (this == &otherFraction)
        {
            return *this;
        }

        this->numerator = otherFraction.numerator;
        this->denominator = otherFraction.denominator;

        this->reduce();

        return *this;
    }

    friend ostream &operator<<(ostream &output, const Fraction &currentFraction)
    {
        output << currentFraction.numerator << "/" << currentFraction.denominator;
        return output;
    }

    friend istream &operator>>(istream &input, Fraction &currentFraction)
    {
        int numerator = 0, denominator = 0;

        cout << "Input numerator: ";
        input >> numerator;

        cout << "Input denominator: ";
        input >> denominator;

        currentFraction.numerator = numerator;
        currentFraction.denominator = denominator;

        return input;
    }
};
