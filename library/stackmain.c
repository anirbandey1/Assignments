
#include <stdio.h>
#include "stackl.h"

int getData()
{
    printf("Enter the data : ");
    int data = -1;
    scanf("%d", &data);
    return data;
}
int getChoice()
{
    printf("Enter your choice : ");
    int data = -1;
    scanf("%d", &data);
    return data;
}

void prompt()
{
    printf("\n");
    printf("Press 1 to Print the Stack \n");
    printf("Press 2 to Push an element into the Stack \n");
    printf("Press 3 to Pop an element from the Stack \n");
    printf("Press 4 to Print the Stack size \n");
    printf("Print 9 to Exit \n");
}
int main()
{

    Stack *st = newStack();
    int ch = -1;
    int data = -1;
    while (ch != 9)
    {
        prompt();
        ch = getChoice();
        switch (ch)
        {
        case 1:
            printStack(st);
            break;
        case 2:
            data = getData();
            push(st, data);
            break;
        case 3:
            data = pop(st);
            printf("%d was popped \n", data);
            break;
        case 4:
            data = stackSize(st);
            printf("Stack size is %d \n", data);
            break;
        case 9:
            printf("Thank You \n");
            break;
        default:
            printf("Please select a Valid Option ");
            break;
        }
    }

    return 0;
}