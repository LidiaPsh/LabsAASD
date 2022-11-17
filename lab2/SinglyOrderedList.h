#include<iostream>
#ifndef SINGLYORDEREDLIST_H
#define SINGLYORDEREDLIST_H
class SinglyOrderedList
{
private:
	struct Node // может использоваться только в классе SinglyOrderedList
	{
		int key_; // значение элемента списка (
		Node* next_; // указатель на следующий элемент списка
		Node(int key, Node* next = nullptr) :key_(key), next_(next) {}
	};
	Node* head_;

	Node* searchNode(int k);
	//Ближайший превышающий x ключ
	//Возвращаемое значение Node*
	Node* successor(Node* x);
	//Ближайший меньший x ключ
	//Возвращаемое значение Node*
	Node* predecessor(Node* x);
	bool search(Node* x);
	bool remove(Node* x);
	bool insert(Node* x);

public:
	//int getHeadItem();
	SinglyOrderedList() : head_(nullptr) {}
	SinglyOrderedList(SinglyOrderedList&& list1) noexcept;
	SinglyOrderedList& operator=(SinglyOrderedList&& list1) noexcept;
	bool search(int k);
	bool remove(int k);
	bool insert(int k);
	void unite(SinglyOrderedList* list2);
	void exclude(const SinglyOrderedList* list2);
	void out();
	friend SinglyOrderedList* intersection(SinglyOrderedList& list1, SinglyOrderedList& list2);
	~SinglyOrderedList();
};
#endif
