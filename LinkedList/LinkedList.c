#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
typedef int data_type;
struct node{
    data_type data;
    Node *next;
};

void free_list(Node* head){
    Node *seek  = head->next;
    free(head);
    while(seek){
        Node *current = seek;
        seek = seek->next;
        free(current);
    }
    free(seek);
}

void print_list(Node *head){
    printf("List : \n");
    while(head){
        printf("%d\n" , head->data);
        head = head->next;
    }
}

Node* create_node(data_type data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_to_end(Node **head , data_type data){
    Node *seek = *head;
    if(!seek){
        *head = create_node(data);
    }
    else{
        while(seek->next)
            seek = seek->next;
        Node *new_node = create_node(data);
        seek->next = new_node;
    }
}

void add_to_front(Node **head , data_type data){
    Node *seek = *head;
    if(!seek){
        *head = create_node(data);
    }
    else{
        Node *new_node = create_node(data);
        new_node->next = seek;
        *head = new_node;
    }
}




int main(){
    Node* lol = create_node(1234);
    add_to_end(&lol , 32);
    add_to_front(&lol , 12);
    print_list(lol);

    return 0;
}