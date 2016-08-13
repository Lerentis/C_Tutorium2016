/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 *******************************************************/
 
#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int data;
    struct list_node *next;
    struct list_node *prev;
};

typedef struct list_node* node;

node insert_right(node list, int data){
    node new_node = (node) malloc(sizeof(struct list_node));
    new_node->data = data;
    new_node->next = list->next;
    new_node->prev = list->prev;
    list->next     = new_node;
    return new_node;
}

node insert_left(node list, int data){
    node new_node = (node) calloc(1,sizeof(struct list_node));
    new_node->data = data;
    new_node->next = list->prev;
    new_node->prev = list->next;
    list->prev = new_node;
    return new_node;
}

int main()
{

    node m = (node) calloc(1,sizeof(struct list_node));
    printf("%d \n",m->data);
    insert_right(m,55);
    printf("%d \n",m->next->data);
    insert_right(m,42);
    printf("%d \n",m->next->data);
    while(!m){
        free (m->next);
    }

    free(m);

    return 0;
}
