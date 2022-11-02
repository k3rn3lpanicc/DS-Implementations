// Author : k3rn3lpanic
// GitHub Page : https://github.com/k3rn3lpanicc/DS-Implementations

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack Stack;
typedef int data_type;
struct Stack{
    data_type data;
    Stack *next;
};

void free_stack(Stack* head){
    Stack *seek  = head->next;
    free(head);
    while(seek){
        Stack *current = seek;
        seek = seek->next;
        free(current);
    }
    free(seek);
}

void print_stack(Stack *head){
    printf("List : \n");
    while(head){
        printf("*\t%d\n" , head->data);
        head = head->next;
    }
    printf("\n");
}

Stack* create_Stack(data_type data){
    Stack *new_Stack = (Stack*)malloc(sizeof(Stack));
    new_Stack->data = data;
    new_Stack->next = NULL;
    return new_Stack;
}

void push(Stack **head , data_type data){
    Stack *seek = *head;
    if(!seek){
        *head = create_Stack(data);
    }
    else{
        Stack *new_Stack = create_Stack(data);
        new_Stack->next = seek;
        *head = new_Stack;
    }
}

data_type pop(Stack **head){
    if(*head){
        data_type ret = (*head)->data;
        *head = (*head)->next;
        return ret;
    }
}

int get_len(Stack *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

data_type peek(Stack *head){
    return head->data;
}

int main(){
    Stack* st = NULL;
    push(&st , 10);
    push(&st , 20);
    push(&st , 30);
    print_stack(st);
    
    data_type poped = pop(&st);
    printf("popped : %d\n\n" , poped);
    
    print_stack(st);
    free_stack(st);
    return 0;
}