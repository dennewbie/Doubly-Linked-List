//
//  header.h
//  stackDoublyLinkedList
//
//  Created by Denny Caruso on 31/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ID 10
#define newLine() { printf("\n\n"); }

#endif /* header_h */

//Bool handling
enum bool { FALSE, TRUE };
typedef enum bool Bool;

//Basic Data Structures for the Queue
struct info {
    int ID;
};

typedef struct info Data;

struct node {
    Data *nodeData;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

Node *createNode(void);
void addNode(Node **, Node *, unsigned short int, unsigned short int);
void getErrorNodeCreation(void);
Data *createData(void);
void genData(Data *);
void getErrorDataCreation(void);

void printNode(Node *);
void printList(Node *);

unsigned short int generateIntegerNumber(void);
