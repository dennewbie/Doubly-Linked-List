//
//  main.c
//  stackDoublyLinkedList
//
//  Created by Denny Caruso on 31/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#include "header.h"

int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    
    Node *head = createNode();
    unsigned short int nNodes = generateIntegerNumber();
    printf("\nnNodes: %u\n", nNodes);
    
    for(int i = 0; i < nNodes - 1; i++) {
        Node *newNode = createNode();
        addNode(&head, newNode, generateIntegerNumber() % nNodes, nNodes);
    }
    printList(head);
    
    return 0;
}
