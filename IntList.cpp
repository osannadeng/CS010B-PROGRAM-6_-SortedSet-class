#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) {}

IntList::~IntList() { clear(); }

IntList::IntList(const IntList &cpy) {
    IntNode* curr = cpy.head;
    head = nullptr;
    tail = nullptr;
    while (curr) {
        push_back(curr->value);
        curr = curr->next;
    }
}

void IntList::clear() {
    while (head) {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
    head = tail = nullptr;
}

void IntList::push_front(int val) {
    IntNode* newNode = new IntNode(val);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}


void IntList::pop_front() {
    if (head != nullptr) {
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
        } else {
            IntNode* nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }
}


bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

const int & IntList::front() const { return head->value; }
	
const int & IntList::back() const { return tail->value; }

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode* currNode = list.head;
    while (currNode) {
        out << currNode->value;
        if (currNode->next != nullptr) {
            out << " ";
        }
        currNode = currNode->next;
    }
    return out;
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        IntNode* curr = rhs.head;
        clear();
        while (curr) {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    if (head == nullptr) {
        head = tail = new IntNode(value);
    } else {
        IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
    }
}

void IntList::selection_sort() {
    IntNode* temp = head;
    IntNode* search;
    int minVal;
    IntNode* minLoc;
    while (temp) {
        search = temp->next;
        minVal = temp->value;
        minLoc = temp;
        while (search) {
            if (search->value < minVal) {
                minVal = search->value;
                minLoc = search;
            }
            search = search->next;
        }
        minLoc->value = temp->value;
        temp->value = minVal;
        temp = temp->next;
    }
}

void IntList::insert_ordered(int value) {
    if (head == nullptr) {
        head = tail = new IntNode(value);
    } else {
        IntNode* prev = head;
        IntNode* curr = prev->next;
        while (curr != nullptr && value > curr->value) {
            prev = prev->next;
            curr = curr->next;
        }
        if (value <= head->value) {
            push_front(value);
        } else if (curr == nullptr) {
            push_back(value);
        } else {
            IntNode* newNode = new IntNode(value);
            newNode->next = curr;
            prev->next = newNode;
        }
    }
}

void IntList::remove_duplicates() {
    IntNode* temp = head;
    while (temp) {
        IntNode* prev = temp;
        IntNode* curr = prev->next;
        while (curr) {
            if (temp->value == curr->value) {
                prev->next = curr->next;
                delete curr;
                if (prev->next == nullptr) {
                    tail = prev;
                }
            } else {
                prev = prev->next;
            }
            curr = prev->next;
        }
        temp = temp->next;
    }
}

IntNode * IntList::min(IntNode *) { return nullptr; }

void IntList::copy(const IntList &) {}