#include <stdio.h>
#include "push_swap.h"
void push_b(int data, struct node** stack_b)
{
	struct node* new;
	new = malloc(sizeof(new));
	if ( new== NULL)
	{
		printf("overflow");
		exit(1);
	}
	new->data = data;
	new->link = NULL;


	new->link= *stack_b;
	*stack_b = new;
	printf("pb");
	// stack_a->link = stack_b;
	// stack_a = stack_b;
	// return (stack_a);
}
int pop_a(struct node** stack_b)
{
	struct node* temp;
	int val;
	temp = *stack_b;
	val= temp->data;
	*stack_b= (*stack_b)->link;
	free(temp);
	temp=NULL;
	return(val);

	// if(stack_a == NULL)
	// {
	// 	printf("overflow");
	// 	exit(1);
	// }
	// temp = stack_a;
	// stack_a = stack_a->link;
	// return temp;
}
void push_a(int data, struct node** stack_a)
{
	struct node* new;
	new = malloc(sizeof(new));
	if ( new== NULL)
	{
		printf("overflow");
		exit(1);
	}
	new->data = data;
	new->link = NULL;


	new->link= *stack_a;
	*stack_a = new;
	printf("pa");
	// stack_a->link = stack_b;
	// stack_a = stack_b;
	// return (stack_a);
}
int pop_b(struct node** stack_a)
{
	struct node* temp;
	int val;
	temp = *stack_a;
	val= temp->data;
	*stack_a= (*stack_a)->link;
	free(temp);
	temp=NULL;
	return(val);

	// if(stack_a == NULL)
	// {
	// 	printf("overflow");
	// 	exit(1);
	// }
	// temp = stack_a;
	// stack_a = stack_a->link;
	// return temp;
}