#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

int main()
{
    struct node *head = NULL;
    int result, data, pos, choice;

    printf("===== Doubly Linked List Program =====\n");

    while (1) // keep running until user exits
    {
        printf("\nChoose an option:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert in between (at position)\n");
        printf("4. Delete a node (by position)\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert_first(&head, data);
            printf("Inserted %d at the beginning.\n", data);
        }

        else if (choice == 2)
        {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert_last(&head, data);
            printf("Inserted %d at the end.\n", data);
        }

        else if (choice == 3)
        {
            printf("Enter position (0-based index): ");
            scanf("%d", &pos);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            result = insert_in_between(&head, pos, data);
            if (result == 0)
                printf("Inserted %d after position %d.\n", data, pos);
            else
                printf("Invalid position.\n");
        }

        else if (choice == 4)
        {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            result = delete_node(&head, pos);
            if (result == 0)
                printf("Deleted node at position %d.\n", pos);
            else
                printf("Invalid position or empty list.\n");
        }

        else if (choice == 5)
        {
            print_list(head);
        }

        else if (choice == 6)
        {
            printf("Exiting program...\n");
            free_list(&head);
            break;
        }

        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
