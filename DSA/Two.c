/*2. Design, develop and Implement a Program in C for the following operations on Strings
a. Read a main String (STR),
b. Pattern String (PAT) and a Replace String (REP)
c. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in
STR with REP if PAT exists in STR.
Report suitable messages in case PAT does not exist in STR. Support the program with
functions for each of the above operations. Don't use Built-in functions.*/

#include <stdio.h>
#include <conio.h>
char Mainstr[100], Pat[100], Replace[100], ans[100];
int i, j, c, m, k;
void read()
{
    printf("\nEnter a string \n");
    gets(Mainstr);
    printf("\nEnter a search string \n");
    gets(Pat);
    printf("\nEnter a replace string \n");
    gets(Replace);
}
void find_replace()
{
    i = m = c = j = 0;
    while (Mainstr[c] != '\0')
    {
        if (Mainstr[m] == Pat[i]) // matching
        {
            i++;
            m++;
            if (Pat[i] == '\0') // found occ
            {
                //.... copy replace string in ans string .....
                for (k = 0; Replace[k] != '\0'; k++, j++)
                {
                    ans[j] = Replace[k];
                }
                i = 0;
                c = m;
            }
        }
        else //... mismatch
        {
            ans[j] = Mainstr[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
    printf("\nThe resultant string is\n%s", ans);
}
void main()
{
    // clrscr();
    read();
    find_replace();
    getch();
}