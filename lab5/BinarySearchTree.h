#include <iostream>
#include <fstream>
#include<iomanip>
#include "QueueArray.h"
#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();// "по умолчанию" создает пустое дерево
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr);
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src);
	virtual ~BinarySearchTree();

	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const;

	// 2 Вставка нового элемента в дерево: true,если элемент добавлен;
	// false, если элемент уже был
	bool insert(const T& key);

	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key);

	// 4.1 Печать строкового изображения дерева в выходной поток out
	void print(std::ostream& out) const;

	// 5.1 Определение количества узлов дерева
	int getCount() const;

	// 6.1 Определение высоты дерева
	int getHeight() const;

	// 7 Инфиксный обход дерева (итеративный)
	//template<class T>
	void iterativeInorderWalk(void (*visit)(T)) const;
	// 8.1 Инфиксный обход дерева (рекурсивный)
	//template<class T>
	void inorderWalk(void (*visit)(T)) const;
	//9 Обход дерева по уровням(в ширину)
	void levelsWalk(void (*visit)(T)) const;
	//10 Похожи ли два дерева
	bool similarity(BinarySearchTree& tree);
	//11 есть ли одинаковые ключи
	bool areThereSameKeys(BinarySearchTree& tree);

private:
	template <class T>
	struct Node {
		T key_; // значение ключа, содержащееся в узле 
		Node<T>* left_; // указатель на левое поддерево 
		Node<T>* right_; // указатель на правое поддерево 
		Node<T>* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key = 0, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) : key_(key), left_(left), right_(right), p_(p)
		{ }
		Node(Node& node) {
			key_ = node.key_;
			left_ = node.left_;
			right_ = node.right_;
			p_ = node.p_;
		}
	};

	//Supporting method
	void removeTree(Node<T>* x);

	// 5.2 Рекурсивная функция определения количества узлов дерева
	size_t getCountSubTree(Node<T>* node) const;

	// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
	Node<T>* iterativeSearchNode(const T& key) const;

	//3.2 Удаление узла
	void deleteNode(Node<T>* x);

	// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
	void printNode(std::ostream& out, Node<T>* node) const;

	// 6.2 Рекурсивная функция определения высоты дерева
	int getHeight(const Node<T>* node, int height = 0) const;

	// 8.2 Рекурсивная функция для организации обхода узлов дерева.
	//template<class T>
	void inorderWalk(Node<T>* node, void (*visit)(T)) const;

	Node<T>* root_; // Указатель на корневой узел
}; // конец шаблона класса TreeBinarySearchTree


//----------------------------------------
//----------------------------------------
//----------------------------------------


template<class T>
inline BinarySearchTree<T>::BinarySearchTree() {
	root_ = nullptr;
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)
{
	root_ = scr.root_;
	scr.root_ = nullptr;
}

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
{
	root_ = src.root_;
	src.root_ = nullptr;
	return *this;
	// TODO: вставьте здесь оператор return
}

template<class T>
void BinarySearchTree<T>::removeTree(BinarySearchTree<T>::Node<T>* x) {
	if (x != nullptr) {
		//std::cout << "amogus\n";
		removeTree(x->left_);
		removeTree(x->right_);
		//std::cout << x->key_ << " ";
		delete x;
		//std::cout << "Element was deleted succefully\n";
	}
}

template<class T>
//Обратным обходом удаляем элементы
inline BinarySearchTree<T>::~BinarySearchTree()
{
	//std::cout << "Here!\n";
	removeTree(root_);
	root_ = nullptr;
}

template<class T>
inline bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	Node<T>* x = root_;
	while (x != nullptr && x->key_ != key) {
		if (key < x->key_) {
			x = x->left_;
		}
		else {
			x = x->right_;
		}
	}
	return (x != nullptr && x->key_ == key);
}

template<class T>
inline bool BinarySearchTree<T>::insert(const T& key)
{
	if (root_ == nullptr) {
		root_ = new Node<T>(key);
		return true;
	}
	Node<T>* x = root_;
	Node<T>* y = nullptr;
	while (x != nullptr) {
		if (key < x->key_) {
			y = x;
			x = x->left_;
		}
		else if (x->key_ == key) return false;
		else {
			y = x;
			x = x->right_;
		}
	}
	(key < y->key_) ? y->left_ = new Node<T>(key, nullptr, nullptr, y) : y->right_ = new Node<T>(key, nullptr, nullptr, y);
	return true;
}

template<class T>
inline bool BinarySearchTree<T>::deleteKey(const T& key)
{
	if (root_ == nullptr) return false;
	Node<T>* x = root_;
	//Node<T>* y = nullptr;
	while (x != nullptr && x->key_ != key) {
		if (key < x->key_) x = x->left_;
		else 	x = x->right_;
	}
	if (x == nullptr) return false;
	if (x->key_ != key) std::cout << "idk if its possible but still i will check it";
	deleteNode(x);
	return true;
}

template<class T>
inline void BinarySearchTree<T>::print(std::ostream& out) const
{
	printNode(out, root_);
}

template<class T>
inline int BinarySearchTree<T>::getCount() const
{
	return getCountSubTree(root_);
}

template<class T>
inline int BinarySearchTree<T>::getHeight() const
{
	if (root_ == nullptr) return 0;
	return getHeight(root_);
}

template<class T>
inline void BinarySearchTree<T>::iterativeInorderWalk(void(*visit) (T)) const
{
	if (root_ == nullptr) return;
	//std::ofstream out("C:/Users/samve/Desktop/ПОЛИТЕХ/Программирование/Лабораторки/2 сем/Практика №4/debuginfooutput.txt");
	int nNodes = getCount();
	//out << nNodes << '\n';
	int nPrintedNodes(0);
	T currentKey;
	Node<T>* x = root_;
	Node<T>* currentNode = root_;
	while (x != nullptr) {
		currentNode = x;
		x = x->left_;
	} //currentNode got the most left elem ;;;;;;;;;)
	currentKey = currentNode->key_;

	//in currentKey is placed maximum of our trip  
	while (true)
	{
		//std::cout << "stepped, " << nNodes << " " << nPrintedNodes << "\n";
		if (nPrintedNodes == nNodes) {
			//std::cout << "\nend!\n";
			return;
		}
		//
		//going down on the left side
		//
		//
		if (currentNode->left_ != nullptr && currentKey < currentNode->left_->key_) {
			//std::cout << "in the second if\n";
			//std::cout << std::left << std::setw(35) << "going down on the left side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
			currentNode = currentNode->left_;
			//std::cout << std::left << std::setw(35) << "end going down on the left side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
		}
		//
		//going down on the right side
		//conditions
		//
		else if (currentNode->right_ != nullptr && currentKey < currentNode->right_->key_)
		{
			//std::cout << "in the first if\n";
			//std::cout << std::left << std::setw(35) << "going down on the right side" << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
			(*visit)(currentNode->key_);
			nPrintedNodes++;
			currentKey = currentNode->key_;
			currentNode = currentNode->right_;
			//std::cout << std::left << std::setw(35) << "end going down on the right side" << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
		}
		//
		//going up on the left side
		//
		//
		else if (currentKey < currentNode->key_) {
			//std::cout << "in the third if\n";
			//std::cout << std::left << std::setw(35) << "going up on the left side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
			(*visit)(currentNode->key_);
			nPrintedNodes++;
			currentKey = currentNode->key_;
			currentNode = currentNode->p_;
			//std::cout << std::left << std::setw(35) << "end going up on the left side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
		}
		//
		//going up on the right side
		//
		//
		else {
			//std::cout << "in the forth if\n";
			//std::cout << std::left << std::setw(35) << "going up on the right side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
			if (currentNode->right_ == nullptr) {
				(*visit)(currentNode->key_);
				nPrintedNodes++;
			}
			currentNode = currentNode->p_;
			//std::cout << std::left << std::setw(35) << "end going up on the right side" << std::left << std::setw(30) << "CurrentNode contains " << std::left << std::setw(5) << currentNode->key_ << std::left << std::setw(30) << "CurrentKey contains " << std::left << std::setw(5) << currentKey << '\n';
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::inorderWalk(void(*visit)(T)) const
{
	inorderWalk(root_, visit);
	return;
}

template<class T>
inline void BinarySearchTree<T>::levelsWalk(void(*visit)(T)) const
{
	int nNodes(getCount());
	if (nNodes == 0) return;
	QueueArray<Node<T>> queue(nNodes);
	Node<T> x = *root_;
	queue.enQueue(x);
	while (!queue.isEmpty()) {
		x = queue.deQueue();
		(*visit)(x.key_);
		if (x.left_ != nullptr) queue.enQueue(*(x.left_));
		if (x.right_ != nullptr) queue.enQueue(*(x.right_));
	}
}

template<class T>
inline bool BinarySearchTree<T>::similarity(BinarySearchTree& tree)
{
	if (root_ == nullptr && tree.root_ == nullptr) return true;
	else if (root_ == nullptr || tree.root_ == nullptr) return false;
	int nNodes1 = getCount();
	int nNodes2 = tree.getCount();
	if (nNodes1 != nNodes2) return false;
	QueueArray<T> queue(nNodes1);
	int nPrintedNodes1(0);
	T currentKey1;
	Node<T>* x1 = root_;
	Node<T>* currentNode1 = root_;
	while (x1 != nullptr) {
		currentNode1 = x1;
		x1 = x1->left_;
	} //currentNode1 got the most left elem ;;;;;;;;;)
	currentKey1 = currentNode1->key_;
	//
	//
	//
	int nPrintedNodes2(0);
	T currentKey2;
	Node<T>* x2 = tree.root_;
	Node<T>* currentNode2 = tree.root_;
	while (x2 != nullptr) {
		currentNode2 = x2;
		x2 = x2->left_;
	} //currentNode2 got the most left elem ;;;;;;;;;)
	currentKey2 = currentNode2->key_;
	//
	//
	while (true)
	{
		if (nPrintedNodes1 < nPrintedNodes2 || queue.isEmpty())
		{
			//
			//going down on the left side
			//
			//
			if (currentNode1->left_ != nullptr && currentKey1 < currentNode1->left_->key_) {
				currentNode1 = currentNode1->left_;
			}
			//
			//going down on the right side
			//
			//
			else if (currentNode1->right_ != nullptr && currentKey1 < currentNode1->right_->key_)
			{
				queue.enQueue(currentNode1->key_);
				nPrintedNodes1++;
				currentKey1 = currentNode1->key_;
				currentNode1 = currentNode1->right_;
			}
			//
			//going up on the left side
			//
			//
			else if (currentKey1 < currentNode1->key_) {
				queue.enQueue(currentNode1->key_);
				nPrintedNodes1++;
				currentKey1 = currentNode1->key_;
				currentNode1 = currentNode1->p_;
			}
			//
			//going up on the right side
			//
			//
			else {
				if (currentNode1->right_ == nullptr) {
					queue.enQueue(currentNode1->key_);
					nPrintedNodes1++;
				}
				currentNode1 = currentNode1->p_;
			}
		}
		else if (nPrintedNodes1 > nPrintedNodes2) {
			//second tree ;)

			//
			//going down on the left side
			//
			//
			if (currentNode2->left_ != nullptr && currentKey2 < currentNode2->left_->key_) {
				currentNode2 = currentNode2->left_;
			}
			//
			//going down on the right side
			//
			//
			else if (currentNode2->right_ != nullptr && currentKey2 < currentNode2->right_->key_)
			{
				queue.enQueue(currentNode2->key_);
				nPrintedNodes2++;
				currentKey2 = currentNode2->key_;
				currentNode2 = currentNode2->right_;
			}
			//
			//going up on the left side
			//
			//
			else if (currentKey2 < currentNode2->key_) {
				queue.enQueue(currentNode2->key_);
				nPrintedNodes2++;
				currentKey2 = currentNode2->key_;
				currentNode2 = currentNode2->p_;
			}
			//
			//going up on the right side
			//
			//
			else {
				if (currentNode2->right_ == nullptr) {
					queue.enQueue(currentNode2->key_);
					nPrintedNodes2++;
				}
				currentNode2 = currentNode2->p_;
			}
		}//nPrintedNodes1 <> nPrintedNodes2
		else {
			if (!queue.isEmpty()) {
				int y1 = queue.deQueue();
				int y2 = queue.deQueue();
				//std::cout << y1 << "   " << y2 << '\n';
				//if (queue.deQueue() != queue.deQueue()) return false;
				if (y1 != y2) return false;
				if (nPrintedNodes1 == nNodes1) return true;
			}
		}
	}//while true
}

template<class T>
inline bool BinarySearchTree<T>::areThereSameKeys(BinarySearchTree& tree)
{
	if (root_ == nullptr || tree.root_ == nullptr) return false;
	int nNodes1 = getCount();
	int nNodes2 = tree.getCount();
	int nPrintedNodes1(0);
	T currentKey1;
	Node<T>* x1 = root_;
	Node<T>* currentNode1 = root_;
	while (x1 != nullptr) {
		currentNode1 = x1;
		x1 = x1->left_;
	} //currentNode1 got the most left elem ;;;;;;;;;)
	currentKey1 = currentNode1->key_;
	//
	//
	//
	int nPrintedNodes2(0);
	T currentKey2;
	Node<T>* x2 = tree.root_;
	Node<T>* currentNode2 = tree.root_;
	while (x2 != nullptr) {
		currentNode2 = x2;
		x2 = x2->left_;
	} //currentNode2 got the most left elem ;;;;;;;;;)
	currentKey2 = currentNode2->key_;
	//
	//
	while (true)
	{
		if (currentKey1 < currentKey2 && nPrintedNodes1 != nNodes1)
		{
			//
			//going down on the left side
			//
			//
			if (currentNode1->left_ != nullptr && currentKey1 < currentNode1->left_->key_) {
				currentNode1 = currentNode1->left_;
			}
			//
			//going down on the right side
			//
			//
			else if (currentNode1->right_ != nullptr && currentKey1 < currentNode1->right_->key_)
			{
				nPrintedNodes1++;
				currentKey1 = currentNode1->key_;
				currentNode1 = currentNode1->right_;
			}
			//
			//going up on the left side
			//
			//
			else if (currentKey1 < currentNode1->key_) {
				nPrintedNodes1++;
				currentKey1 = currentNode1->key_;
				currentNode1 = currentNode1->p_;
			}
			//
			//going up on the right side
			//
			//
			else {
				if (currentNode1->right_ == nullptr) {
					nPrintedNodes1++;
				}
				currentNode1 = currentNode1->p_;
			}
		}
		else if (currentKey1 > currentKey2 && nPrintedNodes2 != nNodes2) {
			//second tree ;)

			//
			//going down on the left side
			//
			//
			if (currentNode2->left_ != nullptr && currentKey2 < currentNode2->left_->key_) {
				currentNode2 = currentNode2->left_;
			}
			//
			//going down on the right side
			//
			//
			else if (currentNode2->right_ != nullptr && currentKey2 < currentNode2->right_->key_)
			{
				nPrintedNodes2++;
				currentKey2 = currentNode2->key_;
				currentNode2 = currentNode2->right_;
			}
			//
			//going up on the left side
			//
			//
			else if (currentKey2 < currentNode2->key_) {
				nPrintedNodes2++;
				currentKey2 = currentNode2->key_;
				currentNode2 = currentNode2->p_;
			}
			//
			//going up on the right side
			//
			//
			else {
				if (currentNode2->right_ == nullptr) {
					nPrintedNodes2++;
				}
				currentNode2 = currentNode2->p_;
			}
		}//nPrintedNodes1 <> nPrintedNodes2
		else {
			if (currentKey1 == currentKey2) return true;
			if (nPrintedNodes1 == nNodes1 && currentKey2 > currentKey1
				|| nPrintedNodes2 == nNodes2 && currentKey1 > currentKey2) return false;
		}
	}//while true
}

template<class T>
inline size_t BinarySearchTree<T>::getCountSubTree(Node<T>* node) const
{
	//if (node != nullptr) std::cout << node->key_ << " ";
	if (node == nullptr)
		return 0;
	return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
inline BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
	Node<T>* x = root_;
	while (x != nullptr && x->key_ != key) {
		if (key < x->key_) {
			x = x->left_;
		}
		else {
			x = x->right_;
		}
	}
	return x;
}

template<class T>
inline void BinarySearchTree<T>::deleteNode(Node<T>* x)
{
	if (x->left_ != nullptr) {
		Node<T>* y = x->left_;
		Node<T>* z = nullptr;
		z = y;
		y = y->right_;
		while (y != nullptr) {
			z = y;
			y = y->right_;
		}
		if (x->left_ == z)
		{
			z->p_ = x->p_;
			z->right_ = x->right_;
			if (x->right_ != nullptr) x->right_->p_ = z;
		}
		else
		{
			if (z->left_ != nullptr) {
				z->left_->p_ = z->p_;
				z->p_->right_ = z->left_;
			}
			else {
				z->p_->right_ = nullptr;
			}
			z->p_ = x->p_;
			z->right_ = x->right_;
			if (x->right_ != nullptr) x->right_->p_ = z;
			z->left_ = x->left_;
			x->left_->p_ = z;
		}
		if (x->p_ != nullptr) {
			(x->p_->left_ == x) ? x->p_->left_ = z : x->p_->right_ = z;
		}
		if (x == root_) root_ = z;
		delete x;
		return;
	}
	else if (x->right_ != nullptr) {
		Node<T>* y = x->right_;
		Node<T>* z = nullptr;
		z = y;
		y = y->left_;
		while (y != nullptr) {
			z = y;
			y = y->left_;
		}
		if (z->right_ != nullptr) {
			if (x->right_ != z) {
				z->right_->p_ = z->p_;
				z->p_->left_ = z->right_;
				x->right_->p_ = z;
				z->right_ = x->right_;
			}
			else {
				z->p_ = x->p_;
			}
			z->p_->left_ = z->right_;
			z->p_ = x->p_;
			z->right_ = x->right_;
			//z->left_ = x->left_;
		}
		else {
			if (x->right_ != z) {
				x->right_->p_ = z;
				z->p_->left_ = nullptr;
				z->p_ = x->p_;
				z->right_ = x->right_;
			}
			else {
				z->p_ = x->p_;
			}
			//z->right_ = x->right_;
		}
		if (x != root_)
			(x->p_->left_ == x) ? x->p_->left_ = z : x->p_->right_ = z;
		if (x == root_) root_ = z;
		delete x;
		return;
	}
	else {
		if (root_ != x) (x->p_->left_ == x) ? x->p_->left_ = nullptr : x->p_->right_ = nullptr;
		if (root_ == x) root_ = nullptr;
		delete x;
	}
}

template<class T>
inline void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* node) const
{
	if (node != nullptr) {
		(node->left_ == nullptr && node->right_ == nullptr) ? std::cout << node->key_ << "{" : std::cout << node->key_ << "( ";
		printNode(out, node->left_);
		std::cout << ", ";
		printNode(out, node->right_);
		(node->left_ == nullptr && node->right_ == nullptr) ? std::cout << "}" : std::cout << " )" << '[' << node->key_ << ']';
	}
	else {
		std::cout << "n";
	}
}

template<class T>
inline int BinarySearchTree<T>::getHeight(const Node<T>* node, int height) const
{
	static int maxHeight(0);
	if (node != nullptr) {
		getHeight(node->left_, height + 1);
		getHeight(node->right_, height + 1);
	}
	else {
		if (maxHeight < height)  maxHeight = height - 1;
	}
	return maxHeight;
}

template<class T>
inline void BinarySearchTree<T>::inorderWalk(Node<T>* node, void(*visit)(T)) const
{
	if (node != nullptr) {
		inorderWalk(node->left_, visit);
		(*visit)(node->key_);
		inorderWalk(node->right_, visit);
	}
}

#endif //!_BINARY_SEARCH_TREE_H