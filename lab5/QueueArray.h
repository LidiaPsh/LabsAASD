#include "QueueOverflow.h"
#include "WrongQueueSize.h"
#include "QueueUnderflow.h"
#include "UsingBeforeInit.h"
#include "Queue.h"
#include <iostream>

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

template<class T>
class QueueArray :
    public Queue<T>
{
public:
    QueueArray() : array_(nullptr), head_(0), tail_(0), size_(0) {};
    QueueArray(size_t size = 100);
    QueueArray(QueueArray<T>& a) = delete;
    QueueArray(QueueArray<T>&& x);
    QueueArray& operator=(QueueArray<T>& a) = delete;
    QueueArray& operator=(QueueArray<T>&& x);
    void enQueue(const T& e);
    T deQueue();
    virtual ~QueueArray();
    bool isEmpty();
private:
    T* array_;
    size_t head_;
    size_t tail_;
    size_t size_;
};

template<class T>
inline QueueArray<T>::QueueArray(size_t size)
{
    if (size == 0) throw WrongQueueSize();
    array_ = new T[size + 1];
    head_ = 0;
    tail_ = 0;
    size_ = size;
}

template<class T>
inline QueueArray<T>::QueueArray(QueueArray<T>&& x)
{
    array_ = x.array_;
    head_ = x.head_;
    tail_ = x.tail_;
    size_ = x.size_;
    x.array_ = nullptr;
}

template<class T>
inline QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& x)
{
    array_ = x.array_;
    head_ = x.head_;
    tail_ = x.tail_;
    size_ = x.size_;
    x.array_ = nullptr;
    return *this;
    // TODO: вставьте здесь оператор return
}

template<class T>
inline void QueueArray<T>::enQueue(const T& e)
{
    if ((tail_ + 1)%(size_+1) == head_) throw QueueOverflow();
    array_[tail_] = e;
    tail_ = (tail_ + 1) % (size_ + 1);
}

template<class T>
inline T QueueArray<T>::deQueue()
{
    if (head_ == tail_) throw QueueUnderflow();
    T temp = array_[head_];
    head_ = (head_ + 1) % (size_ + 1);
    return temp;
}

template<class T>
inline QueueArray<T>::~QueueArray()
{
    if (array_ != nullptr) delete[] array_;
}

template<class T>
inline bool QueueArray<T>::isEmpty()
{
    if (head_ == tail_) return true;
    return false;
}

#endif // !QUEUEARRAY_H
