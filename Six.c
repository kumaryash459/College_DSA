#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int q[SIZE], i, r = -1, f = 0, option, count = 0;

int main()
{
    for (;;)
    {
        printf("\n1. Insert  2. Delete\n3. Display  4. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: // Inserting items into Queue
            if (count == SIZE)
                printf("\nQueue is Full\n");
            else
            {
                r = (r + 1) % SIZE;
                printf("\nEnter the item: ");
                scanf("%d", &q[r]);
                count++;
            }
            break;

        case 2: // Deleting items from Queue
            if (count == 0)
                printf("\nQueue is Empty\n");
            else
            {
                printf("\nDeleted item is: %d", q[f]);
                f = (f + 1) % SIZE;
                count--;
            }
            break;

        case 3: // Displaying items in Queue
            if (count == 0)
                printf("\nQueue is Empty\n");
            else
            {
                printf("\nQueue items are: ");
                for (i = 0; i < count; i++)
                {
                    printf("%d ", q[(f + i) % SIZE]);
                }
                printf("\n");
            }
            break;

        case 4: // Exit
            exit(0);

        default:
            printf("\nInvalid option. Please try again.\n");
        }
    }
    return 0;
}
