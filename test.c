#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		if (number < 0)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (number * sign);
}
struct node {
	int data;
	struct node *link;
};
struct stack_b {
	int data2;
	struct stack_b *link2;
};

void appendNode(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *last = *head;
        while (last->link != NULL) {
            last = last->link;
        }
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
void sorting(struct node *head)
{
    ///// swaping first two nodes
    struct node * i;
	struct node * j;
    int temp;
    i = head;
    while (i->link!=NULL)
    {
		j=i->link;
		while(j!=NULL)
		{
			if(i->data > j->data)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
			j=j->link;
		}
        i=i->link;
}
printf("Operation sa\n");
}

int main(int argc, char *argv[])
{
////////////////////////MANUALY
// struct node *head1 = malloc(sizeof(struct node));
// head1->data = 74;
// head1->link = NULL;

// struct node *head2 = malloc(sizeof(struct node));
// head2->data = 45;
// head2->link = NULL;
// head1->link = head2;

// head2 = malloc(sizeof(struct node));
// head2->data = 85;
// head2->link = NULL;
// head1->link->link= head2;


// head2 = malloc(sizeof(struct node));
// head2->data = 123;
// head2->link = NULL;
// head1->link->link->link = head2;

// head2 = malloc(sizeof(struct node));
// head2->data = 453;
// head2->link = NULL;
// head1->link->link->link->link = head2;
/////////////////////////////////////////////////////////
struct node *head1 = NULL;
int i = 1;
    while (i < argc)
    {
        int data = ft_atoi(argv[i]); // Преобразуем аргумент в целое число
        appendNode(&head1, data);
        i++;
    }

printf("Original:\n");
print_data(head1);
// printf("Sorted :\n");
// swap_a(head1);
// printf("Sorted :\n");
// print_data(head1);		

return(0);
}