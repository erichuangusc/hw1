/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

void printLinkedList(Node* head) {
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}
int main(int argc, char* argv[])
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(head, odds, evens);

    printLinkedList(head);
    printLinkedList(odds);
    printLinkedList(evens);

  return 0;
}
