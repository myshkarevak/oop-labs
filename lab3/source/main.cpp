#include "ClassThree.cpp"

int main()
{
     ClassOne objectOfClassOne(10, "test string");
     ClassTwo objectOfClassTwo(objectOfClassOne, 13.4);
     ClassThree objectOfClassThree(objectOfClassOne, 15.9, 11);

     cout << "ObjectOfClassOne: ";

     objectOfClassOne.print();

     cout << endl
          << endl;

     cout << "ObjectOfClassTwo: ";

     objectOfClassTwo.print();

     cout << endl
          << endl;

     cout << "ObjectOfClassThree: ";

     objectOfClassThree.print();

     cout << endl
          << endl;

     system("pause");

     return 0;
}
