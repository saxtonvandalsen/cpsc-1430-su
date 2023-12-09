#include <iostream>
#include "FancyList-hw3.h"
using namespace std;
// Linked list header file

FancyList::FancyList(){
    head = nullptr;
}

FancyList::~FancyList(){
    ListNode * curr = head;
    ListNode * nextNode = nullptr;

    while (curr != nullptr){
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
}

FancyList::FancyList(FancyList &copyList){
    ListNode * prev = nullptr;
    ListNode * newNode = nullptr;
    ListNode * curr = copyList.head;

     while (curr != nullptr){
        newNode = new ListNode;
        newNode->value = curr->value;
        newNode->next = nullptr;

        if (prev == nullptr){
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
        curr = curr->next;
    }
}

void FancyList::appendNode(int num){
    ListNode * curr = nullptr;
    ListNode * newNode = nullptr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head){
        head = newNode;
    } else {
        curr = head;

        while (curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void FancyList::displayList() const{
    ListNode * curr = nullptr;
    curr = head;

    while (curr != nullptr){
        cout << curr->value;
        curr = curr->next;
    }
}

void FancyList::deleteNthNode(int n){
    ListNode * prev = nullptr;
    ListNode * curr = nullptr;
    curr = head;
    int count = 0;

    if (head == nullptr){
        return;
    }

    while (curr != nullptr){
        prev = curr;
        curr = curr->next;
        count++;
    }

    int nthPosition = count - n +1;

    if (n > count || n <= 0){
        return;
    }

    curr = head;
    prev = nullptr;

    for (int i = 1; i < nthPosition; i++){
        prev = curr;
        curr = curr->next;
    }

    if (prev != nullptr){
        prev->next = curr->next;
    } else {
        head = curr->next;
    }
    delete curr;
}

void FancyList::insertNode(int num){
    ListNode * prev = nullptr;
    ListNode * curr = nullptr;
    ListNode * newNode = nullptr;

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (!head){
        head = newNode;
    } else {
        curr = head;

        while (curr != nullptr && curr->value < num){
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr){
            newNode->next = head;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void FancyList::reverseList(){
    ListNode * prev = nullptr;
    ListNode * curr = nullptr;
    ListNode * nextNode = nullptr;
    curr = head;

    if(!head){
        return;
    }
    while (curr != nullptr){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}