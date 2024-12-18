#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char ssn[11];
    char name[21];
    char dept[15];
    char design[15];
    int salary;
    unsigned long long phno;
};
typedef struct employee EMP;

struct node {
    char ssn[11];
    char name[21];
    char dept[15];
    char design[15];
    int salary;
    unsigned long long phno;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;

NODE *first = NULL;

// Function to create a new node from employee data
NODE* copyNode(EMP e) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory cannot be allocated\n");
        return NULL;
    }
    strcpy(temp->ssn, e.ssn);
    strcpy(temp->name, e.name);
    strcpy(temp->dept, e.dept);
    strcpy(temp->design, e.design);
    temp->salary = e.salary;
    temp->phno = e.phno;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert a node at the rear
void addrear(EMP e) {
    NODE *temp = copyNode(e);
    if (temp == NULL) return;

    if (first == NULL) {
        first = temp;
    } else {
        NODE *cur = first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->prev = cur;
    }
}

// Function to insert a node at the front
void addfront(EMP e) {
    NODE *temp = copyNode(e);
    if (temp == NULL) return;

    if (first == NULL) {
        first = temp;
    } else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

// Function to display a single node
void display(NODE *r) {
    printf("%s\t%s\t%s\t%s\t%d\t%llu\n", r->ssn, r->name, r->dept, r->design, r->salary, r->phno);
}

// Function to delete a node from the front
void deletefront() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    NODE *temp = first;
    if (first->next == NULL) {
        first = NULL;
    } else {
        first = first->next;
        first->prev = NULL;
    }
    printf("Deleted Node:\n");
    display(temp);
    free(temp);
}

// Function to delete a node from the rear
void deleterear() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    NODE *cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    if (cur->prev == NULL) { // Only one node in the list
        first = NULL;
    } else {
        cur->prev->next = NULL;
    }
    printf("Deleted Node:\n");
    display(cur);
    free(cur);
}

// Function to display the entire list
void displayList() {
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("SSN\tName\tDept\tDesignation\tSalary\tPhone\n");
    NODE *r = first;
    while (r != NULL) {
        display(r);
        r = r->next;
    }
}

// Function to count the number of nodes in the list
int count() {
    NODE *n = first;
    int c = 0;
    while (n != NULL) {
        c++;
        n = n->next;
    }
    return c;
}

// Function to input employee details
EMP input() {
    EMP e;
    printf("Enter SSN: ");
    scanf("%s", e.ssn);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Dept: ");
    scanf("%s", e.dept);
    printf("Enter Designation: ");
    scanf("%s", e.design);
    printf("Enter Salary: ");
    scanf("%d", &e.salary);
    printf("Enter Phone no: ");
    scanf("%llu", &e.phno);
    return e;
}

// Main function with menu-driven operations
int main() {
    EMP e;
    int ch, n, i;

    while (1) {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1. Create a DLL of N Employees Data by using end insertion\n");
        printf("2. Display the status of DLL and count the number of nodes in it\n");
        printf("3. Perform Insertion and Deletion at End of DLL\n");
        printf("4. Perform Insertion and Deletion at Front of DLL\n");
        printf("5. Demonstration of this DLL as Double Ended Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of Employees: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter the details of Employee %d:\n", i);
                    e = input();
                    addrear(e);
                }
                break;

            case 2:
                if (first == NULL) {
                    printf("List is Empty\n");
                } else {
                    printf("Node Count = %d\n", count());
                    displayList();
                }
                break;

            case 3:
                printf("1. Insert at End\n2. Delete From End\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                if (ch == 1) {
                    e = input();
                    addrear(e);
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
                    e = input();
                    addfront(e);
                } else if (ch == 2) {
                    deletefront();
                } else {
                    printf("Invalid operation\n");
                }
                break;

            case 5:
                printf("This DLL can be used as a Double Ended Queue by inserting and deleting from both ends.\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
