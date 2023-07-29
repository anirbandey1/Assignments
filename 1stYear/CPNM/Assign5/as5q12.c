#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double epsilon = 0.001;

double f (double x) {
	return (pow(x, 3) - 1);
}

double Simpson_1third (double a, double b, double h) {
	double x[100], y[100], sum_even = 0, sum_odd = 0, integ = 0;
	int i, n;
	n = (b - a)/h;
	if (n % 2)	n++;
	h = (b - a)/n;
	for(i = 0; i <= n; i++)
    {
        x[i] = a + i*h;
        y[i] = f(x[i]);
    }
	printf ("\nFOR SIMPSON'S 1/3RD METHOD:\n");
	printf("a = %.4lf, b = %.4lf, h = %.4lf, n = %d\nx:\t", a, b, h, n);
	for(i = 0; i <= n; i++)
        printf ("%4.4lf\t", x[i]);
    printf ("\nf(x):\t");
	for(i = 0; i <= n; i++)
        printf ("%4.4lf\t", y[i]);
	printf ("\n");
	for(i = 1; i < n; i++)
    {
        if(i%2)
            sum_odd += y[i];
        else
            sum_even += y[i];

    }
   integ = (h/3)*(y[0] + y[n] + (4 * sum_odd) + (2 * sum_even));
   return integ;
}

double Trapezoidal (double a, double b, double h) {
	double x[100], y[100], sum = 0, integ = 0;
	int i, n;
	n = (b - a)/h;
	for(i = 0; i <= n; i++)
    {
        x[i] = a + i*h;
        y[i] = f(x[i]);
    }
	printf ("FOR TRAPEZOIDAL METHOD:\n");
	printf("a = %.4lf, b = %.4lf, h = %.4lf, n = %d\nx:\t", a, b, h, n);
	for(i = 0; i <= n; i++)
        printf ("%4.4lf\t", x[i]);
    printf ("\nf(x):\t");
	for(i = 0; i <= n; i++)
        printf ("%4.4lf\t", y[i]);
	printf ("\n");
	for(i = 1; i < n; i++)
        sum += y[i];
   integ = (h/2)*(y[0] + y[n] + (2 * sum));
   return integ;
}

int main(int argc, char **argv) {
	double a, b, h, trapezoidal, simpsons1third;
	if (argc < 3)  {
		printf ("Too few arguments!\n");
		return 0;
	}
	else {
		a = atof(argv[1]);
		b = atof(argv[2]);
	}
	printf ("INTEGRATION METHODS::\n");
	printf ("Enter the value of h: ");
	scanf ("%lf", &h);
	trapezoidal = Trapezoidal(a, b, h);
	simpsons1third = Simpson_1third(a, b, h);
	printf("\nValue of integrand (by Trapezoidal method) = %.4lf\n", trapezoidal);
	printf ("Value of integrand (by Simpson's 1/3rd method) = %.4lf\n", simpsons1third);
	return 0;
}

