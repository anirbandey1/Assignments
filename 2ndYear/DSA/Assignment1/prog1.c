#include <stdio.h>
#include <stdlib.h>
#define sw 30

typedef struct State{
    char Name[sw];
    int eng;
    int med;
    int mng;
    int uni;
} State;

void InputState(State *s);
void PrintState(State *s);
State* input(State *States,int*number);
void PrintStuYear( int y,State *States,int n);
void PrintStuRoll( int r,State *States,int n);

void InputState(State *s){
    char ch;

    printf("Name : ");
    scanf("%c",&ch);
    scanf("%[^\n]%*c",s->Name);
    printf("No. of Engineering Colleges : ");
    scanf("%u",&(s->eng));
    printf("No. of Medical Colleges : ");
    scanf("%u",&(s->med));
    printf("No. of Management Colleges : ");
    scanf("%u",&(s->mng));
    printf("No. of Universities : ");
    scanf("%u",&(s->uni));


}
void PrintState(State *s){

    printf("Name : ");
    puts(s->Name);
    printf("No. of Engineering Colleges : %u \n",s->eng);
    printf("No. of Medical Colleges : %u \n",s->med);
    printf("No. of Management Colleges : %u \n",s->mng);
    printf("No. of Universities : %u \n",s->uni);
    printf("\n");

}

int total(State *s){
	return s->eng+s->med+s->mng+s->uni;
}
State* input(State *States,int *number){
    int i,n;
    printf("Number of States : ");
    scanf("%d",&n);
    *number=n;

    States = (State *)malloc(n*sizeof(State));

    for(i=0;i<n;i++){
        printf("State no. %d \n",i+1);
        InputState(&States[i]);
    }
    return (States);
}


void PrintHighest( State *States,int n){

    State *best=States;
    int i=0;
    for(i=0;i<n;i++){
        if(total(best)<total(&States[i])){
            best=States+i;       
        }
    }

    PrintState(best);
}

int main(){

    State *States;
    int n;
    States =input(States,&n);

    int eng;
    printf("\n");
    
    printf("State with the Highest number of Colleges \n");
    PrintHighest(States,n);

    return 0;
}

