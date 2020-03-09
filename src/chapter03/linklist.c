//
// Created by changwang on 1/18/20.
//
#include "apue.h"
#include "link.h"
#include <stdlib.h>

typedef struct _node{
    Data* data; //这里可以是任意的结构提
    struct _node* next;
} Node;

struct _linkedList {
    Node* head;
};

LinkedList*
getLinkedListInstance()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if(list == NULL) {
        err_sys("malloc linkedList error");
    }
    list->head = NULL;
    return list;
}

void
removeLinkedListInstance(LinkedList* list)
{
    Node* tmp = list->head;
    while(tmp != NULL) {
        free(tmp->data);
        Node* current = tmp;
        tmp = tmp->next;
        free(current);
    }
    free(list);
}

void
addNode(LinkedList* list, Data data)
{
    //Malloc Node
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL) {
        list->head = node;
        node->next = NULL;
    } else {
        //头插法
        node->next = list->head;
        list->head = node;
    }
}

Data
removeNode(LinkedList* list)
{
    if(list->head == NULL)
        return NULL;

    Node* tmp = list->head;
    Data* data;
    list->head = list->head->next;
    data = tmp->data;
    free(tmp);
    return data; //这里没有 free ，需要调用方自己 free
}

int
main(void)
{

}

