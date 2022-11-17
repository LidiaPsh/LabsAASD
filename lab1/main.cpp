//
// Примеры использования класса DoubleLinkedList
//
#include "DoubleLinkedList.h"
#include <iostream>

int main() {
	DoubleLinkedList list;   // Создание пустого списка
	std::cout << "    What list contains:    ";
	list.outAll();           // Печать элементов
	std::cout << '\n';
	list.insertTail(20000);      // Добавление элементов
	list.insertTail(3);
	list.insertTail(1);
	std::cout << " C:insertTail(20000);\n C:insertTail(3);\n C:insertTail(1); ";
	std::cout << "\n    What list contains:    ";
	list.outAll();           // Печать элементов
	std::cout << "\n C:searchItem(1)\n";
	std::cout << ((list.searchItem(1)) ? "1 was found" : "1 was not found") << std::endl;
	std::cout << "\n C:searchItem(8)\n";
	std::cout << ((list.searchItem(8)) ? "8 was found" : "8 was not found") << std::endl;
	
	std::cout << "\n---------Going to the next part------------\n";
	std::cout << " C:DoubleLinkedList  list1(list)\n\n";
	DoubleLinkedList  list1(list);  // Копирование списка
	std::cout << "    What list1 contains:    ";
	list1.outAll();
	std::cout << "\n C:list1.insertHead(4)\n C:list1.insertHead(5)\n C:list1.deleteHead()\n";
	list1.insertHead(4);         // Добавление элемента
	list1.insertHead(5);         // Добавление элемента
	list1.deleteHead();          // Удаление головного
	std::cout << "    What list1 contains:    ";
	list1.outAll();
	std::cout << "\n-----------------Going to another part---------------------\n";
	std::cout << " C:DoubleLinkedList list3 = list1\n\n";
	DoubleLinkedList list3 = list1;
	std::cout << "    What list3 contains:    ";
	list3.outAll();
	std::cout << "\n    The headitem of list3 is " << list3.headItem() << "\n\n";
	std::cout << " C:list3.headItem() = 2\n";
	list3.headItem() = 2;
	std::cout << "\n    The new headitem of list3 is " << list3.headItem() << '\n';
	std::cout << "\n    The  tailitem of list3 is " << list3.tailItem() << '\n';
	std::cout << "\n-----------------And another part---------------------\n";
	DoubleLinkedList list4;
	std::cout << "    What list4 contains:    \n";
	std::cout << "    What list3 contains:    ";
	list3.outAll();
	std::cout << " C:list3 == list4\n";
	std::cout << ((list3 == list4) ? "    true\n" : "    false\n");
	std::cout << " C:list3 = list4\n";
	list3 = list4;
	std::cout << " C:list3 == list4\n";
	std::cout << ((list3 == list4) ? "    true\n" : "    false\n");
	std::cout << "\n-----------------And another part---------------------\n";
	std::cout << " C:DoubleLinkedList  list5\n";
	DoubleLinkedList  list5;
	list5.insertHead(1);
	list5.insertHead(2);
	list5.insertHead(3);
	list5.insertHead(4);
	list5.insertHead(5);
	std::cout << " C:list5.insertHead(1)\n C:list5.insertHead(2);\n C:list5.insertHead(3);\n C:list5.insertHead(4);\n C:list5.insertHead(5);\n\n";
	std::cout << "    What list5 contains:    ";
	list5.outAll();
	list5.replaceItem(5, 6);
	std::cout<<"\n C:list5.replaceItem(5, 6); \n\n";
	std::cout << "    What list5 contains:    ";
	list5.outAll();
	list5.replaceItem(4, 6);
	std::cout << "\n C:list5.replaceItem(4, 6); \n\n";
	std::cout << "    What list5 contains:    ";
	list5.outAll();
	std::cout << "\n C:operator <<\n";
	std::cout << "    " << list5;
	std::cout << "\n-----------------And another part---------------------\n";
	std::cout << " C:DoubleLinkedList  list6\n\n";
	DoubleLinkedList  list6;
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	std::cout << "    What list6 contains:    ";
	list6.outAll();
	std::cout << "\n C:list6.deleteItem(1)\n\n";
	std::cout << (list6.deleteItem(1) ? "    true" : "    false");
	std::cout << "\n    What list6 contains:    ";
	list6.outAll();
	std::cout << "\n C:list6.deleteItem(1, true)\n\n";
	std::cout << (list6.deleteItem(1, true) ? "    true" : "    false");
	std::cout << "\n    What list6 contains:    ";
	list6.outAll();
	std::cout << "\n C:list6.deleteItem(1)\n\n";
	std::cout << (list6.deleteItem(1) ? "    true" : "    false");
	std::cout << "\n    What list6 contains:    ";
	list6.outAll();
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	list6.insertHead(1);
	std::cout << "\n C:insertHead(1)x6\n\n";
	std::cout << "    What list6 contains:    ";
	list6.outAll();
	std::cout << "\n C:DoubleLinkedList  list7\n";
	DoubleLinkedList  list7;
	list7.insertHead(2);
	list7.insertHead(2);
	list7.insertHead(2);
	list7.insertHead(2);
	list7.insertHead(2);
	list7.insertHead(2);
	std::cout << "\n C:insertHead(2)x6\n\n";
	std::cout << "    What list7 contains:    ";
	list7.outAll();
	std::cout << "\n C:list6.add(list7)\n\n";
	list6.add(list7);
	std::cout << "    What list6 contains:    ";
	list6.outAll();
	std::cout << "    What list7 contains:    ";
	list7.outAll();
	std::cout << "\n C:DoubleLinkedList  list8\n";
	DoubleLinkedList  list8;
	std::cout << "\n C:DoubleLinkedList  list9\n";
	DoubleLinkedList  list9;
	std::cout << "\n C:list8.add(list9)\n";
	list8.add(list9);
	std::cout << "\n C:DoubleLinkedList  list10\n";
	DoubleLinkedList  list10;
	list10.insertHead(1);
	list10.insertHead(1);
	list10.insertHead(1);
	list10.insertHead(1);
	list10.insertHead(1);
	list10.insertHead(1);
	std::cout << "\n C:insertHead(1)x6\n\n";
	std::cout << "    What list10 contains:    ";
	list10.outAll();
	std::cout << "\n C:replaceItem(1, 2);  ";
	std::cout << (list10.replaceItem(1, 2) ? "    true" : "    false");
	std::cout << "\n    What list10 contains:    ";
	list10.outAll();
	std::cout << "\n C:replaceItem(1, 2, true);  ";
	std::cout << (list10.replaceItem(1, 2, true) ? "    true" : "    false");
	std::cout << "\n    What list10 contains:    ";
	list10.outAll();
	std::cout << "\n C:replaceItem(0, 2, true);  ";
	std::cout << (list10.replaceItem(0, 2, true) ? "    true" : "    false");
	std::cout << "\n    What list10 contains:    ";
	list10.outAll();
}