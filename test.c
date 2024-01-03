#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
    
	struct node *link;
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

int main(int argc, char *argv[])
{
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
struct node *head1 = NULL;

    // Проходим по аргументам и добавляем их в список
    for (int i = 1; i < argc; i++) {
        int data = atoi(argv[i]); // Преобразуем аргумент в целое число
        appendNode(&head1, data);
    }

//     // Выводим список
//     printf("Linked List: ");
//    // printList(head);
printf("Original:\n");
print_data(head1);
printf("Sorted :\n");
sort(head1);
print_data(head1);		

return(0);
}