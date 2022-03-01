#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIRSTSIZE 15
#define LASTSIZE 20

typedef struct linkeddata
{
	int stud_id;
	char firstname[FIRSTSIZE + 1];
	char lastname[LASTSIZE + 1];
	float gpa;
} DATA_TYPE;

typedef struct listnode
{
	DATA_TYPE data;
	struct listnode * next;
} LIST_NODE;

typedef struct list
{
	LIST_NODE * front;
	LIST_NODE * back;
	int listSize;
}LINKED_LIST;

void append(LINKED_LIST  * headPtr, DATA_TYPE * data);
void traverse(LINKED_LIST  * headPtr);
void clear(LINKED_LIST  * headPtr);
LINKED_LIST * getHonorsStudents(LINKED_LIST * headPtr);