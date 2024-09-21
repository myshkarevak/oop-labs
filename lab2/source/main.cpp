#include "ClassTwo.cpp"

int main()
{
    ClassOne objectOfClassOne(10, "test string");
    ClassTwo objectOfClassTwo(objectOfClassOne, 13.4);

    cout << "ObjectOfClassOne: ";

    objectOfClassOne.print();

    cout << endl
         << endl;

    cout << "ObjectOfClassTwo: ";

    objectOfClassTwo.print();

    cout << endl
         << endl;

    system("pause");

    return 0;
}
