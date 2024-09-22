#include "ClassThree.cpp"

class ClassFour : public ClassThree
{
private:
    string extraString;

public:
    ClassFour() : ClassThree()
    {
        this->extraString = "";
    }

    ClassFour(const ClassOne &objectOfClassOne, const double doubleValue, const int extraValue, const string extraString)
        : ClassThree(objectOfClassOne, doubleValue, extraValue)
    {
        this->extraString = extraString;
    }

    ClassFour(const ClassFour &otherObject) : ClassThree(otherObject)
    {
        this->extraString = otherObject.extraString;
    }

    void setExtraString(const string extraString)
    {
        this->extraString = extraString;
    }

    string getExtraString()
    {
        return this->extraString;
    }

    virtual void print()
    {
        ClassThree::print();
        cout << ", " << this->extraString;
    }
};