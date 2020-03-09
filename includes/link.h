//
// Created by changwang on 1/18/20.
//
// Code example in 《Understanding And Using Pointers in C》 chapter 8
// Object-Oriented Linked List in C
//

#ifndef APUE_CODE_LINK_H
#define APUE_CODE_LINK_H

typedef void* Data;
typedef struct _linkedList LinkedList;

LinkedList* getLinkedListInstance();
void removeLinkedListInstance(LinkedList* linkedList);
void addNode(LinkedList* list, Data data);
Data removeNode(LinkedList* list);

#endif //APUE_CODE_LINK_H
