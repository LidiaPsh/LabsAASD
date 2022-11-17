// Практика №4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "BinarySearchTree.h"
#include <iostream>

template<class T>
void print(T x) {
    std::cout << x << " ";
}

int main()
{
    std::cout << "\ntree1:\n";
    BinarySearchTree<int> tree1;
    tree1.insert(3);
    tree1.insert(5);
    tree1.insert(4);
    tree1.insert(1);
    tree1.insert(2);
    //
    tree1.insert(3);
    tree1.insert(5);
    tree1.insert(4);
    tree1.insert(1);
    tree1.insert(2);
    //
    tree1.insert(7);
    tree1.insert(10);
    tree1.insert(100);
    tree1.insert(12);
    tree1.insert(34);
    //
    tree1.iterativeInorderWalk(print);
    std::cout << "\n\ntree2:\n";
    BinarySearchTree<int> tree2; //full mega tree hog rider ultra plus amogus
    tree2.insert(200);
    tree2.insert(150);
    tree2.insert(220);
    tree2.insert(140);
    tree2.insert(160);
    tree2.insert(139);
    //
    tree2.insert(142);
    tree2.insert(161);
    //
    tree2.insert(141);
    tree2.insert(143);
    tree2.insert(162);
    tree2.insert(165);
    tree2.insert(164);
    tree2.insert(166);
    tree2.insert(163);
    //
    tree2.insert(217);
    tree2.insert(225);
    tree2.insert(226);
    tree2.insert(224);
    tree2.insert(216);
    tree2.insert(218);
    std::cout << "\niterativeInorderWalk\n";
    tree2.iterativeInorderWalk(print);
    std::cout << "\nRecursiveInorderWalk\n";
    tree2.inorderWalk(print);
    std::cout << "\n\n\nprinting tree2: ";
    tree2.print(std::cout);
    std::cout << "\n\n";

    //
    std::cout << "\n\ntree3:\n";
    BinarySearchTree<int> tree3; // only right side
    tree3.insert(200);
    tree3.insert(220);
    //
    tree3.insert(217);
    tree3.insert(225);
    tree3.insert(226);
    tree3.insert(224);
    tree3.insert(216);
    tree3.insert(218);
    tree3.deleteKey(216);
    tree3.deleteKey(218);
    tree3.deleteKey(225);
    tree3.deleteKey(200);
    std::cout << "\niterativeInorderWalk\n";
    tree3.iterativeInorderWalk(print);
    std::cout << "\nRecursiveInorderWalk\n";
    tree3.inorderWalk(print);
    std::cout << '\n';
    tree3.print(std::cout);
    std::cout << '\n';
    std::cout << "\n\ntree4:\n";
    BinarySearchTree<int> tree4;
    std::cout << '\n' << tree4.deleteKey(100) << tree4.getCount() << tree4.getHeight();
    tree4.inorderWalk(print);
    std::cout << "\n\ntree5:\n";
    BinarySearchTree<int> tree5;
    tree5.insert(200);
    tree5.insert(150);
    tree5.insert(220);
    tree5.insert(140);
    tree5.insert(160);
    tree5.insert(139);
    //
    tree5.insert(142);
    tree5.insert(161);
    //
    tree5.insert(141);
    tree5.insert(143);
    tree5.insert(162);
    tree5.insert(165);
    tree5.insert(164);
    tree5.insert(166);
    tree5.insert(163);
    std::cout << "\niterativeInorderWalk before deleting\n";
    tree5.print(std::cout);
    tree5.deleteKey(166);
    std::cout << '\n';
    tree5.print(std::cout);
    tree5.deleteKey(164);
    std::cout << '\n';

    tree5.print(std::cout);
    tree5.deleteKey(150);
    std::cout << '\n';

    tree5.print(std::cout);
    tree5.deleteKey(200);
    std::cout << '\n';

    tree5.print(std::cout);
    std::cout << "\niterativeInorderWalk\n";
    tree5.iterativeInorderWalk(print);
    std::cout << "\nRecursiveInorderWalk\n";
    tree5.inorderWalk(print);
    BinarySearchTree<int> tree6;
    tree6.insert(10);
    tree6.insert(8);
    tree6.insert(12);
    std::cout << "\n\n\n";
    tree6.print(std::cout);
    std::cout << "\n\n";
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
