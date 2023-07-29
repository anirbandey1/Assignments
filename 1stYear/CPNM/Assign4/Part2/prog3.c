#include <stdio.h>

int main(){

	char c;
	FILE *fp;
	fp=fopen("prog3.c","r");
	
	do{
		c=getc(fp);
		putchar(c);

	}while(c!=EOF);

	fclose(fp);
	return 0;
}
