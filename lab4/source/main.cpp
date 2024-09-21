#include "ClassFour.cpp"

void printAll(ClassTwo **classesObjects, int length)
{
     for (int i = 0; i < length; i++)
     {
          classesObjects[i]->print();
          cout << endl
               << endl;
     }
}

int main()
{
     ClassOne objectOfClassOne(10, "test string");
     ClassTwo objectOfClassTwo(objectOfClassOne, 13.4);
     ClassThree objectOfClassThree(objectOfClassOne, 15.9, 11);
     ClassFour objectOfClassFour(objectOfClassOne, 17.12, 23, "Some string");

     ClassTwo *classesObjects[] = {&objectOfClassTwo, &objectOfClassThree, &objectOfClassFour};

     printAll(classesObjects, 3);

     system("pause");

     return 0;
}
