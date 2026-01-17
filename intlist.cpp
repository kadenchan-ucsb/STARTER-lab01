// intlist.cpp
// Implements class IntList
// Kaden Chan, CS24, 1/13/2026
#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node *head;
    Node *tail;

    
}

// destructor deletes all nodes
IntList::~IntList() {

    while (head){
        Node* curr = head->next;
        delete head;
        head = curr;
    }
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node *curr = head;
    int result = 0;
    while (curr!=tail){
        result+=curr->info;
        curr = curr->next;
    }
    result+=curr->info;
    return result; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *curr = head;
    while (curr!=tail){
        if (curr->info == value){
            return true;
        }
        curr = curr->next;
    }
    if (curr->info == value){
        return true;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node *curr = head;
    if(curr == nullptr){
        return 0;
    }
    int max=curr->info;
    while (curr!=tail){
        if (curr->info > max){
            max = curr->info;
        }
        curr = curr->next;
    }
    if (curr->info > max){
        max = curr->info;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    
    Node *curr = head;
    int result = 0;
    int num = 0;
    while (curr!=tail){
        result+=curr->info;
        curr = curr->next;
        num++;
    }
    result+=curr->info;
    num++;
    if (num == 0){
        return 0.0;
    }
    return (double)result/(double)num; 
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node *newNode = new Node(value);
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node *newNode = new Node();
    newNode->info = value;
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
 
}

// return count of values
int IntList::count() const {
    Node *curr = head;
    int num = 0;
    while (curr!=tail){
        curr = curr->next;
        num++;
    }
    result+=curr->info;
    num++;
    if (num == 0){
        return 0.0;
    }
    return num;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    ~IntList();
    self.head=source.head;
    self.tail=source.tail;
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

