#include "SortedSet.h"

bool SortedSet::in(int val) const {
    IntNode * curr = head;
    while (curr) {
        if (curr->value == val) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}


SortedSet SortedSet::operator|(const SortedSet &add) const {
    SortedSet temp(add);
    IntNode * curr = head;
    while (curr) {
        temp.add(curr->value);
        curr = curr->next;
    }
    return temp;
}

SortedSet SortedSet::operator&(const SortedSet &add) const {
    SortedSet temp;
    IntNode * curr1 = head;
    IntNode * curr2;
    while (curr1) {
        curr2 = add.head;
        while (curr2) {
            if (curr1->value == curr2->value) {
                temp.add(curr1->value);
                break;
            }
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    return temp;
}



void SortedSet::add(int val) {
    IntNode * temp;
    if (head == nullptr) {
        head = new IntNode(val);
        tail = head;
        return;
    }
    if (val == head->value) {
        return;
    }
    if (val < head->value) {
        temp = head;
        head = new IntNode(val);
        head->next = temp;
        return;
    }
    if (head->next == nullptr && val > head->value) {
        head->next = new IntNode(val);
        tail = head->next;
        return;
    }
    IntNode * curr = head->next;
    IntNode * prev = head;
    while (curr) {
        if (val == curr->value) {
            return;
        }
        if (val < curr->value && val > prev->value) {
            prev->next = new IntNode(val);
            prev->next->next = curr;
            return;
        }
        if (tail == curr && val > curr->value) {
            curr->next = new IntNode(val);
            tail = curr->next;
        }
        prev = curr;
        curr = curr->next;
    }
}

void SortedSet::push_front(int val) {
    add(val);
}

void SortedSet::push_back(int val) {
    add(val);
}

void SortedSet::insert_ordered(int val) {
    add(val);
}


SortedSet & SortedSet::operator|=(SortedSet &add) {
    *this = *this | add;
    return *this;
}

SortedSet & SortedSet::operator&=(SortedSet &add) {
    *this = *this & add;
    return *this;
}