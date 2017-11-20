#include<stdio.h>
#include<stdlib.h>

typedef struct st{
	struct st *prv;
	int data;
	struct st *next;
}ST;

// Thsi add_begin function add node at the front...
void add_begin(ST **ptr)
{
	ST *temp = (ST *) malloc (sizeof(ST));

	printf("Enter the data...\n");
	scanf(" %d", &temp->data);

	temp -> next = *ptr;
	temp -> prv = NULL;

	if(*ptr != NULL)
		(*ptr) -> prv = temp;

	*ptr = temp;

}

//printing the linked list straightly i.e. last entered value in node will display first and first entered value will display last....
void printing_ll(ST *ptr)
{
	ST *last;
	while(ptr != NULL)	
	{
		printf("%d ",ptr -> data);
		last = ptr;
		ptr = ptr -> next;
	}
}
// reverse printing the node...
void rev_printing_ll(ST *ptr)
{
	while(ptr -> next != NULL)
		ptr = ptr -> next;

	while(ptr)
	{
		printf("%d ",ptr -> data);
		ptr = ptr -> prv;
	}
}

int main()
{
	char ch;
	ST *hptr = 0;

	do{
		add_begin(&hptr);
		printf("Do u want the node???\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

printf("Printing linked list using add_begin or add node at front...\n");	
printing_ll(hptr);

printf("\nReverse printing the linked list\n");
	rev_printing_ll(hptr);
	return 0;
}
