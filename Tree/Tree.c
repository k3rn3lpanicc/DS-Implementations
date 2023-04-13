#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    int child_count;
    struct node *children[10];
} node;
node *create_node(int data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->child_count = 0;
    return new_node;
}
void add_child(node *parent, node *child){
    parent->children[parent->child_count] = child;
    parent->child_count++;
}
void print_tree(node *root){
    printf("%d ", root->data);
    for(int i=0; i<root->child_count; i++){
        print_tree(root->children[i]);
    }
}
//get children of a given node
node** get_children(node *root){
    return root->children;
}


int main(){
    node *root = create_node(1);
    node *child1 = create_node(2);
    node *child2 = create_node(3);
    node *child3 = create_node(4);
    node *child4 = create_node(5);
    node *child5 = create_node(6);
    node *child6 = create_node(7);
    node *child7 = create_node(8);
    node *child8 = create_node(9);
    node *child9 = create_node(10);
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(child1, child4);
    add_child(child1, child5);
    add_child(child2, child6);
    add_child(child2, child7);
    add_child(child3, child8);
    add_child(child3, child9);
    print_tree(root);
    printf("\n");
    node **children = get_children(root);
    for(int i=0; i<root->child_count; i++){
        printf("%d ", children[i]->data);
    }
    printf("\n");
    return 0;
}
