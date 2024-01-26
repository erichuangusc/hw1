/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void recursion(Node*& current, Node*& odds, Node*& evens);

void split(Node*& in, Node*& odds, Node*& evens) {
    // odd and even linked list
    odds = NULL;
    evens = NULL;

    // check if in is empty
    if (in == NULL) {
        return;
    }

    // recursive call
    recursion(in, odds, evens);
    in = NULL;
}

/* If you needed a helper function, write it here */

void recursion(Node*& current, Node*& odds, Node*& evens) {
    if (current == NULL) {
        // base case
        return;
    }

    Node* temp = current->next;
    // check even or odd
    if (current->value % 2 == 0) {
        // even
        if (evens == NULL) {
            evens = current;
            evens->next = NULL;
        } else {
            evens->next = current;
            evens->next->next = NULL;
        }
        recursion(temp, odds, evens->next);
    } 
    else {
        // odds
        if (odds == NULL) {
            odds = current;
            odds->next = NULL;
        } else {
            odds->next = current;
            odds->next->next = NULL;
        }
        recursion(temp, odds->next, evens);
    }
}


