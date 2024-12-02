/* 5b.c Tower of Honoi */

#include <stdio.h>

// Function to move disks in Tower of Hanoi
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n MOVE DISK 1 FROM PEG %c TO PEG %c", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n MOVE DISK %d FROM PEG %c TO PEG %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;

    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    // Show the sequence of moves
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towers(num, 'A', 'C', 'B');  // A, B, and C are the names of the rods

    return 0;
}
