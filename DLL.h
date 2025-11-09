#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

/*
===========================================
 DOUBLY LINKED LIST STRUCTURE & FUNCTION DECLARATIONS
-------------------------------------------
 This header file tells the compiler:
 “These are the functions and structures
 you’ll find in DLL.c.”

 We only *declare* things here, not define.
===========================================
*/

// Each node stores data and two links (previous and next)
struct node
{
    int data;              // stores value
    struct node *prev;     // link to previous node
    struct node *next;     // link to next node
};

// ===== Function Declarations =====

// Creates a new node with given data
int create_node(struct node **newNode, int data);

// Insert node at the beginning of the list
int insert_first(struct node **head, int data);

// Insert node at the end of the list
int insert_last(struct node **head, int data);

// Insert node after a given position (0-based index)
int insert_in_between(struct node **head, int pos, int data);

// Delete a node at a given position
int delete_node(struct node **head, int pos);

// Print all elements of the list
void print_list(const struct node *head);

// Free the entire list from memory
void free_list(struct node **head);

#endif
