#include <iostream>
#include <stdexcept>
#include <type_traits>

using namespace std;

template <typename T>
class Fraction
{
    static_assert(is_arithmetic<T>::value, "Template parameter must be a numeric type.");

private:
    T numerator;
    T denominator;

    const T gcd(T numerator, T denominator)
    {
        while (denominator != 0)
        {
            const T temp = denominator;
            denominator = numerator % denominator;
            numerator = temp;
        }
        return numerator;
    }

    void reduce()
    {
        const T divisor = gcd(this->numerator, this->denominator);

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

    Fraction(const T numerator, const T denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Error: denominator cannot be zero!");
        }

        this->numerator = numerator;
        this->denominator = denominator;

        this->reduce();
    }

    Fraction operator+(const Fraction &fractionToAdd)
    {
        const T numerator = this->numerator * fractionToAdd.denominator + fractionToAdd.numerator * this->denominator;
        const T denominator = this->denominator * fractionToAdd.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator-(const Fraction &fractionToSubtract)
    {
        const T numerator = this->numerator * fractionToSubtract.denominator - fractionToSubtract.numerator * this->denominator;
        const T denominator = this->denominator * fractionToSubtract.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator*(const Fraction &fractionToMultiply)
    {
        const T numerator = this->numerator * fractionToMultiply.numerator;
        const T denominator = this->denominator * fractionToMultiply.denominator;

        return Fraction(numerator, denominator);
    }

    Fraction operator/(const Fraction &fractionToDivide)
    {
        if (fractionToDivide.numerator == 0)
        {
            throw domain_error("Error: division by zero!");
        }

        const T numerator = this->numerator * fractionToDivide.denominator;
        const T denominator = this->denominator * fractionToDivide.numerator;

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

    bool operator>(const Fraction &otherFraction)
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
        T numerator = 0, denominator = 0;

        cout << "Input numerator: ";
        input >> numerator;

        cout << "Input denominator: ";
        input >> denominator;

        if (denominator == 0)
        {
            throw invalid_argument("Error: denominator cannot be zero!");
        }

        currentFraction.numerator = numerator;
        currentFraction.denominator = denominator;

        currentFraction.reduce();

        return input;
    }
};
