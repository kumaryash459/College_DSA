// Given a File of N employee records with a set K of Keys (4-digit) which uniquely
// determine the records in file F. Assume that file F is maintained in memory by a Hash
// Table (HT) of m memorylocations with L as the set of memory addresses (2-digit) of
// locations in HT. Let the keys in K andaddresses in L are Integers.
// Develop a Program in C that uses Hash function H: K →L as H(K)=K mod m
// (remainder method), and implement hashing technique to map a given key K to the
// address space L. Resolve the collision (if any) using linear probing

#include <stdio.h>
#define m 5
int HT[10];
int hash(int key)
{
    return key % m;
}
void linear_probe(int hk, int key)
{
    int i, flag = 0;
    for (i = hk + 1; i < m; i++)
    {
        if (HT[i] == 999)
        {
            HT[i] = key;
            flag = 1;
            break;
        }
        for (i = 0; i < hk && flag == 0; i++)
        {
            if (HT[i] == 999)
            {
                HT[i] = key;
                flag = 1;
                break;
            }
        }
        if (!flag)
            printf("HASH Table is Full!!!\n");
    }
}
int main()
{
    FILE *fp;
    int N, i, key, hk;
    char name[100];
    // clrscr();
    for (i = 0; i < m; i++)
        HT[i] = 999;
    fp = fopen("emp.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%d%s", &key, name);
        hk = hash(key);
        if (HT[hk] == 999)
            HT[hk] = key;
        else
        {
            printf("Collision for key %d:\n", key);
            printf("Collision solved by Linear Probing\n\n");
            linear_probe(hk, key);
        }
    }
    printf("-------------------------------\n");
    printf("HASH TABLE\n");
    printf("-------------------------------\n");
    printf("Address\tKeys\n");
    for (i = 0; i < m; i++)
        printf("%d\t%d\n", i, HT[i]);
    // gech();
}