#include "exam1list.h"  

//Adds a COPY of the data to the end of the list
void append(LINKED_LIST * headPtr, DATA_TYPE * data)
{
	LIST_NODE * nodeptr = (LIST_NODE *) malloc(sizeof(LIST_NODE));
	LIST_NODE * currPtr = NULL;
	
	//Copy the data from the parameter.
	nodeptr->data.stud_id = data->stud_id;
	nodeptr->data.gpa = data->gpa;
	strcpy(nodeptr->data.firstname, data->firstname);
	strcpy(nodeptr->data.lastname, data->lastname);
	nodeptr->next = NULL;
	
	headPtr->listSize++;

	if(headPtr->front == NULL) //the node is the first
	{
		headPtr->front = headPtr->back = nodeptr;
		return;
	}
	
	/*There is at least one thing on the list.*/
	currPtr = headPtr->back;
	currPtr->next = headPtr->back = nodeptr;
}

void traverse(LINKED_LIST * headPtr)
{
   LIST_NODE * currPtr = headPtr->front;
   if (currPtr == NULL)
   {
	   printf("Nothing on list\n");
	   return;
   }
   printf("Contents of list:\n");
   while(currPtr != NULL)
   {
		printf("%d: %s %s: %.1f\n", currPtr->data.stud_id, currPtr->data.firstname,
						currPtr->data.lastname, currPtr->data.gpa);
		currPtr = currPtr->next;
   }
}


void clear(LINKED_LIST * headPtr)
{
	LIST_NODE * currptr = headPtr->front;
	LIST_NODE * prevptr = NULL;
	
	while(currptr)
	{
		prevptr = currptr;
		currptr = currptr->next;
		free(prevptr);
	}
	headPtr->front = headPtr->back = NULL;
}

LINKED_LIST * getHonorsStudents(LINKED_LIST * headPtr)
{
	if(headPtr->front == NULL) return NULL;
	LINKED_LIST * newListPtr = (LINKED_LIST *) malloc(sizeof(LINKED_LIST));
	newListPtr->back = newListPtr->front = NULL;
	newListPtr->listSize = 0;

	LIST_NODE * currPtr = headPtr->front;
	while(currPtr)
	{
		if (currPtr->data.gpa >= 3.5)
			append(newListPtr, &(currPtr->data));
		currPtr = currPtr->next;
	}
	return newListPtr;
}
