#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int data;
	struct st *next;
}ST;

void add_end(ST ** ptr)
{
	ST *temp = (ST *)malloc (sizeof (ST));

	printf("Enter the data...\n");
	scanf(" %d",&temp->data);

	if(*ptr == NULL)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}
	else
	{
		ST * last = *ptr;

		while(last -> next)
			last = last -> next;

		temp -> next = last -> next;
		last -> next = temp;
	}
}
void print_ll( ST *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr -> next;
	}
}
void swap_node_changing_link(ST **ptr, int x, int y )
{
	ST *prev_x = NULL; 
	ST *prev_y = NULL;

	ST *curr_x = *ptr;
	ST *curr_y = *ptr;

	//If x and y is same nothing to do, simply return...
	if(x == y)
		return;

	//Keep searching x value thru curr_x pointer...
	while(curr_x && curr_x -> data != x)
	{
		prev_x = curr_x;
		curr_x = curr_x -> next;
	}

	//Keep searching y value thru curr_y pointer...
	while(curr_y && curr_y -> data != y)
	{
		prev_y = curr_y;
		curr_y = curr_y -> next;
	}

	//If either of is not found or traced then do nothing...
	if(curr_x == NULL || curr_y == NULL)
		return;

	if(prev_x != NULL)
		prev_x -> next = curr_y;
	else
		*ptr = curr_y;

	if(prev_y != NULL)
		prev_y -> next = curr_x;
	else
		*ptr = curr_x;

ST *temp = curr_y -> next;
curr_y -> next = curr_x -> next;
curr_x -> next = temp;

}

void main()
{
	char ch;

	ST * hptr = 0;

	int first_value, second_value;

	do
	{
		add_end(&hptr);
		printf("Do u want the node???\n");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');

	printf("Before swapping the node...\n");
	print_ll(hptr);

	printf("\nEnter the value (Node 1) ...\n");
	scanf(" %d",&first_value);

	printf("\nEnter the value (Node 2) ... \n");
	scanf(" %d",&second_value);

	printf("\nAfter the swapping the node...\n");
	swap_node_changing_link(&hptr,first_value,second_value);
	print_ll(hptr);
printf("\n");	
}
