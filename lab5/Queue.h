#ifndef QUEUE_H
#define QUEUE_H
//tail is pointing at the empty place

template <class T>
class Queue
{
public:
	virtual void enQueue(const T& e) = 0; // ���������� ��������
	virtual T deQueue() = 0; // �������� � ����������� ��������
	virtual bool isEmpty() = 0; // �������� �� �������
	virtual ~Queue() {}
};

#endif // !QUEUE_H

