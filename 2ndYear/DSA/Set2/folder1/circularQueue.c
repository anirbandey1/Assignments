#include<stdio.h>
#include<stdlib.h>
int z;
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

struct Node *fl;
struct Node *rl;
 
struct Node{
    int data;
    struct Node *next;
};

void create_queue_using_array(struct queue* q, int size){
    q->size = size;
    q->f =  -1;
    q->r = -1;
    q->arr = (int*) malloc(q->size*sizeof(int));
}
 
 
int is_empty_using_array(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}
 
int is_full_using_array(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue_using_array(struct queue *q, int val){
    if(is_full_using_array(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int number_of_elements_using_array(struct queue* q){
    if(is_empty_using_array(q)){
        return 0;
    }
    return q->r - q->f;
}
 
int dequeue_using_array(struct queue *q){
    int val = -1;
    if(is_empty_using_array(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

void create_queue_using_linked_list(){
    fl = NULL;
    rl = NULL;
}

int is_full_using_linked_list(){
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    return n == NULL;
}

int is_empty_using_linked_list(){
    return fl == NULL;
}
 
void enqueue_using_linked_list(int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(is_full_using_linked_list()){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(fl == NULL){
            fl = rl = n;
        }
        else{
            rl->next = n;
            rl = n;
        }
    }
}
 
int dequeue_using_linked_list(){
    int val = -1;
    struct Node *ptr = fl;
    if(is_empty_using_linked_list()){
        printf("Queue is Empty\n");
    }
    else{
        fl = fl->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int number_of_elements_using_linked_list(){
    if(is_empty_using_linked_list()){
        return 0;
    }
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    int size = 0;
    temp = fl->next;
    while(temp){
        temp = temp->next;
        size++;
    }
    return size + 1;
}

void print_options(int op){
  if(op==1){
    printf("1. Enqueue \n");
    printf("2. Dequeue\n");
    printf("3. is full (overflow)\n");
    printf("4.is empty (underflow)\n");
    printf("5. size\n");
    printf("6. Exit\n");
    printf("Enter choice ");
  }
  else{
    printf("1. Enqueue \n");
    printf("2. Dequeue\n");
    printf("3.Is empty (underflow)\n");
    printf("4. size\n");
    printf("5. Exit\n");
    printf("Enter choice ");
  }
   
}
 
int main(){
    z = system("cls");
    struct queue *q;
    int indicator = 0, option = 0, c, choice, value, size;
    printf("1. Use array to implement queue\n");
    printf("2. Use linked list to implement queue\n");
    z = scanf("%d", &choice);
    switch(choice){
        case 1: printf("Enter the size to create a queue ");
                z = scanf("%d", &size);
                q = (struct queue *) malloc(sizeof(struct queue));
                create_queue_using_array(q, size);
                option = 1;
                break;
        case 2:
                create_queue_using_linked_list(q);
                option = 2;
                break;
        default: printf("Enter correct choice\n");
    }
   
    if(option == 1){
        while(indicator == 0){
            print_options(1);
            z = scanf("%d", &c);
            switch(c){
                case 1: printf("Enter element ");
                        z = scanf("%d", &value);
                        enqueue_using_array(q, value);
                        break;
                case 2: printf("The element poped out from the queue is %d\n", dequeue_using_array(q));
                        break;
                case 3: printf("Full: %d\n", is_full_using_array(q));
                        break;
                case 4: printf("Empty: %d\n", is_empty_using_array(q));
                        break;
                case 5: printf("The number of elements in the queue is %d\n", number_of_elements_using_array(q));
                        break;
                case 6: indicator = 1;
                        break;
                default: printf("Enter correct choice\n");
            }
        }
    }
    if(option == 2){
        while(indicator == 0){
            print_options(2);
            z = scanf("%d", &c);
            switch(c){
                case 1: printf("Enter element ");
                        z = scanf("%d", &value);
                        enqueue_using_linked_list(value);
                        break;
                case 2: printf("The element poped out from the queue is %d\n", dequeue_using_linked_list());
                        break;
                case 3: printf("Full: %d\n", is_full_using_linked_list());
                        break;
                case 4: printf("The number of elements in the queue is %d\n", number_of_elements_using_linked_list());
                        break;
                case 5: indicator = 1;
                        break;
                default: printf("Enter correct choice\n");
            }
        }
    }
    return 0;
}
