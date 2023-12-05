#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>

#include "IntList.h"

class SortedSet : public IntList {
 public:
    //constructors
    SortedSet() : IntList() {}
    SortedSet(const SortedSet &copy) : IntList(copy) {}
    SortedSet(const IntList &copy) : IntList(copy) {
        selection_sort();
        remove_duplicates();
    }
    ~SortedSet() { clear(); }
    //accessors
    bool in(int) const;
    SortedSet operator|(const SortedSet &) const;
    SortedSet operator&(const SortedSet &) const;
    //mutators
    void add(int);
    void push_front(int);
    void push_back(int);
    void insert_ordered(int);
    SortedSet & operator|=(SortedSet &);
    SortedSet & operator&=(SortedSet &);
};

#endif