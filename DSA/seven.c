//singly Linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char usn[11];
    char name[25];
    int sem;
    char branch[5];
    unsigned long long phno;
};
typedef struct student STUD;

struct node {
    char usn[11];
    char name[25];
    int sem;
    char branch[5];
    unsigned long long phno;
    struct node *next;
};
typedef struct node NODE;

NODE *first = NULL;

// Function to create a new node from a student structure
NODE *copyNode(STUD s) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory cannot be allocated\n");
        return NULL;
    }
    strcpy(temp->usn, s.usn);
    strcpy(temp->name, s.name);
    strcpy(temp->branch, s.branch);
    temp->sem = s.sem;
    temp->phno = s.phno;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the end of the list
void addrear(STUD s) {
    NODE *temp = copyNode(s);
    if (temp == NULL) return;

    if (first == NULL) {
        first = temp;
        return;
    }
    NODE *cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
}

// Function to insert a node at the front of the list
void addfront(STUD s) {
    NODE *temp = copyNode(s);
    if (temp == NULL) return;

    if (first == NULL) {
        first = temp;
    } else {
        temp->next = first;
        first = temp;
    }
}

// Function to display a single node
void display(NODE *temp) {
    printf("%s\t%s\t%s\t%d\t%llu\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
}

// Function to delete a node from the front of the list
void deletefront() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    NODE *temp = first;
    first = first->next;

    printf("Deleted Node is:\n");
    display(temp);
    free(temp);
}

// Function to delete a node from the end of the list
void deleterear() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }

    NODE *cur = first, *prev = NULL;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) { // Only one node in the list
        first = NULL;
    } else {
        prev->next = NULL;
    }

    printf("Deleted Node is:\n");
    display(cur);
    free(cur);
}

// Function to display the entire list
void displayList() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("USN\tName\tBranch\tSem\tPhone\n");
    NODE *cur = first;
    while (cur != NULL) {
        display(cur);
        cur = cur->next;
    }
}

// Function to count the number of nodes in the list
int count() {
    NODE *cur = first;
    int c = 0;
    while (cur != NULL) {
        c++;
        cur = cur->next;
    }
    return c;
}

// Function to take student input
STUD input() {
    STUD s;
    printf("Enter USN: ");
    scanf("%s", s.usn);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Branch: ");
    scanf("%s", s.branch);
    printf("Enter Sem: ");
    scanf("%d", &s.sem);
    printf("Enter Phone no: ");
    scanf("%llu", &s.phno);
    return s;
}

// Main menu-driven program
int main() {
    STUD s;
    int i, ch, n;

    while (1) {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1. Create List of n students using front Insert\n");
        printf("2. Display the status and count the nodes\n");
        printf("3. Perform Insertion and Deletion at End of SLL\n");
        printf("4. Perform Insertion and Deletion at Front of SLL\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter the number of students: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++) {
                printf("\nEnter the details of student %d:\n", i);
                s = input();
                addfront(s);
            }
            break;

        case 2:
            printf(" Node Count = %d\n", count());
            displayList();
            break;

        case 3:
            printf("1. Insert at End\n2. Delete From End\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);
            if (ch == 1) {
                s = input();
                addrear(s);
            } else if (ch == 2) {
                deleterear();
            } else {
                printf("Invalid operation\n");
            }
            break;

        case 4:
            printf("1. Insert at Front\n2. Delete From Front\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);
            if (ch == 1) {
                s = input();
                addfront(s);
            } else if (ch == 2) {
                deletefront();
            } else {
                printf("Invalid operation\n");
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
