#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};
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
void sort(struct node *head)
{
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
}

int main()
{
struct node *head1 = malloc(sizeof(struct node));
head1->data = 74;
head1->link = NULL;

struct node *head2 = malloc(sizeof(struct node));
head2->data = 45;
head2->link = NULL;
head1->link = head2;

head2 = malloc(sizeof(struct node));
head2->data = 85;
head2->link = NULL;
head1->link->link= head2;


head2 = malloc(sizeof(struct node));
head2->data = 123;
head2->link = NULL;
head1->link->link->link = head2;

head2 = malloc(sizeof(struct node));
head2->data = 453;
head2->link = NULL;
head1->link->link->link->link = head2;


sort(head1);
print_data(head1);		

return(0);
}