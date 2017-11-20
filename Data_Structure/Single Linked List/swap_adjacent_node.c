#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct st
{
	int data;
	struct st *next;
}ST;

void add_middle(ST **ptr)
{
	ST *temp = (ST *) malloc(sizeof(struct st));

	printf("Enter the data...\n");
	scanf("%d",&temp -> data);

	if(*ptr == NULL || temp -> data < (*ptr) -> data)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}
	else{
		ST *last = *ptr;

		while(last -> next && last -> next -> data < temp -> data)
			last = last -> next;

		temp -> next = last -> next;
		last -> next = temp;
	}
}

void print_ll(ST *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr = ptr-> next;
	}
	printf("\n");
}

void swap_adjecent_nodes(ST **ptr)
{
	ST *prev = *ptr;
	ST *curr = (*ptr) -> next;
	*ptr = curr;

	while(true)
	{
		ST *next = curr->next;
		curr -> next = prev;

		if(next == NULL || next -> next == NULL)
		{
			prev -> next = next;
			break;
		}

		prev -> next = next -> next;
		prev = next;
		curr = prev -> next;
	}
}

int main()
{
char ch;
ST *hptr = 0;

do{
add_middle(&hptr);
printf("Do u want node?\n");
scanf(" %c",&ch);
}while(ch == 'y' || ch == 'Y');

printf("Before swapping the linked list...\n");
print_ll (hptr);

printf("After swapping the adajecent nodes of linked list...\n");
swap_adjecent_nodes(&hptr);
print_ll(hptr);

		return 0; 
}
