/*  Linked List Tool
 *
 *  implementation of Linked List data type in C
 *  Uses linkedListNodeStruct to faciliate linked list operations
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include "boolDefines.h"
#include "linkedListNodeStruct.h"

int main(void)
{
    int selectedOperation = '\0';

    while(TRUE)
    {
        printf("\n\nLINKED LIST");
        printf("\nAvailable Operations:");

        printf("\n1.Insert node at beginning");
        printf("\n2.Insert node at end");
        printf("\n3.Insert node at a specific position");
        printf("\n4.Delete node from any Position");
        printf("\n5.Update first found instance of node by value");
        printf("\n6.Search for first found instance of element in the linked list");
        printf("\n7.Get length of list");
        printf("\n8.Display list");
        printf("\n9.Exit");

        printf("\nPlease select an operation: ");
        scanf("%d", &selectedOperation);

        switch(selectedOperation)
        {
        case 1:
            //only need to determine value as position is set
            insertNodeAtBeginning(requestValue());
            break;
        case 2:
            //only need to determine value as position is set
            insertNodeAtEnd(requestValue());
            break;
        case 3:
            //need to determine value and position
            insertNodeAtPosition(requestValue(), requestPosition());
            break;
        case 4:
            deleteNodeAtPosition();
            break;
        case 5:
            updateNodeValue();
            break;
        case 6:
            searchByElement();
            break;
        case 7:
            printf("\nLength of list is: %d", findLengthOfList());
            break;
        case 8:
            displayList();
            break;
        case 9:
            printf("\nExiting LINKED LIST");
            return 0;
        default:
            printf("\nInvalid choice, please retry");
            break;
        }
    }
    return 0;
}