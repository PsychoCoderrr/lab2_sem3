#pragma once
#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"

template<typename T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* data;
public:
    ArraySequence()
    {
        this->data = new DynamicArray<T>();
    }
    ArraySequence(int size)
    {
        this->data = new DynamicArray<T>(size);
    }
    ArraySequence(T* items, int size)
    {
        this->data = new DynamicArray<T>(items, size);
    }
    
    ~ArraySequence()
    {
        delete data;
    }
    
    T GetFirst() const override
    {
        return (this->data)->Get(0);
    }
    T GetLast() const override 
    {
        return this->data->Get((this->data)->GetSize() - 1);
    }
    T Get(int index) const override
    {
        return this->data->Get(index);
    }
    int GetLength() const override
    {
        return this->data->GetSize();
    }
    
    void Append(const T &item) override
    {
        this->data->Resize(this->data->GetSize() + 1);
        this->data->Set(item, this->data->GetSize() - 1);
    }
    void Prepend(const T &item) override
    {
        this->data->Resize(this->data->GetSize() + 1);
        for (int i = this->data->GetSize() - 1; i > 1; i--)
        {
            this->data->Set(this->data->Get(i - 1), i);
            this->data->Set(0, item);
        }
    }
    
    T& operator[](int index) override
    {
        return (this->data)[index];
    }
};
