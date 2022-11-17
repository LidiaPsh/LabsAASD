#include "SinglyOrderedList.h"

SinglyOrderedList::Node* SinglyOrderedList::searchNode(int k)
{
	Node* current = head_;
	while (current != nullptr && current->key_ != k) current = current->next_;
	return (current != nullptr && current->key_ == k) ? current : nullptr;
}

SinglyOrderedList::Node* SinglyOrderedList::successor(Node* x)
{
	Node* current = head_;
	while (current != nullptr && current->key_ < x->key_) current = current->next_;
	return current;
}

SinglyOrderedList::Node* SinglyOrderedList::predecessor(Node* x)
{
	Node* current = head_;
	Node* prev = nullptr;
	while (current != nullptr && current->key_ < x->key_) {
		prev = current;
		current = current->next_;
	}
	return (prev != nullptr && prev->key_ < x->key_) ? prev : nullptr;
}

SinglyOrderedList::SinglyOrderedList(SinglyOrderedList&& list1) noexcept
{
	head_ = list1.head_;
	list1.head_ = nullptr;
}
 
SinglyOrderedList& SinglyOrderedList::operator=(SinglyOrderedList&& list1) noexcept
{
	head_ = list1.head_;
	list1.head_ = nullptr;
	return *this;
}

bool SinglyOrderedList::search(int k)
{
	Node* current = head_;
	while (current != nullptr && current->key_ != k) current = current->next_;
	return (current != nullptr && current->key_ == k);
}

bool SinglyOrderedList::search(Node* x)
{
	if (x == nullptr) return false;
	Node* current = head_;
	while (current != nullptr && current != x) current = current->next_;
	return (current == x);
}

bool SinglyOrderedList::remove(Node* x)
{
	if (search(x->key_) == false) return false;
	if (head_ == nullptr) return false;
	Node* prev = predecessor(x);
	if (prev == nullptr) {
		prev = head_;
		head_ = head_->next_;
		delete prev;
		return true;
	}
	else {
		Node* temp = prev->next_;
		if(prev->next_ != nullptr) prev->next_ = (prev->next_)->next_;
		delete temp;
		return true;
	}
}

bool SinglyOrderedList::remove(int k)
{
	return remove(new Node(k));
}

bool SinglyOrderedList::insert(Node* x)
{
	if (search(x->key_) == true) return false;
	if (head_ == nullptr) 
	{
		head_ = x;
		return true;
	}
	else 
	{
		Node* prev = predecessor(x);
		if (prev == nullptr) 
		{
			x->next_ = head_;
			head_ = x;
			return true;
		}
		else 
		{
			x->next_ = prev->next_;
			prev->next_ = x;
			return true;
		}
	}
}

bool SinglyOrderedList::insert(int k)
{
	return insert(new Node(k));
}

void SinglyOrderedList::unite(SinglyOrderedList* list2)
{
	Node* current2 = list2->head_;
	Node* next = (current2 == nullptr) ? nullptr : current2->next_;
	while (current2 != nullptr) {
		if (!insert(current2)) {
			delete current2;
			current2 = next;
			next = (next == nullptr) ? nullptr : next->next_;
		}
		else {
			current2 = next;
			next = (next == nullptr) ? nullptr : next->next_;;
		}
	}
	list2->head_ = nullptr;
}
void SinglyOrderedList::exclude(const SinglyOrderedList* list2)
{
	Node* current2 = list2->head_;
	Node* next = (current2 == nullptr) ? nullptr : current2->next_;;
	while (current2 != nullptr) {
		remove(current2->key_);
		current2 = next; 
		next = (next == nullptr) ? nullptr : next->next_;;
	}
}

void SinglyOrderedList::out()
{
	Node* current = head_;
	while (current != nullptr) {
		std::cout << current->key_ << " ";
		current = current->next_;
	}
}

SinglyOrderedList* intersection(SinglyOrderedList& list1, SinglyOrderedList& list2)
{
	SinglyOrderedList* newList = new SinglyOrderedList();
	SinglyOrderedList::Node* current2 = list2.head_;
	while (current2 != nullptr) 
	{
		if (list1.search(current2->key_)) newList->insert(new SinglyOrderedList::Node(current2->key_));
		current2 = current2->next_;
	}
	return newList;
}

SinglyOrderedList::~SinglyOrderedList()
{
	Node* current(head_);
	Node* prev(nullptr);
	while (current != nullptr) {
		prev = current;
		current = current->next_;
		delete prev;
	}
	head_ = nullptr;
}
