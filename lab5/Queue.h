#ifndef QUEUE_H
#define QUEUE_H
//tail is pointing at the empty place

template <class T>
class Queue
{
public:
	virtual void enQueue(const T& e) = 0; // Добавление элемента
	virtual T deQueue() = 0; // Удаление и возвращение элемента
	virtual bool isEmpty() = 0; // Проверка на пустоту
	virtual ~Queue() {}
};

#endif // !QUEUE_H

