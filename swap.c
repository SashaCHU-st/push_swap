#include <stdio.h>
#include "push_swap.h"

void from_last_to_first_a(struct node **stack_a)
{
	if(*stack_a == NULL || (*stack_a)->link == NULL)
		return;
	struct node *last = NULL;
	struct node *ptr1 = *stack_a;

	while(ptr1->link !=NULL)
	{
		last=ptr1;
		ptr1= ptr1->link;
	}
	last->link= NULL;
	ptr1->link= *stack_a;
	*stack_a = ptr1;
	printf("\nra");
}
void from_last_to_first_b(struct node **stack_b)
{
	if(*stack_b == NULL || (*stack_b)->link == NULL)
		return;
	struct node *last = NULL;
	struct node *ptr1 = *stack_b;

	while(ptr1->link !=NULL)
	{
		last=ptr1;
		ptr1= ptr1->link;
	}
	last->link= NULL;
	ptr1->link= *stack_b;
	*stack_b = ptr1;
	printf("\nrb");
}