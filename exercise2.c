/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */
    /* post-condition: stack is empty */
    s->head = NULL;
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    /* post-condition: x is added to top of stack */
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("fejl\n");
        exit(1);
    }

    new_node->data = x;
    new_node->next = s->head;
    s->head = new_node;

}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */

    if (s->head == NULL) {
        print ("fejl\n"); //stopper hvis stacken er tom
        exit(1);
    }

    node *temp = s->head; // midlertidig pointer til toppen af stacken
    int value = temp->data; // gemmer værdien af toppen
    s->head = s->head->next; // opdaterer toppen til næste element
    free(temp); // frigør den gamle top-node

  return value; // returnerer værdien af den fjernede top
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false; // linked list stack kan altid vokse
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */
    if (s->head == NULL) {
        return true; // stacken er tom
    } else {
        return false; // stacken er ikke tom
    }
}

/* Print the contents of the stack */
void print(stack *s)
{
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */

if (s->head == NULL) {
        printf("Stacken er tom.\n");
        return;
    }

    node *current = s->head;
    printf("Stack indhold (top til bund): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

}
