#include <iostream>
using namespace std;

class Stack
{
    int size, top, *buffer;
public:
    Stack(int sz)
    {
        top = -1;
        size = sz;
        buffer = new int[sz];
    }

    void push(int data)
    {
        if (top == size - 1)
            printf("Stack Full \n");
        else
            buffer[++top]=data;
    }
    int pop(){
        if(top==-1){
            printf("Stack is Empty \n");
            return -1;
        }
        else{
            int val=buffer[top];
            top--;
            return val;
        }
    }

    void disp(){
        printf("STACK : ");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",buffer[i]);
        }
        printf("\n");
    }
};

int main()
{
    const int MAX=10;
    Stack st(MAX);

    for (int i = 2; i <= 5; i++)
    {
        printf("Push : %d \n", i);
        st.push(i);
        st.disp();
    }

    for (int i = 1; i <= 2; i++)
    {
        printf("Pop \n");
        printf("Deleted value = %d \n", st.pop());
        st.disp();
    }
    return 0;
}