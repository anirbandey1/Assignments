#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Device;

class Point
{
    float x, y;

public:
    Point()
    {
        this->x = this->y = 0;
    }
    void set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float operator-(const Point &ob)
    {
        float dist = 0;
        dist += (x - ob.x) * (x - ob.x);
        dist += (y - ob.y) * (y - ob.y);
        dist = sqrt(dist);
        return dist;
    }
};

class Device
{
    int id;
    Point p;
    float r;

public:
    Device(int id, float x, float y, float r)
    {
        this->id = id;
        this->p.set(x, y);
        this->r = r;
    }
    int getId()
    {
        return id;
    }
    bool canSend(const Device &ob)
    {
        float dist = this->p - ob.p;
        return this->r >= dist;
    }

    void print()
    {
        printf("Device :- \n");
        printf("ID : %d \n", id);
        printf("Coordinates : (%.f,%.f) \n", p.getX(), p.getY());
        printf("Range is a Circle of Radius %.f \n", r);
    }
};

int rN()
{
    int lower = 0;
    int upper = 100;
    return rand() % (upper - lower + 1) + lower;
}
int main()
{
    int n = 10;
    Device **dev;
    dev = (Device **)malloc(n * sizeof(Device *));
    for (int tt = 1; tt <= 2; tt++)
    {
        if(tt==1){
            printf("\n Intitially, \n\n");
        }
        else if(tt==2){
            printf("\n After moving each device to a new random location \n\n");
        }
        for (int i = 0; i < n; i++)
        {

            dev[i] = new Device(i + 1, rN(), rN(), rN());
            dev[i]->print();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (dev[i]->canSend(*dev[j]))
                {
                    printf("Device %d can send message to Device %d \n", dev[i]->getId(), dev[j]->getId());
                }
            }
        }
    }
    return 0;
}