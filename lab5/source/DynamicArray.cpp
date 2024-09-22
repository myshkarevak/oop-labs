#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray
{
private:
    T *data;
    int size;
    int capacity;

    void resize(const int newCapacity)
    {
        T *newData = new T[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        this->data = newData;
        this->capacity = newCapacity;
    }

public:
    DynamicArray()
    {
        this->size = 0;
        this->capacity = 1;
        this->data = new T[this->capacity];
    }

    DynamicArray(const int initialSize)
    {
        this->size = 0;
        this->capacity = initialSize;
        this->data = new T[capacity];
    }

    DynamicArray(const DynamicArray &arrayToCopy)
    {
        this->size = arrayToCopy.size;
        this->capacity = arrayToCopy.capacity;

        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = arrayToCopy[i];
        }
    }

    ~DynamicArray()
    {
        delete[] this->data;
    }

    int getSize()
    {
        return this->size;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    void push(const T &value)
    {
        if (size == capacity)
        {
            resize(capacity++);
        }

        data[size++] = value;
    }

    void pop()
    {
        if (size > 0)
        {
            --this->size;
        }
        else
        {
            throw out_of_range("Array is empty, cannot pop element.");
        }
    }

    T &operator[](const int index)
    {
        if (index >= this->size)
        {
            throw out_of_range("Index out of range.");
        }

        return this->data[index];
    }

    void insert(const int index, const T &value)
    {
        if (index > this->size)
        {
            throw out_of_range("Index out of range.");
        }

        if (this->size == this->capacity)
        {
            resize(capacity++);
        }

        for (int i = size; i > index; --i)
        {
            data[i] = data[i - 1];
        }

        this->data[index] = value;
        this->size++;
    }

    void remove(const int index)
    {
        if (index >= this->size)
        {
            throw out_of_range("Index out of range.");
        }

        for (int i = index; i < this->size - 1; i++)
        {
            this->data[i] = this->data[i + 1];
        }

        this->size--;
    }

    void clear()
    {
        this->size = 0;
        this->capacity = 1;
        this->data = new T[this->capacity];
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};
