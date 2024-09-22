#include <iostream>
#include "ClassOne.cpp"
using namespace std;

class ClassTwo
{
private:
    ClassOne *objectOfClassOnePointer;
    double doubleValue;

public:
    ClassTwo()
    {
        this->objectOfClassOnePointer = new ClassOne();
        this->doubleValue = 0.0;
    }

    ClassTwo(const ClassOne &objectOfClassOne, const double doubleValue)
    {
        this->objectOfClassOnePointer = new ClassOne(objectOfClassOne);
        this->doubleValue = doubleValue;
    }

    ClassTwo(const ClassTwo &otheObject)
    {
        this->objectOfClassOnePointer = new ClassOne(*otheObject.objectOfClassOnePointer);
        this->doubleValue = otheObject.doubleValue;
    }

    ~ClassTwo()
    {
        delete this->objectOfClassOnePointer;
    }

    void setObjectOfClassOnePointer(const ClassOne &objectOfClassOnePointer)
    {
        this->objectOfClassOnePointer = new ClassOne(objectOfClassOnePointer);
    }

    void setDoubleValue(const double doubleValue)
    {
        this->doubleValue = doubleValue;
    }

    ClassOne *getObjectOfClassOnePointer()
    {
        return this->objectOfClassOnePointer;
    }

    double getDoubleValue()
    {
        return this->doubleValue;
    }

    ClassTwo &operator=(const ClassTwo &objectToCopy)
    {
        this->objectOfClassOnePointer = new ClassOne(*objectToCopy.objectOfClassOnePointer);
        this->doubleValue = objectToCopy.doubleValue;
        return *this;
    }

    virtual void print()
    {
        cout << *this;
    }

    friend ostream &operator<<(ostream &output, const ClassTwo &currentObject)
    {
        output << *currentObject.objectOfClassOnePointer << ", " << currentObject.doubleValue;
        return output;
    }

    friend istream &operator>>(istream &input, ClassTwo &currentObject)
    {
        double doubleValue;
        ClassOne objectOfClassOne;

        cout << "Input ClassOneObject: ";
        input >> objectOfClassOne;

        cout << "Input doubleValue: ";
        input >> doubleValue;

        currentObject.objectOfClassOnePointer = &objectOfClassOne;
        currentObject.doubleValue = doubleValue;

        return input;
    }
};