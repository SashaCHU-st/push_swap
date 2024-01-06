#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void appendNode(struct node **head, int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (*head == NULL)
        *head = newNode;
    else 
    {
        struct node *last = *head;
        while (last->link != NULL) 
            last = last->link;
        last->link = newNode;
    }
}

void print_data(struct node *head)
{
	if(head == NULL)
		printf("Empty");
	struct node *ptr = NULL;
	ptr= head;
	while(ptr)
	{
		printf("%d\n", ptr->data);
		ptr= ptr->link;
	}
}

int main(int argc, char *argv[])
{
//struct node *temp;
struct node *stack_a = NULL;
struct node *stack_b = NULL;
int i = 1;
int data;
int temp;
/// if argc = 3 togda ando simple function
    while (i < argc)
    {
        data = ft_atoi(argv[i]); 
        appendNode(&stack_a, data);
        i++;
    }

printf("Original:\n");
printf("Stack_a \n");
print_data(stack_a);
printf("\n");

/////////////////////////////////////////
// stack_a = push_b(data, stack_a);
// temp= pop_a(stack_a);
// stack_a= temp->link;


// stack_b= push_b(temp->data, stack_b);
// temp= pop_a(stack_a);
// stack_a= temp->link;
// stack_b= push_b(temp->data, stack_b);
///////////////////////////////////////////
//push_b(data, &stack_a);



/////////////// POP_A FROM STACK_A AND PUSH TO STACK_B
temp= pop_a(&stack_a);
push_b(temp, &stack_b);

//////ONE MORE TIME
temp= pop_a(&stack_a);
push_b(temp, &stack_b);

////////PUSH BACK FROM STACK_B. POP FROM B AND PUSH TO B
temp= pop_b(&stack_b);
push_a(temp, &stack_a);



printf("Stack_b\n");
print_data(stack_b);


printf("Stack_a\n");
print_data(stack_a);
// printf("Sorted :\n");
// swap_a(head1);
// printf("Sorted :\n");
// print_data(head1);		

return(0);
}