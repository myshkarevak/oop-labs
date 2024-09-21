#include <iostream>
using namespace std;

#define MAX_STRING_BUFFER 100
#define SPACE_SYMBOL ' '
#define END_OF_LINE '\0'

class String
{
private:
    char *data;
    int length;

public:
    String()
    {
        this->data = new char[1];
        this->data[0] = END_OF_LINE;
        this->length = 0;
    }

    String(const String &stringToCopy)
    {
        this->length = stringToCopy.length;
        this->data = new char[this->length + 1];

        for (int i = 0; i < this->length; i++)
        {
            this->data[i] = stringToCopy.data[i];
        }

        this->data[length] = END_OF_LINE;
    }

    String(const char *stringToCopy)
    {
        if (!stringToCopy)
        {
            this->data = new char[1];
            this->data[0] = END_OF_LINE;
            this->length = 0;

            return;
        }

        this->length = 0;

        while (stringToCopy[this->length] != END_OF_LINE)
        {
            this->length++;
        }

        this->data = new char[this->length + 1];

        for (int i = 0; i < this->length; i++)
        {
            this->data[i] = stringToCopy[i];
        }

        this->data[this->length] = END_OF_LINE;
    }

    ~String()
    {
        delete[] this->data;
    }

    String &operator=(const String &stringToCopy)
    {
        if (this == &stringToCopy)
        {
            return *this;
        }

        delete[] this->data;

        this->length = stringToCopy.length;
        this->data = new char[stringToCopy.length + 1];

        for (int i = 0; i < this->length; i++)
        {
            this->data[i] = stringToCopy.data[i];
        }

        this->data[length] = END_OF_LINE;

        return *this;
    }

    String operator+(const String &stringToAdd)
    {
        String resultString;

        resultString.length = this->length + stringToAdd.length;
        resultString.data = new char[resultString.length + 1];

        for (int i = 0; i < this->length; i++)
        {
            resultString.data[i] = this->data[i];
        }

        for (int i = 0; i < stringToAdd.length; i++)
        {
            resultString.data[this->length + i] = stringToAdd.data[i];
        }

        resultString.data[resultString.length] = END_OF_LINE;

        return resultString;
    }

    String getSubstring(const int index, const int count)
    {
        if (index < 0 || index >= length || count <= 0 || index + count > length)
        {
            return String();
        }

        String resultString;

        resultString.length = count;
        resultString.data = new char[count + 1];

        for (int i = 0; i < count; i++)
        {
            resultString.data[i] = this->data[index + i];
        }

        resultString.data[count] = END_OF_LINE;

        return resultString;
    }

    void removeSubstring(const int index, const int count)
    {
        if (index < 0 || index >= length || count < 0 || index + count > length)
        {
            return;
        }

        int newLength = length - count;
        char *newData = new char[newLength + 1];

        for (int i = 0; i < index; i++)
        {
            newData[i] = this->data[i];
        }

        for (int i = index; i < newLength; i++)
        {
            newData[i] = this->data[i + count];
        }

        newData[newLength] = END_OF_LINE;

        delete[] this->data;

        this->data = newData;
        this->length = newLength;
    }

    void insert(const char *stringToInsert, const int index)
    {
        if (index < 0 || index > length)
        {
            return;
        }

        int insertLength = 0;

        while (stringToInsert[insertLength] != END_OF_LINE)
        {
            insertLength++;
        }

        int newLength = length + insertLength;
        char *newData = new char[newLength + 1];

        for (int i = 0; i < index; i++)
        {
            newData[i] = this->data[i];
        }

        for (int i = 0; i < insertLength; i++)
        {
            newData[index + i] = stringToInsert[i];
        }

        for (int i = index; i < length; i++)
        {
            newData[insertLength + i] = this->data[i];
        }

        newData[newLength] = END_OF_LINE;

        delete[] this->data;

        this->data = newData;
        this->length = newLength;
    }

    void insert(const String stringToInsert, const int index)
    {
        this->insert(stringToInsert.data, index);
    }

    void trim()
    {
        int start = 0;

        while (this->data[start] == SPACE_SYMBOL && start < length)
        {
            start++;
        }

        int end = length - 1;

        while (this->data[end] == SPACE_SYMBOL && end >= start)
        {
            end--;
        }

        int newLength = end - start + 1;
        char *newData = new char[newLength + 1];

        for (int i = 0; i < newLength; i++)
        {
            newData[i] = this->data[start + i];
        }

        newData[newLength] = END_OF_LINE;

        delete[] this->data;

        this->data = newData;
        this->length = newLength;
    }

    const int getSize()
    {
        return this->length;
    }

    friend ostream &operator<<(ostream &output, const String &currentString)
    {
        output << currentString.data;
        return output;
    }

    friend istream &operator>>(istream &input, String &currentString)
    {
        delete[] currentString.data;

        char buffer[MAX_STRING_BUFFER];

        input >> buffer;

        currentString.length = 0;

        while (buffer[currentString.length] != END_OF_LINE)
        {
            currentString.length++;
        }

        currentString.data = new char[currentString.length + 1];

        for (size_t i = 0; i < currentString.length; i++)
        {
            currentString.data[i] = buffer[i];
        }

        currentString.data[currentString.length] = END_OF_LINE;

        return input;
    }
};
