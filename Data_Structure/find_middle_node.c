#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
	int data;
	struct st *next;
}ST;

//This add_end function add the node at the end...
void add_end(ST **ptr)
{
	ST * temp = (ST *) malloc(sizeof(ST));

	printf("Enter the data...\n");
	scanf(" %d",&temp->data);

	if(*ptr==NULL)
	{
		temp->next = *ptr;
		*ptr = temp;
	}
	else 
	{
		ST *last = *ptr;

		while(last -> next != NULL)
			last = last -> next;

		temp -> next = last -> next;
		last -> next = temp;
	}

}
// This print_ll is function which prints the linked list
void print_ll(ST*ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}


} 
//This, find_middle_node function will find find the middle node and also gives at which index or position its present, starting from zero.
void find_middle_node(ST *ptr)
{
	ST *fast_ptr = ptr;
	ST *slow_ptr = ptr;
	int count_node = 0;

	if(ptr != NULL)
	{
		while(fast_ptr && fast_ptr -> next)
		{
			count_node++;//gives, At which position middle node is?
			fast_ptr = fast_ptr -> next -> next;
			slow_ptr = slow_ptr -> next;
		}
		printf("The middle node is %d at %d position\n",slow_ptr->data, count_node);
	}
}
int main()
{
	char ch;

	ST *hptr = 0;

	do{
		add_end(&hptr);
		printf("Do u want node again???\n");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
	printf("linked list is :\n");
	print_ll(hptr);
	printf("\n");
	find_middle_node(hptr);
	return 0;
}

