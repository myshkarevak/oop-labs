#include "ClassTwo.cpp"

int main() {
    ClassOne objectOfClassOne(10, "test string");
    ClassTwo objectOfClassTwo(objectOfClassOne, 13.4);

    cout << "ObjectOfClassOne:" << endl;

    objectOfClassOne.print();

    cout << endl;

    cout << "ObjectOfClassTwo" << endl;

    objectOfClassTwo.print();

    cout << endl;

    system("pause");

    return 0;
}
