#pragma once
#include "Sequence.h"
template <typename T> class ArraySequence : public Sequence<T>
{
  private:
    T *elements = nullptr;
    int capacity;
    int size;

    void Reserve(int newCapacity)
    {
        if (newCapacity <= capacity)
        {
            capacity = newCapacity;
            return;
        }

        T *newElements = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        delete elements;
        elements = newElements;
        capacity = newCapacity;
    }

  public:
    ArraySequence() : size(0), capacity(0), elements(nullptr)
    {
    }

    ArraySequence(int size) : size(size), capacity(size + 1), elements(nullptr)
    {
        if (size <= 0)
        {
            throw std::out_of_range("invalid argument for size");
        }
        else
        {
            elements = new T[capacity];
        }
    }

    ArraySequence(T *items, int count) : ArraySequence(count)
    {
        if (items == nullptr)
        {
            throw std::out_of_range("invalid argument in elems for constructor");
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                elements[i] = items[i];
            }
        }
    }

    ArraySequence(const DynamicArray<T> &dynamicArray) : DynamicArray<T>(dynamicArray.elements, dynamicArray.size)
    {
    }

    ~ArraySequence()
    {
        delete[] elements;
    }
    T GetFirst() const override
    {
        return elements[0];
    }
    
    T GetLast() const override
    {
        return elements[size - 1];
    }
    
    T Get(int index) const override
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("invalid argument");
        }
        return elements[index];
    }
    
    int GetLength() const override
    {
        return size;
    }

    void Set(const T &value, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("invalid argument");
        }
        elements[index] = value;
    }

    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::invalid_argument("invalid argument");
        }
        if (newSize == 0)
        {
            delete[] elements;
            elements = nullptr;
        }
        if (newSize > capacity)
        {
            Reserve(newSize * 2);
        }
        size = newSize;
    }
    
    void Append(const T& item) override
    {
        this->Resize(this->GetLength() + 1);
        elements[this->GetLength() - 1] = item;
    }
    
    void Prepend(const T& item) override
    {
        this->Resize(this->GetLength() + 1);
        for (int i = this->GetLength(); i > 0; i--)
        {
            elements[i] = elements[i - 1];
        }
        elements[0] = item;
    }
    
    T &operator[](int index) override
    {
        if (size <= index)
        {
            throw std::out_of_range("Invalid argument");
        }
        return elements[index];
    }
    
    const T &operator[](int index) const
    {
        if (size <= index)
        {
            throw std::out_of_range("Invalid argument");
        }
        return elements[index];
    }

    bool operator==(const DynamicArray<T> &array)
    {
        if (array.size != size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (array[i] != elements[i])
            {
                return false;
            }
        }
        return true;
    }
};
