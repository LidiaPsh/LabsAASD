#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - ������ ������� ������ ����� ����� - ���������� ������� ������  
//
#include <iostream>

// ����������� "�� ���������" - �������� ������� ������ - ��. �������� ������
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

void DoubleLinkedList::swap(DoubleLinkedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}

// ����������� "�����������" � �������� ����� ���������� ������
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& src)
{
	count_ = src.count_;
	if (count_ == 0) {
		head_ = nullptr;
		tail_ = nullptr;
		return;
	}
	head_ = new Node(src.head_->item_);
	Node* current_left = head_;
	Node* current_right = src.head_;
	for (int i = 0; i < count_-1; i++) {
		current_left->next_ = new Node(current_right->next_->item_);
		current_left->next_->prev_ = current_left;
		current_left = current_left->next_;
		current_right = current_right->next_;
	}
	tail_ = current_left;
}

// �������� ������������ (���������� ������������)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp ����� right ��������
		swap(temp);        // ������ this ����� right, � temp ����� this
	}                    // �������� temp c ������� ������� this
	return *this;
}

// ����������� ����������� 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// �������� ������������� ������������ 
DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& right) noexcept 
{
	if (this != &right) {
		swap(right);
	}
	return *this;
}

bool DoubleLinkedList::operator==(DoubleLinkedList& right)
{
	if(count_ != right.count_) return false;
	if (count_ == 0 && right.count_ == 0) return true;
	Node* current_left = head_;
	Node* current_right = right.head_;
	while (current_left->item_ == current_right->item_ && current_left->next_ != nullptr) {
		current_left = current_left->next_;
		current_right = current_right->next_;
	}
	return current_left->item_ == current_right->item_;
}


// ���������� ��������������� ���� � ����� ������
void DoubleLinkedList::insertTail(Node* x)
{
	
	if (tail_ == nullptr)
	{
		head_ = x;
		tail_ = x;
	}
	else {
		tail_->next_ = x;
		x->prev_ = tail_;
		tail_ = x;
	}
	count_++;
}

// ���������� ��������������� ���� � ������ ������
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// ������ ��� �� ���� � ����� ������� �� ����� � ������, � ���������
		head_->prev_ = x;
	}
	else {
		// ������ ��� ���� � ����� ������� ����� � ������, � ���������
		tail_ = x;
	}
	head_ = x;
	count_++;  // ����� ��������� ������ �����������
}

// �������� ��������� ���� 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - ������� ����� ����� ���������� ����");
	}
	if (x->prev_ != nullptr) {
		// ��������� �� ������ ������
		(x->prev_)->next_ = x->next_;
	}
	else {
		// ��������� ������ ������,  ������ ������� ���������� ������
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// ��������� �� �����
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// ��������� �����
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // ����� ��������� ������ �����������
}

// ����� ���� (�����) � �������� ���������  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// ������ ���������� ���� �� ����� 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x; // !!!!!
}

// ���������� ��������� ������
//int DoubleLinkedList::count() const { return count_; }
// ������ � ���������� ��������� ���� ������
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - ������ ����!");
}

// ������ � ���������� ���������� ���� ������
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - ������ ����!");
}

// ���������� �������� � ������ ������
void DoubleLinkedList::insertHead(int item)
{   // ������� ����� ������� ������ � ��������� � ������ 
	insertHead(new Node(item));
}


// ���������� �������� � ����� ������
void DoubleLinkedList::insertTail(int item)
{   // ������� ����� ������� ������ � ��������� � ����� 
	insertTail(new Node(item));
}

// �������� �������� � ������ ������
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // ������ ����, �������� ���
	}
	deleteNode(head_);
	return 1;      // ������ ��� �� ����, �������� ������
}

// �������� �������� �� ������ ������
bool DoubleLinkedList::deleteTail()
{
	if (count_ == 0) {
		return 0;
	}
	deleteNode(tail_);
	return 1;
}

// �������� ���� � �������� ���������  
bool DoubleLinkedList::deleteItem(const int item, bool all)
{
	int nDeleted(0);
	if (count_ == 0) return 0;
	if (all == false)
	{
		Node* current = head_;
		while (current->item_ != item && current->next_ != nullptr) current = current->next_;
		if (current->item_ != item) return 0;
		else {
			deleteNode(current);
			nDeleted++;
		}
	}
	else {
		Node* current = head_;
		Node* temp = head_;
		while (current->next_ != nullptr) {
			if (current->item_ == item) {
				temp = current;
				current = current->next_;
				deleteNode(temp);
				nDeleted++;
			}
		}
		if (current->item_ == item) {
			deleteTail();
			nDeleted++;
		}
	} return nDeleted > 0;
}

// ����� ������ � �������� ���������  
bool DoubleLinkedList::searchItem(int item)
{   // ���������� TRUE, ���� ���� ������ 
	return (searchNode(item) != nullptr);
}


// ������ ���������� ���� �� ����� 
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew, bool all)
{
	if (count_ == 0) return 0;
	int nChanged(0);
	if (all == false) {
		Node* current = head_;
		while (current->item_ != itemOld && current->next_ != nullptr) current = current->next_;
		if (current->item_ != itemOld) return 0;
		else current->item_ = itemNew;
		return 1;
	}
	else {
		Node* current = head_;
		while (current->next_ != nullptr) {
			if (current->item_ == itemOld) {
				current->item_ = itemNew;
				nChanged++;
			}
			current = current->next_;
		}
		if (current->item_ == itemOld) {
			current->item_ = itemNew;
			nChanged++;
		}
	}
	return nChanged > 0;
}

// ����� ��������� ������ � ��������� ���� � ����������� �������� ����� 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // ��������� �� �������
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // ������� � ���������� ��������
	}
	std::cout << std::endl;
}

void DoubleLinkedList::add(DoubleLinkedList& list)
{
	if (list.count_ == 0) return;
	if (count_ == 0) {
		head_ = list.head_;
		tail_ = list.tail_;
		count_ = list.count_;
	}
	else {
		tail_->next_ = list.head_;
		list.head_->prev_ = tail_;
		tail_ = list.tail_;
		count_ += list.count_;
	}
	list.head_ = nullptr;
	list.tail_ = nullptr;
	list.count_ = 0;
}

// ���������� ������	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // ��������� �� �������, ���������� ��������
	Node* next = head_;        // ��������� �� ��������� �������
	while (next != nullptr) {  // ���� ���� ��� �������� � ������
		current = next;
		next = next->next_;    // ������� � ���������� ��������
		delete current;        // ������������ ������
	}
}

std::ostream& operator<<(std::ostream& out, const DoubleLinkedList& list)
{
	DoubleLinkedList::Node* current = list.head_;
	while (current != nullptr) {
		out << current->item_ << ' ';
		current = current->next_; 
	}
	return out;
}
