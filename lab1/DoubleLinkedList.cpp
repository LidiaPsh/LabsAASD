#include "DoubleLinkedList.h"
#include "DoubleLinkedList.h"
//  DoubleLinkedList.cpp - Дважды связный список целых чисел - реализация методов класса  
//
#include <iostream>

// Конструктор "по умолчанию" - создание пустого списка - см. Описание класса
// DoubleLinkedList::DoubleLinkedList(): count_(0), head_(nullptr), tail_(nullptr) {  }

void DoubleLinkedList::swap(DoubleLinkedList& other) noexcept
{
	std::swap(head_, other.head_);
	std::swap(tail_, other.tail_);
	std::swap(count_, other.count_);
}

// Конструктор "копирования" – создание копии имеющегося списка
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

// Оператор присваивания (копирующее присваивание)
DoubleLinkedList & DoubleLinkedList ::operator=(const DoubleLinkedList& right)
{
	if (this != &right) {
		DoubleLinkedList temp(right); // temp копия right операнда
		swap(temp);        // теперь this копия right, а temp копия this
	}                    // удаление temp c данными старого this
	return *this;
}

// Конструктор перемещения 
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept:
	head_(other.head_),
	tail_(other.tail_),
	count_(other.count_)
{
	other.head_ = nullptr;
	other.tail_ = nullptr;
	other.count_ = 0;
}

// Оператор перемещающего присваивания 
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


// Добавление сформированного узла в хвост списка
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

// Добавление сформированного узла в начало списка
void DoubleLinkedList::insertHead(Node* x)
{   // x->prev_ == nullptr,  x->next_ == nullptr  
	x->next_ = head_;
	if (head_ != nullptr) {
		// список был НЕ пуст – новый элемент НЕ будет и первым, и последним
		head_->prev_ = x;
	}
	else {
		// список был пуст – новый элемент будет и первым, и последним
		tail_ = x;
	}
	head_ = x;
	count_++;  // число элементов списка увеличилось
}

// Удаление заданного узла 
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  - неверно задан адрес удаляемого узла");
	}
	if (x->prev_ != nullptr) {
		// удаляется НЕ голова списка
		(x->prev_)->next_ = x->next_;
	}
	else {
		// удаляется голова списка,  второй элемент становится первым
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		// удаляется НЕ хвост
		(x->next_)->prev_ = x->prev_;
	}
	else {
		// удаляется хвост
		tail_ = x->prev_;
	}
	delete x;      // 
	count_--;     // число элементов списка уменьшилось
}

// Поиск узла (адрес) с заданным значением  
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}

// Замена информации узла на новое 
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	x->item_ = item;
	return x; // !!!!!
}

// количество элементов списка
//int DoubleLinkedList::count() const { return count_; }
// Доступ к информации головного узла списка
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem - список пуст!");
}

// Доступ к информации хвостового узла списка
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem - список пуст!");
}

// Добавление элемента в голову списка
void DoubleLinkedList::insertHead(int item)
{   // создаем новый элемент списка и добавляем в голову 
	insertHead(new Node(item));
}


// Добавление элемента в хвост списка
void DoubleLinkedList::insertTail(int item)
{   // создаем новый элемент списка и добавляем в хвост 
	insertTail(new Node(item));
}

// Удаление элемента с головы списка
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;  // список пуст, удалений нет
	}
	deleteNode(head_);
	return 1;      // список был НЕ пуст, удаление головы
}

// Удаление элемента из хвоста списка
bool DoubleLinkedList::deleteTail()
{
	if (count_ == 0) {
		return 0;
	}
	deleteNode(tail_);
	return 1;
}

// Удаление узла с заданным значением  
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

// Поиск записи с заданным значением  
bool DoubleLinkedList::searchItem(int item)
{   // возвращаем TRUE, если узел найден 
	return (searchNode(item) != nullptr);
}


// Замена информации узла на новое 
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

// Вывод элементов списка в текстовом виде в стандартный выходной поток 
void DoubleLinkedList::outAll()
{
	Node* current = head_;       // Указатель на элемент
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;  // Переход к следующему элементу
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

// Деструктор списка	
DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr;   // указатель на элемент, подлежащий удалению
	Node* next = head_;        // указатель на следующий элемент
	while (next != nullptr) {  // пока есть еще элементы в списке
		current = next;
		next = next->next_;    // переход к следующему элементу
		delete current;        // освобождение памяти
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
