#ifndef STACKARRAY_H
#define STACKARRAY_H

#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"
#include "Stack.h"
#include <iostream>

template<class T>
class StackArray : public Stack<T>
{
public:
    StackArray(size_t size = 100) 
    {
        if (size == 0) throw WrongStackSize();
        else
        {
            try {
                array_ = new T[size + 1];
                top_ = 0;
                size_ = size;
            }
            catch (std::bad_alloc) {
                throw std::bad_alloc();
            }
        }
    } // size задает размер стека "по умолчанию"
    StackArray(const StackArray<T>& src) = delete;// =
    StackArray(StackArray <T>&& src) {
        swap(*this, src);
    }
    StackArray& operator=(const StackArray <T>& src) = delete; // =
    StackArray& operator=(StackArray <T>&& src) {
        swap(src);
        return *this;
    }
    virtual ~StackArray() { delete[] array_; } //{ delete[] array_;
    void push(const T& e) {
        if (top_ == size_) throw StackOverflow();
        else array_[++top_] = e;
    }
    T pop() {
        if (isEmpty()) throw StackUnderflow();
        return array_[top_--];
    }
    bool isEmpty() { return top_ == 0; } // { return top_ == 0; }
private:
    T* array_;
    // массив элементов стека: стека:!!! array _[0] не используется, top _ от 1 до size _
    size_t top_; // вершина стека, элемент занесенный в стек последним
    size_t size_; // размер стека
    void swap(StackArray <T>& src) {
        std::swap(array_, src.array_); // this array_, src.array _)
        std::swap(top_, src.top_);
        std::swap(size_, src.size_);
    }
};

#endif // !STACKARRAY_H