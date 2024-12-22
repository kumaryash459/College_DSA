// Given a File of N employee records with a set K of Keys (4-digit) which uniquely
// determine the records in file F. Assume that file F is maintained in memory by a Hash
// Table (HT) of m memorylocations with L as the set of memory addresses (2-digit) of
// locations in HT. Let the keys in K andaddresses in L are Integers.
// Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m
// (remainder method), and implement hashing technique to map a given key K to the
// address space L. Resolve the collision (if any) using linear probing

#include <stdio.h>
#define m 5 // Hash table size

int HT[m]; // Hash table array

// Hash function: Remainder method
int hash(int key) {
    return key % m;
}

// Function to handle collisions using linear probing
void linear_probe(int hk, int key) {
    int i, flag = 0;
    // Check from hk+1 to the end of the hash table
    for (i = (hk + 1) % m; i != hk; i = (i + 1) % m) {
        if (HT[i] == 999) { // Empty slot found
            HT[i] = key;
            flag = 1;
            break;
        }
        if (i == m - 1) i = -1; // Wrap around to the beginning
    }

    if (!flag) {
        printf("HASH Table is Full!!!\n");
    }
}

int main() {
    FILE *fp;
    int key, hk, i;
    char name[100];

    // Initialize hash table with 999 (indicates empty slots)
    for (i = 0; i < m; i++) {
        HT[i] = 999;
    }

    // Open the employee file
    fp = fopen("emp.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the file and insert keys into the hash table
    while (fscanf(fp, "%d %s", &key, name) == 2) {
        hk = hash(key); // Compute hash value
        if (HT[hk] == 999) { // If slot is empty
            HT[hk] = key;
        } else { // Collision occurs
            printf("Collision for key %d:\n", key);
            printf("Collision solved by Linear Probing\n\n");
            linear_probe(hk, key);
        }
    }

    fclose(fp);

    // Display the hash table
    printf("-------------------------------\n");
    printf("HASH TABLE\n");
    printf("-------------------------------\n");
    printf("Address\tKeys\n");
    for (i = 0; i < m; i++) {
        if (HT[i] != 999)
            printf("%d\t%d\n", i, HT[i]);
        else
            printf("%d\tEMPTY\n", i);
    }

    return 0;
}
