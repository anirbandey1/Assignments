#include <stdio.h>
#include <stdlib.h>
#define sw 30

typedef struct Student{
    int Roll;
    char Name[sw];
    char Dept[sw];
    int YoJ;
} Student;

void InputStudent(Student *s);
void PrintStudent(Student *s);
Student* input(Student *Students,int*number);
void PrintStuYear( int y,Student *Students,int n);
void PrintStuRoll( int r,Student *Students,int n);

void InputStudent(Student *s){
    char ch;

    printf("Roll No. : ");
    scanf("%u",&(s->Roll));
    printf("Name : ");
    scanf("%c",&ch);
    scanf("%[^\n]%*c",s->Name);
    printf("Department : ");
    scanf("%[^\n]%*c",s->Dept);
    printf("Year of Joining : ");
    scanf("%u",&(s->YoJ));

}
void PrintStudent(Student *s){

    printf("Roll No. : %u \n",s->Roll);
    printf("Name : ");
    puts(s->Name);
    printf("Department : ");
    puts(s->Dept);
    printf("Year of Joining : %u \n",s->YoJ);
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


void PrintStuYear( int y,Student *Students,int n){

    int i=0;
    for(i=0;i<n;i++){
        if(y==(Students[i].YoJ)){
            PrintStudent(&Students[i]);
        }
    }
}

void PrintStuRoll( int r,Student *Students,int n){

    int i=0;
    for(i=0;i<n;i++){
        if(r==(Students[i].Roll)){
            PrintStudent(&Students[i]);
        }
    }
}

int main(){

    Student *Students;
    int n;
    Students =input(Students,&n);

    int y,r;
    printf("\n");
    printf("Enter the Year of Joining : ");
    scanf("%u",&y);
    printf("\n");
    PrintStuYear(y,Students,n);

    printf("Enter the Roll No. : ");
    scanf("%u",&r);
    printf("\n");
    PrintStuRoll(r,Students,n);

    return 0;
}
