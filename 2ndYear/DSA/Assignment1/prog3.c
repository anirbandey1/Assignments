#include <stdio.h>
#include <stdlib.h>
#define sw 30

typedef struct Student{
    int Roll;
    char Name[sw];
    int Marks[0];
    int Avg;
} Student;

void InputStudent(Student *s);
void PrintStudent(Student *s);
Student* input(Student *Students,int*number);
void PrintHighest( Student *Students,int n);

void InputStudent(Student *s){
    char ch;

    printf("Roll No. : ");
    scanf("%u",&(s->Roll));
    printf("Name : ");
    scanf("%c",&ch);
    scanf("%[^\n]%*c",s->Name);
    printf("Enter marks in five subjects : ");
    int i=0,avg=0;
    for(i=0;i<5;i++){
	scanf("%d",&(s->Marks[i]));
	avg+=s->Marks[i];
    }
    avg/=5;
    s->Avg=avg;
    printf("Average : %d \n",(s->Avg));

}
void PrintStudent(Student *s){

    printf("Roll No. : %u \n",s->Roll);
    printf("Name : ");
    puts(s->Name);
    printf("Average : %u \n",s->Avg);
    printf("\n");

}

Student* input(Student *Students,int *number){
    int i,n;
    printf("Number of Students : ");
    scanf("%d",&n);
    *number=n;

    Students = (Student *)malloc(n*sizeof(Student));

    for(i=0;i<n;i++){
        printf("Student no. %d \n",i+1);
        InputStudent(&Students[i]);
    }
    return (Students);
}


void sort(Student *Students, int n){
	int i,j,pos;
	Student 
	
	for(i=0;i<n;i++)
	{

		for(j=i+1,j<n;j++)
		{
			


		}
	}




}

void PrintHighest( Student *Students,int n){

        int *arr=(int *)calloc(n,sizeof(int));
	int i,j,pos;

	for(i=0;i<n;i++){
		arr[i]=i;
	}
        for(i=0;i<n;i++)
        {
		pos=i;
                for(j=i+1,j<n;j++)
                {
			if(St)


                }
        }

    int i=0;
    for(i=0;i<n;i++){
        if(1){
            PrintStudent(&Students[i]);
	}
    }
}

int main(){

    Student *Students;
    int n;
    Students =input(Students,&n);

    int r;
    printf("\n");

    printf("\n");
    PrintHighest(Students,n);

    return 0;
}

