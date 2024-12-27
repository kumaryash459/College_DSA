/* PROGRAM 5A
Design, develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

int stack[MAX];
char post[MAX];
int top = -1;

void pushstack(int tmp);
void calculator(char c);

int main()
{
    int i;
    printf("Insert a postfix notation :: ");
    scanf("%s", post);
    
    for (i = 0; i < strlen(post); i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            pushstack(i);
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
        {
            calculator(post[i]);
        }
    }

    printf("\n\nResult :: %d\n", stack[top]);
    return 0;
}

void pushstack(int tmp)
{
    top++;
    stack[top] = post[tmp] - '0'; // Convert char to int
}

void calculator(char c)
{
    int a, b, ans;
    b = stack[top--];
    a = stack[top--];

    switch (c)
    {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        case '^':
            ans = pow(a, b);
            break;
        default:
            ans = 0;
    }

    stack[++top] = ans;
}


