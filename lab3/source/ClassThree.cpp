#include "ClassTwo.cpp"

class ClassThree : public ClassTwo
{
private:
    int extraValue;

public:
    ClassThree() : ClassTwo()
    {
        this->extraValue = 0;
    }

    ClassThree(const ClassOne &objectOfClassOne, const double doubleValue, const int extraValue)
        : ClassTwo(objectOfClassOne, doubleValue)
    {
        this->extraValue = extraValue;
    }

    ClassThree(const ClassThree &otherObject) : ClassTwo(otherObject)
    {
        this->extraValue = otherObject.extraValue;
    }

    void setExtraValue(const int extraValue)
    {
        this->extraValue = extraValue;
    }

    int getExtraValue()
    {
        return this->extraValue;
    }

    virtual void print()
    {
        ClassTwo::print();
        cout << ", " << this->extraValue;
    }
};