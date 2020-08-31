//
//  header.c
//  stackDoublyLinkedList
//
//  Created by Denny Caruso on 31/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#include "header.h"

Node *createNode(void) {
    Node *newNode = (Node *) calloc(1, sizeof(Node));
    if(!newNode) getErrorNodeCreation();
    newNode->nodeData = createData();
    newNode->next = newNode->prev = NULL;
    
    return newNode;
}

void addNode(Node **head, Node *newNode, unsigned short int index, unsigned short int nNodes) {
    int i;
    Node *current;
    
    if(!(*head)) {
        printf("Error, List is empty!\n");
    } else {
        current = *head;
        i = 1;
        
        while(i < index - 1 && current != NULL) {
            current = current->next;
            i++;
        }
        
        if(index == 1) {
            newNode->prev = NULL;
            newNode->next = *head;
            if(*head != NULL) (*head)->prev = newNode;
    
            *head = newNode;
        } else if(index == nNodes) {
            while(current->next != NULL) current = current->next;
            newNode->next = NULL;
            newNode->prev = current;
            current->next = newNode;
        } else if(current != NULL) {
            
            newNode->next = current->next;
            newNode->prev = current;
            
            if(current->next != NULL) current->next->prev = newNode;
            current->next = newNode;
        } else {
            printf("Invalid position index generated. Node not inserted.\n");
        }
    }
}

void getErrorNodeCreation(void) {
    printf("\nError allocating memory for new node... Exit... \n");
    exit(EXIT_FAILURE);
}

Data *createData(void) {
    Data *newData = (Data *) calloc(1, sizeof(Data));
    if(!newData) getErrorDataCreation();
    genData(newData);
    
    return newData;
}

void genData(Data *newData) {
    newData->ID = 1 + rand() % MAX_ID;
}

void getErrorDataCreation(void) {
    printf("\nError allocating memory for new data... Exit... \n");
    exit(EXIT_FAILURE);
}

void printNode(Node *nodeToPrint)  {
    if(nodeToPrint) printf("-> %5d\n", nodeToPrint->nodeData->ID);
}

void printList(Node *head) {
    Node *current = head;
    printf("\nThis is the list: \n");
    
    while (head != NULL) {
        printNode(head);
        head = head->next;
    }
    
    while(current->next != NULL) current = current->next;
    printf("\nBackwards:\n");
    while(current != NULL) {
        printNode(current);
        current = current->prev;
    }
}

unsigned short int generateIntegerNumber() {
    return 1 + rand() % MAX_ID;
}
