#include "Fraction.cpp"
#include "DynamicArray.cpp"

int main()
{
    try
    {
        Fraction<int> fraction1(3, 4);
        Fraction<int> fraction2(5, 6);
        Fraction<int> fraction3;
        Fraction<int> result = fraction1 + fraction2;

        cout << "f1 + f2 = " << result << endl;
        cout << "Enter Fraction3: ";
        cin >> fraction3;
        cout << "\nYou entered: " << fraction3 << endl;

        system("pause");

        DynamicArray<int> array;

        array.push(10);
        array.push(20);
        array.push(30);

        cout << "Array elements: ";
        array.print();

        array.insert(1, 15);

        cout << "After insertion (index: 1, value: 15): ";
        array.print();

        array.remove(2);

        cout << "After removal(index: 2): ";
        array.print();

        array.pop();

        cout << "After pop: ";
        array.print();

        system("pause");
    }
    catch (const exception &exception)
    {
        cerr << exception.what() << endl;
    }

    return 0;
}
