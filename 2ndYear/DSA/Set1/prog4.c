#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Term{
	float coeff;
	int pow;
}Term;

typedef struct Poly{
	int terms_size;
	Term *terms;
}Poly;

void printTerm(Term *term){
	printf("%.3fx^%d ",term->coeff,term->pow);
}
Term* newTerm(float c,int p){
	Term* term=(Term*)malloc(sizeof(Term));
	term->coeff=c;
	term->pow=p;
	return term;
}

Poly* inputPoly(Poly* poly){

	int i,n;
	float c;
	int p;
/*
	printf("Enter number of terms in polynomial : ");
	scanf("%d",&n);
	printf("Enter %d terms :- \n",n);

	Poly* poly=(Poly*)malloc(sizeof(Poly));
	poly->terms_size=n;

	poly->terms=(Term*)malloc(n*sizeof(Term));
*/

	n=poly->terms_size;
	printf("Enter %d terms :- \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%f%d",&c,&p);
		//poly->terms[i]=*newTerm(c,p);
		
		poly->terms[i].coeff=c;
		poly->terms[i].pow=p;
	}
	return poly;
}

float evalPoly(Poly*poly,float x){

	float ans=0;
	int i=0,n=poly->terms_size;
	for(i=0;i<n;i++)
	{
		ans+= poly->terms[i].coeff*pow(x,poly->terms[i].pow);
	}
	return ans;
}
void printPoly(Poly *poly){
	
	int i=0,n=poly->terms_size;
	printf("Polynomial : ");
	
	for(i=0;i<n;i++)
	{
		printTerm(&(poly->terms[i]));

		if(i!=n-1){
			printf(" + ");
		}
	}
	printf("\n");
}

int main(){

//	Poly *poly=inputPoly();

	int n;
	printf("Enter number of terms in polynomial : ");
        scanf("%d",&n);
        Poly* poly=(Poly*)malloc(sizeof(Poly));
        poly->terms_size=n;
	poly->terms=(Term*)malloc(n*sizeof(Term));

	poly=inputPoly(poly);
	printPoly(poly);
	
	float x;
	printf("Enter value of x : ");
	scanf("%f",&x);

	float ans=evalPoly(poly,x);
	printf("Answer = %f \n",ans);

	return 0;
}
