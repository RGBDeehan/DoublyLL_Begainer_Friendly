#include "DLL.h"

/*
UNDERSTANDING DOUBLE POINTER (**head)
--------------------------------------
If head = 1000 and *head = address of first node (say 2000)
then **head = value stored in that first node (say 45)

We use **head so the function can directly modify the 'head'
pointer of the linked list in main().
*/

int create_node(struct node **newNode, int data)
{
    *newNode = (struct node *)malloc(sizeof(struct node)); // allocate memory for a new node

    // store data and initialize both links
    (*newNode)->data = data;
    (*newNode)->prev = NULL;
    (*newNode)->next = NULL;
    return 0;
}

int insert_first(struct node **head, int data)
{
    struct node *newNode;
    create_node(&newNode, data); // create a new node

    // link new node with current head
    newNode->next = *head;

    // if list not empty, update previous link of old head
    if (*head != NULL)
        (*head)->prev = newNode;

    // make newNode the new head
    *head = newNode;
    return 0;
}

int insert_last(struct node **head, int data)
{
    struct node *newNode, *ptr;
    create_node(&newNode, data); // create new node

    // if list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return 0;
    }

    // go to last node
    ptr = *head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    // link new node after last node
    ptr->next = newNode;
    newNode->prev = ptr;

    return 0;
}

int insert_in_between(struct node **head, int pos, int data)
{
    // if list is empty
    if (*head == NULL)
        return 1;

    struct node *ptr = *head;
    int i = 0;

    // move pointer to the desired position
    while (ptr != NULL && i < pos)
    {
        ptr = ptr->next;
        i++;
    }

    // if position doesn't exist
    if (ptr == NULL)
        return 1;

    struct node *newNode;
    create_node(&newNode, data);

    // connect newNode links
    newNode->next = ptr->next;
    newNode->prev = ptr;

    // connect existing nodes to new node
    if (ptr->next != NULL)
        ptr->next->prev = newNode;
    ptr->next = newNode;

    return 0;
}

int delete_node(struct node **head, int pos)
{
    if (*head == NULL)
        return 1;

    struct node *ptr = *head;
    int i = 0;

    // move to the position to delete
    while (ptr != NULL && i < pos)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL)
        return 1;

    // if deleting first node
    if (ptr->prev == NULL)
        *head = ptr->next;
    else
        ptr->prev->next = ptr->next;

    // if not the last node
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr); // free memory of deleted node
    return 0;
}

void print_list(const struct node *head)
{
    const struct node *ptr = head;
    printf("\nDoubly Linked List: ");
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // print all nodes
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_list(struct node **head)
{
    struct node *ptr = *head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp); // free current node
    }
    *head = NULL; // make head NULL after freeing
}
