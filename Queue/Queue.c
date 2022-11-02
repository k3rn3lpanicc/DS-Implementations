// Author : k3rn3lpanic
// GitHub Page : https://github.com/k3rn3lpanicc/DS-Implementations

#include<stdio.h>
#include<stdlib.h>

typedef struct Queu Queu;
typedef int data_type;
struct Queu{
    data_type data;
    Queu *next;
};


void free_Queu(Queu* head){
    Queu *seek  = head->next;
    free(head);
    while(seek){
        Queu *current = seek;
        seek = seek->next;
        free(current);
    }
    free(seek);
}

void print_Queu(Queu *head){
    printf("List : \n");
    while(head){
        printf("*\t%d\n" , head->data);
        head = head->next;
    }
    printf("\n");
}

Queu* create_Queu(data_type data){
    Queu *new_Queu = (Queu*)malloc(sizeof(Queu));
    new_Queu->data = data;
    new_Queu->next = NULL;
    return new_Queu;
}

Queu *get_tail(Queu *head){
    while(head->next)
        head = head->next;
    return head;
}

void enqueue(Queu **head , data_type data){
    Queu *seek = *head;
    if(!seek){
        *head = create_Queu(data);
    }
    else{
        Queu *new_Queu = create_Queu(data);
        Queu *tail = get_tail(*head);
        tail->next = new_Queu;
    }
}

Queu *get_tail_prev(Queu *head){
    while(head->next->next)
        head = head->next;
    return head;
}

data_type dequeue(Queu **head){
    Queu *tail = get_tail_prev(*head);
    if(tail){
        data_type ret = tail->next->data;
        tail->next = NULL;
        return ret;
    }
}


int get_len(Queu *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

data_type peek(Queu *head){
    return head->data;
}

int main(){
    Queu* st = NULL;
    enqueue(&st , 10);
    enqueue(&st , 20);
    enqueue(&st , 30);
    print_Queu(st);
    
    data_type dequeued = dequeue(&st);
    printf("dequeued : %d\n\n" , dequeued);
    
    print_Queu(st);
    free_Queu(st);
    return 0;
}