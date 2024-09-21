#include <iostream>
using namespace std;

class ClassOne
{
private:
    int integerValue;
    string stringValue;

public:
    ClassOne()
    {
        this->integerValue = 0;
        this->stringValue = "";
    }

    ClassOne(int integerValue, string stringValue)
    {
        this->integerValue = integerValue;
        this->stringValue = stringValue;
    }

    ClassOne(const ClassOne &objectToCopy)
    {
        this->integerValue = objectToCopy.integerValue;
        this->stringValue = objectToCopy.stringValue;
    }

    void setIntegerValue(int integerValue)
    {
        this->integerValue = integerValue;
    }

    void setStringValue(string stringValue)
    {
        this->stringValue = stringValue;
    }

    int getIntegerValue()
    {
        return this->integerValue;
    }

    string getStringValue()
    {
        return this->stringValue;
    }

    ClassOne &operator=(const ClassOne &objectToCopy)
    {
        this->integerValue = objectToCopy.integerValue;
        this->stringValue = objectToCopy.stringValue;
        return *this;
    }

    void print()
    {
        cout << *this;
    }

    friend ostream &operator<<(ostream &output, const ClassOne &currentObject)
    {
        output << currentObject.integerValue << ", " << currentObject.stringValue;
        return output;
    }

    friend istream &operator>>(istream &input, ClassOne &currentObject)
    {
        int integerValue;
        string stringValue;

        cout << "Input integerValue: ";
        input >> integerValue;

        cout << "Input stringValue: ";
        input >> stringValue;

        currentObject.integerValue = integerValue;
        currentObject.stringValue = stringValue;

        return input;
    }
};