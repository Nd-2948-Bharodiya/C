/*
Hello, all.

Write a Linked list program which has GetNth() function that takes a linked list and an integer index and returns the data
value stored in the node at that index position.

*/
#include<stdio.h>
#include<malloc.h>
typedef struct st
{
	int data;
	struct st *next;
}ST;

// Newly created node will add at the beginning...
void add_node_begin(ST **ptr)
{
	//allocating the memory for the created node...
	ST *temp = (ST *)malloc(sizeof(ST));

	printf("Enter the data\n");
	scanf(" %d",&temp->data);

	temp->next = *ptr;	//hptr's value == 0 is dropped into temp->next location
	*ptr = temp;		//And, temp address is dropped into hptr
}
// Print the linked list
//Input : 10 20 30 60 70
// Output : 70 60 30 20 10
void print(ST *ptr)
{
	while(ptr)
	{
		printf("%d -> ",ptr->data);
		ptr=ptr->next;
	}
}
// Getting Nth Node...
//Here, function get_Nth_node takes structure pointer and integer index as argument and return integer, which contains value at that entered index.
int get_Nth_node(ST *ptr, int index)
{
	int count = 0;
	ST *current = ptr;

	while(current != NULL)
	{
		if(count == index)
			return current->data;
		count++;
		current = current->next;
	}
}
//Driver Program
int main()
{
	char ch;
int index;
	ST *hptr = 0;

	do
	{
		add_node_begin(&hptr);
		printf("Do u want the node again?\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');
//printing the ll... ...
printf("Before\n");
print(hptr);

printf("\nEnter the index value...\n");
scanf(" %d",&index);

int Nth_node = get_Nth_node(hptr,index);
printf("Value of that index : %d\n",Nth_node);
//printf("\n");
}
