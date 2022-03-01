#include <stdio.h>
#include <stdlib.h>
#include "exam1list.h"

void getStudentData(LINKED_LIST * headPtr);

int main(int argc, char**argv)
{
	LINKED_LIST head;
	head.front = head.back = NULL;
	head.listSize = 0;
	
	getStudentData(&head);
	traverse(&head);

	LINKED_LIST * result = getHonorsStudents(&head);
	traverse(result);

	clear(&head);
	clear(result);
	return 0;
}

void getStudentData(LINKED_LIST * headPtr)
{
	DATA_TYPE data;
	char junk[100];
	printf("Enter student id or 0 to quit: ");
	scanf("%d", &(data.stud_id));
	while (data.stud_id >= 1)
	{
		//make space for a name
		printf("Enter the student's first name: ");
		scanf("%15s", data.firstname);
		printf("Enter the student's last name: ");
		scanf("%20s", data.lastname);
		printf("Enter student gpa: ");
		scanf("%f", &(data.gpa));

		append(headPtr, &data);

		printf("Enter student id or 0 to quit: ");
		scanf("%d", &(data.stud_id));
		fgets(junk, 100, stdin);
	}
}

