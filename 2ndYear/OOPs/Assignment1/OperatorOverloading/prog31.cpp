#include <iostream>
using namespace std;

class Complex
{
	float x, y;

public:
	Complex()
	{
		x = y = 0;
	}
	Complex(float a, float b)
	{
		x = a;
		y = b;
	}
	bool operator=(const Complex &ob)
	{
		if (x == ob.x && y == ob.y)
			return true;
		else
			return false;
	}
	Complex operator+(Complex const &ob)
	{
		Complex res;
		res.x = x + ob.x;
		res.y = y + ob.y;
		return res;
	}
	Complex operator-(Complex const &ob)
	{
		Complex res;
		res.x = x - ob.x;
		res.y = y - ob.y;
		return res;
	}
	Complex operator*(Complex const &ob)
	{
		Complex res;
		res.x = x * ob.x - y * ob.y;
		res.y = x * ob.y + y * ob.x;
		return res;
	}
	Complex operator/(Complex const &ob)
	{
		Complex res;
		float mag = ob.x * ob.x + ob.y * ob.y;
		res.x = x * ob.x + y * ob.y;
		res.y = y * ob.x - x * ob.y;
		res.x /= mag;
		res.y /= mag;
		return res;
	}

	void print()
	{
		if (y == 0)
		{
			printf("%f", x);
		}
		else if (y > 0)
		{
			printf("%f + %fi", x, y);
		}
		else
		{
			printf("%f - %fi", x, -y);
		}
	}
};

int main()
{
	Complex cn1(3, 1), cn2(2, 2);

	printf("Complex number 1 : ");
	cn1.print();
	printf("\n");
	printf("Complex number 2: ");
	cn2.print();
	printf("\n");
	if (cn1 = cn2)
	{
		printf("Equal complex numbers \n");
	}
	else
	{
		printf("Unequal complex numbers \n");
	}

	Complex cn3 = cn1 + cn2;
	Complex cn4 = cn1 - cn2;
	Complex cn5 = cn1 * cn2;
	Complex cn6 = cn1 / cn2;

	printf("Sum = ");
	cn3.print();
	printf("\n");
	printf("Difference = ");
	cn4.print();
	printf("\n");
	printf("Product = ");
	cn5.print();
	printf("\n");
	printf("Quotient = ");
	cn6.print();
	printf("\n");

	return 0;
}
