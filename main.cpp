#include <iostream>

#include "IntList.h"
#include "SortedSet.h"

int main() {
    cout << "list1 constructor called" << endl;
    IntList list1;
    cout << "set1 constructor called" << endl;
    SortedSet set1;

    cout << "list1: pushback 3" << endl;
    list1.push_back(3);
    cout << "list1: pushback 6" << endl;
    list1.push_back(6);
    cout << "list1: pushback 7" << endl;
    list1.push_back(7);
    cout << "list1: pushback 6" << endl;
    list1.push_back(6);
    cout << "list1: pushback 10" << endl;
    list1.push_back(10);
    cout << "list1: pushfront 23" << endl;
    list1.push_front(23);
    cout << "list1: pushfront 14" << endl;
    list1.push_front(14);
    cout << "list1: " << list1 << endl << endl;
    cout << "set1: pushfront 12" << endl;
    set1.push_front(12);
    cout << "set1: add 5" << endl;
    set1.add(5);
    cout << "set1: add 8" << endl;
    set1.add(8);
    cout << "set1: pushfront 58" << endl;
    set1.push_front(58);
    cout << "set1: add 24" << endl;
    set1.add(24);
    cout << "set1: insert ordered 9" << endl;
    set1.insert_ordered(9);
    cout << "set1: add 8 (should not add)" << endl;
    set1.add(8);
    cout << "set1: " << set1 << endl << endl;
    

    cout << "set2 constructor called" << endl;
    SortedSet set2(set1);
    cout << "set2: " << set2 << endl << endl;
    cout << "set3 constructor called" << endl;
    SortedSet set3(list1);
    cout << "set3: " << set3 << endl << endl;
    cout << "set4 constructor called" << endl;
    SortedSet set4 = set2 | set3;
    cout << "set4: " << set4 << endl << endl;
    cout << "set1: add 6" << endl;
    set1.add(6);
    cout << "set1: add 44" << endl;
    set1.add(44);
    cout << "set1: add 11" << endl;
    set1.add(11);
    cout << "set1: add 9" << endl;
    set1.add(9);
    cout << "set1: " << set1 << endl << endl;
    cout << "set3: add 6" << endl;
    set3.add(6);
    cout << "set3: add 44" << endl;
    set3.add(44);
    cout << "set3: add 11" << endl;
    set3.add(11);
    cout << "set3: add 9" << endl;
    set3.add(9);
    cout << "set3: " << set3 << endl << endl;
    cout << "set5 constructor called" << endl;
    SortedSet set5 = set1 & set3;
    cout << "set5: " << set5 << endl;
    cout << "set2 adds set5" << endl;
    set2 |= set5;
    cout << "set2: " << set2 << endl;
    cout << "set3 becomes like values with set2" << endl;
    set3 &= set2;
    cout << "set3: " << set3 << endl;

    list1.~IntList();
    set1.~SortedSet();
    set2.~SortedSet();
    set3.~SortedSet();
    set4.~SortedSet();
    set5.~SortedSet();

    return 0;
}