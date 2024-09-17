#include <iostream>
#include "String.cpp"
using namespace std;

int main()
{
    String string1("Hello");
    String string2("World!");
    String string3 = string1 + " " + string2;
    String string4(string3);
    String string5("   |text to trim...|   ");
    String string6;

    string5.trim();

    cout << "Please input test string: ";
    cin >> string6;
   
    cout << "string1 (char *stringToCopy): " << string1 << endl;
    cout << "string2 (char *stringToCopy): " << string2 << endl;
    cout << "string3 (string1 + \" \" + string2): " << string3 << endl;
    cout << "string4 (String &string3): " << string4 << endl;
    cout << "string5 (   |text to trim...|   ) trim: " << string5 << endl;
    cout << "string6 (From cin): " << string6 << endl;
    cout << "substring of string4 (6 chars at index 6): " << string4.getSubstring(6, 6) << endl;

    string4.removeSubstring(6, 6);
    string4.insert(string6, 6);

    cout << "remove World! and insert string6 at position 6: " << string4 << endl;
    cout << "size of string4: " << string4.getSize() << endl;
    system("pause");

    return 0;
}