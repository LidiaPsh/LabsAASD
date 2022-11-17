#include"SinglyOrderedList.h"
#include <iostream>

int main()
{
    SinglyOrderedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(5);
    list1.insert(4);
    list1.insert(3);
    list1.out();
    std::cout << '\n';
    std::cout << "-----" << list1.search(1) << '\n';
    SinglyOrderedList list2;
    std::cout << "++++" << list2.search(1) << '\n';
    std::cout << "***" << list1.remove(0) << '\n';
    std::cout << list1.remove(0) << '\n';
    list1.unite(&list2);
    list1.out();
    std::cout << '\n';
    list2.out();
    SinglyOrderedList list3;
    list3.insert(9);
    list3.insert(6);
    list3.insert(7);
    list3.insert(5);
    list3.insert(8);
    list3.out();
    std::cout << '\n';
    list1.unite(&list2);
    list1.unite(&list3);
    list1.out();
    list3.insert(9);
    list3.insert(6);
    list3.insert(7);
    list3.insert(5);
    list3.insert(8);
    //std::cout << '\n' << list3.getHeadItem() << '\n';
    list1.exclude(&list3);
    std::cout << "alkjS:kj;ladlkj;" <<'\n';
    list1.out();
    std::cout << "alkjS:kj;ladlkj;" << '\n';
    list3.out();
    //std::cout << '\n' << list1.getHeadItem();
    intersection(list1, list3)->out();
    SinglyOrderedList list4;
    SinglyOrderedList list5;
    intersection(list4, list5)->out();
    list4.insert(1);
    list4.insert(2);
    list4.insert(3);
    list5.insert(1);
    list5.insert(2);
    list5.insert(3);
    std::cout << '\n';
    intersection(list4, list5)->out();
}