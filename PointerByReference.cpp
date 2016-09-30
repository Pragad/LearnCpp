#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

// Utility function to print all values of the list.
void printList(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

// -----------------------------------------------------------------------------------------
// Q1: Finding length of the linked list.
// P1. Don't use head pointer to traverse the list as head should always point to the First Entry
// P2: Function argument can just be "node* head" instead of "struct node* head"
// http://stackoverflow.com/questions/6526225/struct-keyword-in-function-parameter-and-const-correctness
// http://stackoverflow.com/questions/1675351/typedef-struct-vs-struct-definitions
// -----------------------------------------------------------------------------------------
unsigned int getLength(node* head)
{
    unsigned int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

// -----------------------------------------------------------------------------------------
// Q5. InsertNth to insert at any place
// -----------------------------------------------------------------------------------------
void insertNth(struct node*& head, unsigned int index, int value)
{
    unsigned int tmpCount = 0;
    struct node* tmpNewNode = new node();
    struct node* tmpHead = head;

    // Proceed only if the index is valid
    if (index <= getLength(head))
    {
        tmpNewNode->data = value;
        tmpNewNode->next = NULL;

        //if (head == NULL)
        if (index == 0)
        {
            tmpNewNode->next = head;
            head = tmpNewNode;
            return;
        }

        while (tmpCount < index-1)
        {
            tmpHead = tmpHead->next;
            tmpCount++;
        }

        tmpNewNode->next = tmpHead->next;
        tmpHead->next = tmpNewNode;
    }
}

// When passed by pointer
//      - ONLY the object that the pointer points gets modified. Not the pointer itself
// When pointer is passed by reference then,
//      - The pointer itself gets modified
//
// Head 1: 0xfc1008
// Addr 1: 0x61fef0
// Head 2: 0xfc1008
// Addr 2: 0x61fed0
void samp(node* head)
{
    cout << "Head 2: " << head << endl;
    cout << "Addr 2: " << &head << endl;

    // The following will change the VALUE in head pointer just altering the linked list.
    /*
    node* b = head;
    b->next = NULL;

    // head->next = NULL;
    */

    head = head->next;
    head = NULL;
}

// -----------------------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------------------
int main()
{
    {
        node* head1 = nullptr;
        insertNth(head1, 0, 5);
        insertNth(head1, 1, 3);
        insertNth(head1, 2, 7);
        insertNth(head1, 3, 1);
        insertNth(head1, 4, 7);
        insertNth(head1, 5, 3);
        insertNth(head1, 6, 5);


        cout << endl << "PROBLEM 17. Is list Palindrome" << endl;
        printList(head1);
        cout << "Head 1: " << head1 << endl;
        cout << "Addr 1: " << &head1 << endl;
        samp(head1);
        printList(head1);
    }

    cout << endl;
    return 0;
}
