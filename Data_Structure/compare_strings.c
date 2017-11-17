/*

Here, is a code in which you have to: 

Enter the character by character in first linked list (add_end_one), and
Enter the character by character in second linked list (add_end_second).

Then, compare this two linked list(Strings), which gives output as:
If String one > String 2 then return 1.
If String one < String 2 then return -1.
If String one == String 2 then return 0.
 
*/
#include<stdio.h>
#include<malloc.h>
typedef struct st
{
	char c;
	struct st *next; 
}ST;

void add_end_one(ST **ptr)
{
	ST *temp =(ST *) malloc(sizeof(ST));

	printf("Enter the data for linked list 1...\n");
	scanf(" %c",&temp->c);

	if(*ptr == NULL)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}

	else
	{
		ST *last = *ptr;

		while(last->next != 0)
			last = last->next;

		temp->next = last->next;
		last -> next = temp;
	}
}

void add_end_two(ST **ptr)
{
	ST *temp =(ST *) malloc(sizeof(ST));

	printf("Enter the data for linked list 2...\n");
	scanf(" %c",&temp->c);	// Enter the character for each node...

	if(*ptr == NULL)
	{
		temp -> next = *ptr;
		*ptr = temp;
	}

	else
	{
		ST *last = *ptr;

		while(last->next != 0)
			last = last->next;

		temp->next = last->next;
		last -> next = temp;
	}
}
void print_ll(ST *ptr)
{
	while(ptr)
	{
		printf("%c -> ",ptr->c);
		ptr=ptr->next;
	}
}

int compare_ll_strings(ST *ptr1, ST *ptr2)
{
	//traverse list. Stop if any either of character is not found matched...
	while(ptr1 && ptr2 && ptr1 -> c == ptr2 -> c)
	{
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}

	if(ptr1 && ptr2 )
		return (ptr1->c > ptr2->c ? 1 : -1);

	if(ptr1 && !ptr2)	return 1;
	if(ptr2 && !ptr1)  	return -1;

	return 0;	//If none of the above is true... That is, if both of ll strings are equal then it will return 0.
}

void main()
{
	char ch1,ch2;
	ST *hptr1 = 0;
	ST *hptr2 = 0;
	//creating first linked list...
	do
	{
		add_end_one(&hptr1);
		printf("Do u want a node again??\n");
		scanf(" %c", &ch1);
	}while(ch1 == 'y' || ch1 == 'Y');


	do
	{
		add_end_two(&hptr2);
		printf("Do u want a node again for second ll??\n");
		scanf(" %c", &ch2);
	}while(ch2 == 'y' || ch2 == 'Y');

	printf("First ll...\n");
	print_ll(hptr1);
	printf("Second ll...\n");
	print_ll(hptr2);

	int result = compare_ll_strings(hptr1,hptr2);
	printf("Result : %d\n",result);
}
