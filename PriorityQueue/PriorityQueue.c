// Author : k3rn3lpanic
// GitHub Page : https://github.com/k3rn3lpanicc/DS-Implementations

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) (a>b?a:b)
typedef int data_type; 

int size = 0;
int max_size = 10;

data_type *createPriorityQueue(int size){
    return malloc(sizeof(data_type)*size);
}
void swap(data_type **pq , int first_index , int second_index){
    data_type tmp = (*pq)[first_index];
    (*pq)[first_index] = (*pq)[second_index];
    (*pq)[second_index] = tmp;
}
void expand_queue(int **oldqueue , int new_max_size){
    if(new_max_size<=max_size)
        return;
    int *new_queue = malloc(sizeof(int)*new_max_size);
    for(int i = 0 ; i<max_size; i++){
        new_queue[i] = (*oldqueue)[i];
    }
    *oldqueue = new_queue;
    max_size = new_max_size;
}

void colapse_queue(data_type **oldqueue , int new_max_size){
    if(new_max_size>(max_size/4))
        return;
    
    data_type **new_queue = malloc(sizeof(data_type)*size*2);
    for(int i = 0; i < size ; i++){
        new_queue[i] = oldqueue[i];
    }
    max_size/=2;
}

int get_parent_index(int index){
    return (index-1)/2;
}

void add(data_type **pq, data_type value){
    if (size>=max_size){
        expand_queue(pq , max_size*2);
    }
    (*pq)[size++] = value;
    int new_position_index = size-1;
    while (new_position_index != 0 && (*pq)[get_parent_index(new_position_index)] < (*pq)[new_position_index]){
        swap(pq, new_position_index , get_parent_index(new_position_index));
        new_position_index = get_parent_index(new_position_index);
    }
}

data_type poll(data_type **pq){
    data_type result = (*pq)[0];
    (*pq)[0] = (*pq)[size-1];
    int new_position_index = 0;
    while(new_position_index!=size && ((*pq)[new_position_index] < max((*pq)[new_position_index*2+1] , (*pq)[new_position_index*2+2]))){
        data_type max_child = max((*pq)[new_position_index*2+1] , (*pq)[new_position_index*2+2]);
        int index_to_swap_with = max_child == (*pq)[new_position_index*2+1]? (new_position_index*2+1) : (new_position_index*2+2);
        swap(pq , index_to_swap_with , new_position_index);
        new_position_index = index_to_swap_with;
    }
    size-=1;
    colapse_queue(pq , size/2);
    return result;
}

data_type peek(data_type *pq){
    return pq[0];
}


void print_queue(data_type *pq){
    printf("List :\n");
    for(int i = 0 ; i<size ; i++){
        printf("\t%d\tSon of : %d\tindex : %d\n" , pq[i] , i!=0 ? get_parent_index(i) : -1 , i);
    }
    printf("\n");
}




int main(){
    printf("%d\n" , (int)(log2(11)));
    data_type *priorityQueue = createPriorityQueue(10);
    add(&priorityQueue , 12);
    add(&priorityQueue , 2);
    add(&priorityQueue , 1);
    add(&priorityQueue , 8);
    add(&priorityQueue , 3);
    add(&priorityQueue , 2);
    add(&priorityQueue , 10);
    add(&priorityQueue , 12);
    add(&priorityQueue , 55);    
    add(&priorityQueue , 3);
    add(&priorityQueue , 4);
    add(&priorityQueue , 22);
    add(&priorityQueue , 4);
    print_queue(priorityQueue);
    printf("%d\n" , poll(&priorityQueue));
    print_queue(priorityQueue);
    free(priorityQueue);
}