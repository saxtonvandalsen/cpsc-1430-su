#include <iostream>
#ifndef FANCYLIST_H
#define FANCYLIST_H

class FancyList {

    private:

        struct ListNode {
            int value;
            ListNode * next;
        };

        ListNode * head = nullptr;

    public:
        FancyList();
        ~FancyList();
        FancyList(FancyList &copyList);
        void appendNode(int);
        void insertNode(int);
        void displayList() const;
        void reverseList();
        void deleteNthNode(int);
};

#endif