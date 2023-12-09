// Saxton Van Dalsen
// lab7_8.cpp
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 71***********/
#include "Helper-lab7_8.h"
using namespace std;
//Merge two sorted linked lists in place for task I
Node * mergeList(Node * l1Head, Node * l2Head);
//Removes all the nodes in a sorted list that have the targeted value
Node * removeTargets(Node * head, int val);
//Remove duplicatesd nodes such that node with the same value only appears once
Node * removeDuplicates(Node * head);
//Find the middle node in a given linked list
Node * findMiddle(Node * head);

//Your program will be tested with the following command:
//./lab7_8 test_case.txt NUMBER_HERE(Replace with real number),
//where lab7_8 is your executable name after compilation,
//test_case.txt is a txt file that has two lines of numbers for creating two lists,
//NUMBER_HERE is a specific target number for task II.
//Note that (1) NUMBER_HERE can be any number when running the command.
//For example, a real command in practice could be "./lab7_8 test_case.txt 6".
//(2) lines could be empty in test_case.txt, which means empty list could be created
int main(int argc, char * argv[]){
    //Preparation. I get this done so that you can focus on the following three tasks.
    //create a list using the first line in the input file
    Node * l1Head = createListFromFile(argv[1], 1);
    //create a list using the second line in the input file
    Node * l2Head = createListFromFile(argv[1], 2);
    // printList(l1Head);
    // printList(l2Head);

    //Your task I: merge the above two sorted lists and keep the merged list sorted.
    //the merge should be in-place. That is, you are not allowed to create a new list,
    //in which node values are copied from two given lists.
    //Instead, you should change the pointers of each existing node properly
    //to chain the existing nodes in both lists together.
    Node * listHeadAfterTaskI = mergeList(l1Head, l2Head);
    printList(listHeadAfterTaskI);

    //Your task II: find the middle node in the linked list generated after task I
    //If there are two middle nodes, return the first middle nodes.
    //For example, if the list is head->1->2->3->null, the middle node will be 2;
    //if the list is head->1->2->3->4->null, there are will be two middle
    //nodes (i.e., 2 and 3), your function should return the *first* one, i.e., 2.
    Node * middleNode = findMiddle(listHeadAfterTaskI);
    if (middleNode){
    cout << "The value of the middle node is " << middleNode->value << endl;
    }else{
    cout << "No middle node in an empty list." << endl;
    }

    //Your task III: remove all the nodes in a sorted list that have the targeted value.
    //For example, assuming the targeted value is 6, and the merged list after task I
    //is head->2->2->6->6->7->7->7->7->8->9->null,
    //after this task III the list will become head->2->2->7->7->7->7->8->9->null
    int targetVal = stoi(argv[2]);
    Node * listHeadAfterTaskIII = removeTargets(listHeadAfterTaskI, targetVal);
    printList(listHeadAfterTaskIII);

    //Your task IV: remove all the duplicated nodes (such that node with the same value
    // only appears once) in the merged list after task III.
    //Since the list remains sorted (non-descending) after task III,
    //the final list will be strictly ascending as we removed all the duplicated values.
    //Continuing the previous example in taskIII,
    //if the list returned by taskIII is head->2->2->7->7->7->7->8->9->null,
    //after this taks IV, it will become head->2->7->8->9->null
    Node * listHeadAfterTaskIV = removeDuplicates(listHeadAfterTaskIII);
    printList(listHeadAfterTaskIV);

    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/


/********* YOU SHOULD IMPLEMENT THREE FUNCTIONS AFTER THIS LINE **********/

// Function to merge two sorted linked lists in place
Node * mergeList(Node * l1Head, Node * l2Head){
    Node * newHead = nullptr;
    Node * curr = nullptr;

    // Returning the second list if the first list is empty
    if (l1Head == nullptr){
        return l2Head;
    }
    // Returning the first list if the second list is empty
    if (l2Head == nullptr){
        return l1Head;
    }

    // Checking the value of the first node of both lists to start merging with a 'newHead' pointer
    if (l1Head->value < l2Head->value){
        newHead = l1Head;
        l1Head = l1Head->next;
    } else {
        newHead = l2Head;
        l2Head = l2Head->next;
    }
    curr = newHead;

    // Traversing through the list to compare the values of every
    // node to link in non-descending order
    while (l1Head && l2Head){
        if (l1Head->value < l2Head->value){
            curr->next = l1Head;
            l1Head = l1Head->next;
        } else if (l1Head->value > l2Head->value) {
            curr->next = l2Head;
            l2Head = l2Head->next;
        } else {
            // If two values are equal to each other chain together current nodes
            curr->next = l1Head;
            l1Head = l1Head->next;
            curr = curr->next;

            curr->next = l2Head;
            l2Head = l2Head->next;
        }
        curr = curr->next; // Setting up curr->next for the next iteration
    }

    // If fully traversed through one of the linked lists,
    // finish chaining the rest of the nodes of the other list to the new list
    while (l1Head){
        curr->next = l1Head;
        l1Head = l1Head->next;
        curr = curr->next;
        }
    while (l2Head){
        curr->next = l2Head;
        l2Head = l2Head->next;
        curr = curr->next;
        }

    return newHead; // Return newly merged linked list
}

// Function to find the middle node in the list
Node * findMiddle(Node * head){
    Node * fast = nullptr;
    Node * slow = nullptr;

    // Return if list is empty
    if (head == nullptr){
        return head;
    }

    int length = 0; // Get the length of the list
    fast = head;

    // Traversing through the list to get the length of it
    while (fast != nullptr){
        slow = fast;
        fast = fast->next;
        length++; //
    }
    slow = head; // Reassigning pointers to head
    fast = head; // for next traversal

    // If the list length is even, find the first middle node
    if (length % 2 == 0){
        while (fast != nullptr){
            // Stopping traversal 1 iteration early to get first middle node
            if (fast->next->next == nullptr){
                break;
            }
            slow = slow->next; // Moving slow pointer 1 node
            fast = fast->next->next; // Moving fast pointer 2 nodes
        }
    } else { // Execute traversal until the end if list is odd
        while (fast != nullptr){ 
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow; // Returning value of the middle node
}

// Removing user-specified value and returning the list after removal
Node * removeTargets(Node * head, int val) {
    Node * prev = nullptr;
    Node * curr = nullptr;

    // Return if list is empty
    if (head == nullptr){
        return head;
    }

    // Checking if user input for 'val' is out of range
    if (val < -2 || val > 4){
        return head;
    }

    // Checking if the first node in the list holds target 'val'
    if (head->value == val){
        curr = head->next; // Maintaining the link after head
        delete head; // Deleting value of Node that head is pointing to
        head = curr; // Reassigning head to the next node in the list
    } else {
        curr = head;

        // Traversing through nodes whole value doesn't equal target 'val'
        while (curr != nullptr && curr->value != val){
            prev = curr;
            curr = curr->next;
        }

        // Removing each node in ordered list whose value equals target 'val'
        while (curr->value == val){
            prev->next = curr->next; // Maintaining the link between the node to be removed
            delete curr;
            curr = prev->next; // Preparing curr to the next node for future iteration

            // If last node to be deleted, set it to null after removal
            if (curr->next == nullptr){
                prev->next = curr->next;
                delete curr;
                curr->next = nullptr; // Setting last node next pointer to null
            }
        }
    }
    return head; // Returning list after removing target 'val'
}

// Function to return the list without any duplicated values of nodes
Node * removeDuplicates(Node * head) {
    Node * prev = nullptr;
    Node * curr = nullptr;
    Node * nextNode = nullptr;

    // If list is empty return head
    if (head == nullptr){
        return head;
    }
    curr = head;

    // Traversing through the list for each duplicated value
    while (curr != nullptr){
        nextNode = curr->next;

        // Since list is non-descending, checking each two nodes at a time if they
        // have the same value, if so delete until one remains
        if (nextNode != nullptr && nextNode->value == curr->value){
            curr->next = nextNode->next;
            delete nextNode;
        }
        else {
            prev = curr;
            curr = nextNode;
        }
    }
    return head;
}