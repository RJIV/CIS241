// R.J. Hamilton
// CIS241
// October 8, 2018
// Hamilton.c

#include"lab3.h"

struct node *init()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	return head;
}

void insert(struct node *head, int data)
{
	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next = (struct node*)malloc(sizeof(struct node));
	head->next->data = data;
	head->next->next = NULL;
}

void display(struct node *head)
{
	head=head->next;
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");
}

void deleteAll(struct node *head)
{
	struct node *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
}

