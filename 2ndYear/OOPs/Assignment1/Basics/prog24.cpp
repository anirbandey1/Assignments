#include <iostream>
using namespace std;

class A
{
    int data;

public:
    A(int x)
    {
        data = x;
    }
    int get() const;
    void set(int);
};

int A::get() const
{
    return data;
}
void A::set(int x)
{
    data = x;
}

int main()
{

    A ob(6);
    printf("Initially, data = %d \n",ob.get());
    ob.set(3);
    printf("Finally, data = %d \n",ob.get());

    return 0;
}