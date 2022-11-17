//#include "StackArray.h"
////template<class T>
////StackArray<T>::StackArray(size_t size)
////{
////	if (size == 0) throw WrongStackSize();
////	else 
////	{
////		try {
////			array_ = new T[size+1];
////			top_ = 0;
////			size_ = size;
////		}
////		catch (std::bad_alloc& e) {
////			throw std::bad_alloc();
////		}
////	}
////}
//
//template<class T>
//StackArray<T>::StackArray(StackArray<T>&& src)
//{
//	swap(*this, src);
//}
//
//template<class T>
//StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
//{
//	swap(*this, src);
//	return *this;
//}
//
//template<class T>
//StackArray<T>::~StackArray()
//{
//	delete[] array_;
//}
//
//template<class T>
//void StackArray<T>::push(const T& e)
//{
//	if (top_ == size_) throw StackOverflow();
//	array_[++top_] = e;
//}
//
//template<class T>
//T StackArray<T>::pop()
//{
//	if (isEmpty()) throw StackUnderflow();
//	return array_[top_--];
//}
//
//template<class T>
//bool StackArray<T>::isEmpty()
//{
//	return top_ == 0;
//}
//
//template<class T>
//void StackArray<T>::swap(StackArray<T>& src)
//{
//	std::swap(array_, src.array_); // this array_, src.array _)
//	std::swap(top_, src.top_);
//	std::swap(size_, src.size_);
//}
