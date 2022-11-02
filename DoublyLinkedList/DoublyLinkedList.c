// Author : k3rn3lpanic
// GitHub Page : https://github.com/k3rn3lpanicc/DS-Implementations

#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
typedef int data_type;
struct node{
    data_type data;
    Node *next;
    Node *prev;
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
        printf("*\t%d\n" , head->data);
        head = head->next;
    }
    printf("\n");
}

Node* create_node(data_type data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
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
        new_node->prev = seek;
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
        seek->prev = new_node;
        *head = new_node;
    }
}

int get_len(Node *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

Node* get_node(Node *head , int index){
    int cnt = 0;
    while(cnt!=index && head){
        head = head->next;
        cnt++;
    }
    if (head) {
        return head;
    }
    return NULL;
}

void insert(Node **head , data_type data , int index){
    int size = get_len(*head);
    if (index > size){
        return;
    }
    else if(index == size){
        add_to_end(head , data);
    }
    else if(index == 0){
        add_to_front(head , data);
    }
    else{
        Node *c = get_node(*head , index-1);
        if (c){
            Node *new_node = create_node(data);
            new_node->next = c->next;
            new_node->prev = c;
            c->next->prev = new_node;
            c->next = new_node;
        }
        else{
            return;
        }
    }
}

int exists(Node *head , data_type value){
    while(head){
        if(head->data == value)
            return 1;
        head = head->next;
    }
    return 0;
}

Node *get_tail(Node *head){
    while(head->next)
        head = head->next;
    return head;
}

// Not a good practice (making a new list is way too slow!)
void reverse(Node **head){
    Node *new_head = get_tail(*head);
    Node *seek = new_head->prev;
    while(seek){
        add_to_end(&new_head , seek->data);
        seek = seek->prev;
    }
    *head = new_head;
}


int main(){
    Node* lol = create_node(1234);
    add_to_end(&lol , 32);
    add_to_front(&lol , 12);
    insert(&lol , 10 , 1);
    print_list(lol);
    printf("Len : %d\n3rd Node : %d\ndoes 32 exists in list ? %d\n" , get_len(lol) , get_node(lol , 2)->data , exists(lol , 32));
    reverse(&lol);
    printf("\nReversed ");
    print_list(lol);
    free_list(lol);
    return 0;
}