/*  Linked List Library
 *
 *  contains functions and structures necessary to the creation of a linked list in C
 * 
 *  Author: Jaryd Peters
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedListNodeStruct.h"
#include "boolDefines.h"

struct node *newnode;
struct node *ptr;
struct node *previous;
struct node *temp;

struct node *head = NULL;
struct node *tail = NULL;

struct node
{
    int value;
    struct node *next;
};

struct node* createNewNode(int nodeValue)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode -> value = nodeValue;
    newnode -> next  = NULL;

    return newnode;
}

//insertNodeAtBeginning is simply a special case of insertNodeAtPosition where positionOfNodeToInsert = 1
void insertNodeAtBeginning(int valueOfNewNode)
{
    insertNodeAtPosition(valueOfNewNode, 1);
}

//insertNodeAtEnd is simply a special case of insertNodeAtPosition where positionOfNodeToInsert = findLengthOfList()
void insertNodeAtEnd(int valueOfNewNode)
{
    //specific handling to ensure nodes inserted at the end of lists with only one node are properly placed at the end
    if(findLengthOfList() == 1)
    {
        insertNodeAtPosition(valueOfNewNode, findLengthOfList() + 1);
    }
    else
    {
        insertNodeAtPosition(valueOfNewNode, findLengthOfList());
    }
}

void insertNodeAtPosition(int valueOfNewNode, int positionOfNodeToInsert)
{
    //create new orphan node with selected value to be inserted
    newnode = createNewNode(valueOfNewNode);

    //grab the length of the linked list
    int lengthOfList = findLengthOfList();

    //reset pointer to head to begin traversing to selected node
    ptr = head;
    
    //easy case where inserted node will be new head
    if(positionOfNodeToInsert == 1)
    {
        //head is tail and head is NULL, i.e. linked list is empty
        if(head == tail && head == NULL)
        {
            head = newnode;
            tail = newnode;

            head -> next = NULL;
            tail -> next = NULL;
        }
        //list has one or more nodes
        else
        {
            //grab head before replacing it
            temp = head;
            //replacing head with new node
            head = newnode;
            //set new head's next to previous head (stored in temp)
            head -> next = temp;
        }
        printf("\nNode inserted successfully into head position");
    }
    //insertion is occurring at tail of list (assume positions past length of list are intended for tail position)
    else if(positionOfNodeToInsert >= lengthOfList)
    {
        //set previous tail's next to the new node
        tail -> next = newnode;
        //set the tail to the new node
        tail = newnode;
        //set the new tail's next node to null
        tail -> next = NULL;

        printf("\nNode with value of %d successfully inserted at end of list", valueOfNewNode);
    }
    //insertion is NOT occurring at the head OR tail
    else if(positionOfNodeToInsert > 1 && positionOfNodeToInsert <= lengthOfList)
    {
        //reset current node to begin traversing to selected position
        ptr = head;

        for(int i = 1; i < positionOfNodeToInsert; i++)
        {
            //keep previous stored to stitch together fragmented list after node deletion
            previous = ptr;

            //move current pointer until we get to selected position
            ptr = ptr -> next;
        }
        previous -> next = newnode;
        newnode  -> next = ptr;

        printf("\nNode inserted successfully into position %d", positionOfNodeToInsert);
    }
    //position invalid
    else
    {
        printf("\nSelected position is out of range!");
    }
}

void deleteNodeAtPosition(void)
{
    int positionOfNodeToDelete;
    int lengthOfList = 0;

    if(head == NULL)
    {
        printf("\nLinked List is empty, no nodes to delete");
    }
    else
    {
        printf("\nEnter position of node to be deleted: ");
        scanf("%d", &positionOfNodeToDelete);

        //set active pointer to head to begin traveling to selected position
        ptr = head;

        //easy case where selected node is the head
        if(positionOfNodeToDelete == 1)
        {
            head = ptr -> next;
            printf("\nNode removed successfully");
        }
        //deletion is NOT occurring at the head
        else
        {
            //grab the length of the linked list
            lengthOfList = findLengthOfList();

            //make sure selection is within the list
            if(positionOfNodeToDelete > 0 && positionOfNodeToDelete <= lengthOfList)
            {
                //reset pointer to head to begin traversing to selected node
                ptr = head;

                for(int i = 1; i < positionOfNodeToDelete; i++)
                {
                    //keep previous stored to stitch together fragmented list after node deletion
                    previous = ptr;

                    //move current pointer until we get to selected position
                    ptr = ptr -> next;
                }
                //stitch together list around selected position, removing selected position from list
                //(previous -> next) was ptr, move it to (ptr -> next) to remove ptr
                previous -> next = ptr -> next;
                //free ptr so that it can be truly erased and not just removed
                free(ptr);
                
                printf("\nNode at position %d deleted successfully", positionOfNodeToDelete);
            }
        }
    }
}

void updateNodeValue(void)
{
    int valueToUpdate;
    int updatedValue;
    int valueUpdated = FALSE;

    if(head == NULL)
    {
        printf("\nLinked List is empty, no nodes to update!");
    }
    else
    {
        printf("\nEnter value to be updated: ");
        scanf("%d", &valueToUpdate);

        printf("\nEnter new value to replace %d: ", valueToUpdate);
        scanf("%d", &updatedValue);

        //set current pointer to the head, or start of the list
        //keep traversing until the pointer hits a NULL value marking the end
        //increment by changing the pointer to the pointer of the next node
        for(ptr = head; ptr != NULL; ptr = ptr -> next)
        {
            if(ptr -> value == valueToUpdate)
            {
                ptr -> value = updatedValue;
                valueUpdated = TRUE;
                break;
            }
        }
        //deliver results based off of search
        if(valueUpdated)
        {
            printf("\nfirst found instance of %d updated to %d successfully", valueToUpdate, updatedValue);
        }
        else
        {
            printf("\nValue of %d not found within list!", valueToUpdate);
        }
    }
}

void searchByElement(void)
{
    int searchedValue;
    int currentPosition = 0;
    int foundValue      = FALSE;

    if(head == NULL)
    {
        printf("\nLinked List is empty, no nodes to search!");
    }
    else
    {
        printf("\nEnter value to be searched for: ");
        scanf("%d", &searchedValue);
      
        //set current pointer to the head, or start of the list
        //keep traversing until the pointer hits a NULL value marking the end
        //increment by changing the pointer to the pointer of the next node
        for(ptr = head; ptr != NULL; ptr = ptr -> next)
        {
            currentPosition += 1;

            if(ptr -> value == searchedValue)
            {
                foundValue = TRUE;
                break;
            }
        }
        //deliver results based off of search
        if(foundValue)
        {
            printf("\nFirst found instance of %d found at position %d", searchedValue, currentPosition);
        }
        else
        {
            printf("\nValue %d not found in list!", searchedValue);
        }
    }
}

void displayList(void)
{
    if(head == NULL)
    {
        printf("\nLinked List is empty, no nodes to display!");
    }
    else
    {
        //formatting break
        printf("\n");

        //set current pointer to the head, or start of the list
        //keep traversing until the pointer hits a NULL value marking the end
        //increment by changing the pointer to the pointer of the next node
        for(ptr = head; ptr != NULL; ptr = ptr -> next)
        {
            printf("%d\t", ptr -> value);
        }
    }
}

int requestPosition(void)
{
    int positionOfNodeToInsert;

    printf("\nEnter position to insert new node: ");
    scanf("%d", &positionOfNodeToInsert);

    return positionOfNodeToInsert;
}

int requestValue(void)
{
    int valueOfNewNode;

    printf("\nEnter value of new node: ");
    scanf("%d", &valueOfNewNode);

    return valueOfNewNode;
}

int findLengthOfList(void)
{
    int lengthOfList = 0;
    
    ptr = head;

    while(ptr != NULL)
    {
        lengthOfList += 1;
        ptr = ptr -> next;
    }

    return lengthOfList;
}