#include<stdio.h>
#include<malloc.h>

typedef struct st
{
	int data;
	struct st *next;
}ST;

void add_end(ST **ptr)
{
	ST *temp = (ST * ) malloc (sizeof(ST));

	printf("Enter the data\n");
	scanf(" %d",&temp->data);

	if(*ptr == 0)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}
	else 
	{
		ST *last = *ptr;

		while(last -> next)
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
		ptr=ptr->next;
	}
	printf("\n");
}

void delete_middle_node(ST *ptr)
{
	ST *fast_ptr = ptr;
	ST *slow_ptr = ptr;
	ST *prv;

	if(ptr != 0)
	{
		while(fast_ptr && fast_ptr -> next)
		{
			fast_ptr = fast_ptr ->next -> next;
			prv = slow_ptr;
			slow_ptr = slow_ptr -> next;		
		}
		prv -> next = slow_ptr -> next;
		free(slow_ptr);
	}
}

int main()
{
	char ch;
	ST * hptr = 0;

	do{
		add_end(&hptr);
		printf("Do u want the node again???\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printf("Before deleting the middle node...\n");
	print_ll(hptr);
	printf("After deleting the middle node...\n");
	delete_middle_node(hptr);
	print_ll(hptr);
	return 0;
}
