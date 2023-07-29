#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){

	FILE *fp=NULL;
	char s[MAX]={0};

	fp=fopen("sample1.txt","w");
	if(fp==NULL){
		printf("ERROR encountered during FILE creation \n");
		fclose(fp);
		exit(1);
	}

	printf("Enter data you want to store : ");
	if(fgets(s,MAX,stdin)==NULL){
		printf("ERROR in reading INPUT");
		fclose(fp);
		exit(1);
	}

	fwrite(s,sizeof(s[0]),MAX,fp);
	fclose(fp);
	printf("FILE has been SUCCESSFULLY CREATED \n");

	return 0;
}
