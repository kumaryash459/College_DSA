//  b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store
// theresult in POLYSUM(x,y,z).
// Support the program with appropriate functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef, px, py, pz, flag;
    struct node *link;
};
typedef struct node *NODE;

// Function Prototypes
NODE create_list(NODE head);
NODE insert(NODE head, int coef, int px, int py, int pz);
NODE add_poly(NODE h1, NODE h2, NODE h3);
void display(NODE head);

NODE create_list(NODE head) {
    int i, n, cf, px, py, pz;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter the Coefficient, px, py, pz: ");
        scanf("%d %d %d %d", &cf, &px, &py, &pz);
        head = insert(head, cf, px, py, pz);
    }
    return head;
}

NODE insert(NODE head, int coef, int px, int py, int pz) {
    NODE cur, tmp;
    tmp = (NODE)malloc(sizeof(struct node)); // Allocate memory
    tmp->coef = coef;
    tmp->px = px;
    tmp->py = py;
    tmp->pz = pz;
    tmp->flag = 0;
    tmp->link = head;

    if (head->link == head) {
        head->link = tmp;
    } else {
        cur = head->link;
        while (cur->link != head) { // Find the last node
            cur = cur->link;
        }
        cur->link = tmp;
    }
    tmp->link = head; // Complete the circular connection
    return head;
}

NODE add_poly(NODE h1, NODE h2, NODE h3) {
    NODE cur1 = h1->link, cur2, temp;
    while (cur1 != h1) { // Traverse Polynomial 1
        cur2 = h2->link;
        int found = 0;
        while (cur2 != h2) { // Traverse Polynomial 2
            if (cur1->px == cur2->px && cur1->py == cur2->py && cur1->pz == cur2->pz) {
                int sum_coef = cur1->coef + cur2->coef;
                if (sum_coef != 0) {
                    h3 = insert(h3, sum_coef, cur1->px, cur1->py, cur1->pz);
                }
                cur2->flag = 1;
                found = 1;
                break;
            }
            cur2 = cur2->link;
        }
        if (!found) { // If no match found, insert the term from Polynomial 1
            h3 = insert(h3, cur1->coef, cur1->px, cur1->py, cur1->pz);
        }
        cur1 = cur1->link;
    }

    cur2 = h2->link;
    while (cur2 != h2) { // Insert remaining terms from Polynomial 2
        if (cur2->flag == 0) {
            h3 = insert(h3, cur2->coef, cur2->px, cur2->py, cur2->pz);
        }
        cur2 = cur2->link;
    }
    return h3;
}

void display(NODE head) {
    NODE cur;
    if (head->link == head) {
        printf("List is empty\n");
        return;
    }
    cur = head->link;
    while (cur != head) {
        if (cur->coef > 0) {
            printf(" +%dx^%dy^%dz^%d", cur->coef, cur->px, cur->py, cur->pz);
        } else {
            printf(" %dx^%dy^%dz^%d", cur->coef, cur->px, cur->py, cur->pz);
        }
        cur = cur->link;
    }
    printf("\n");
}

int main() {
    NODE head1, head2, head3;
    head1 = (NODE)malloc(sizeof(struct node));
    head1->link = head1; // Initialize Polynomial 1
    head2 = (NODE)malloc(sizeof(struct node));
    head2->link = head2; // Initialize Polynomial 2
    head3 = (NODE)malloc(sizeof(struct node));
    head3->link = head3; // Initialize Polynomial Sum

    printf("\nCreate Polynomial 1:\n");
    head1 = create_list(head1);

    printf("\nCreate Polynomial 2:\n");
    head2 = create_list(head2);

    printf("\nPolynomial 1 is:");
    display(head1);

    printf("\nPolynomial 2 is:");
    display(head2);

    head3 = add_poly(head1, head2, head3); // Add both polynomials

    printf("\nAddition of two Polynomials is:");
    display(head3);
}
