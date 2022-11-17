// Практика №5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <exception>
#include <iostream>
#include "QueueArray.h"
#include "BinarySearchTree.h"
template<class T>
void print(T x) {
	std::cout << x << " ";
}

int main()
{
	try {
		//QueueArray<double> queue(-1);
		//QueueArray<double> queue(1);
		//queue.deQueue();

		//queue.enQueue(2.0);
		//queue.enQueue(1.0);


		BinarySearchTree<int> tree1;
		tree1.insert(100);
		tree1.insert(90);
		tree1.insert(91);
		tree1.insert(93);
		tree1.insert(92);
		tree1.insert(80);
		tree1.insert(170);
		tree1.insert(160);
		tree1.insert(180);
		tree1.levelsWalk(print);
		BinarySearchTree<int> tree2;
		tree2.insert(90);
		tree2.insert(91);
		tree2.insert(93);
		tree2.insert(100);
		tree2.insert(92);
		tree2.insert(80);
		tree2.insert(170);
		tree2.insert(160);
		tree2.insert(180);
		std::cout << '\n';
		tree2.levelsWalk(print);
		std::cout << '\n';
		tree1.iterativeInorderWalk(print);
		std::cout << '\n';
		tree2.iterativeInorderWalk(print);
		std::cout << "\nSimilarity test: " << tree1.similarity(tree2);
		std::cout << "\nareThereSameKeys test: " << tree1.areThereSameKeys(tree2);
	}
	catch (WrongQueueSize& e) {
		std::cout << e.what();
	}
	catch (QueueOverflow& e) {
		std::cout << e.what();
	}
	catch (QueueUnderflow& e) {
		std::cout << e.what();
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
