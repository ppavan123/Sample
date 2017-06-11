
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head = NULL;

void insert_b(int i)
{
	struct node *n = NULL;
	n = calloc(1, sizeof(sizeof(struct node)));
	n->data = i;
	n->next = head;
	head = n;
}

void display()
{
	struct node *t = NULL;

	t = head;
	while (t != NULL)
	{
		printf("data: %d\n", t->data);
		t = t->next;
	}
}

void insert_e(int i)
{
	struct node *t = NULL, *n = NULL;
	
	n = calloc(1, sizeof(struct node));
	n->data = i;
	n->next = NULL;

	t = head;
	if (t == NULL)
	{
		head = n;
	}
	else
	{
		while(t->next != NULL)
			t = t->next;

		t->next = n;
	}
}

void insert_af(int i, int j)
{
	struct node *t =  NULL, *n = NULL;

	n = calloc(1, sizeof(struct node));
	n->data = i;

	t = head;
	while(t->next != NULL && t->data != j)
		t = t->next;

	if (t->next == NULL)
	{
		n->next = NULL;
		t->next = n;
	}
	else
	{
		n->next = t->next;
		t->next = n;
	}
}

void insert_bf(int i , int j)
{
	struct node *t = NULL, *n = NULL;

	t = head;
	n = calloc(1, sizeof(struct node));
	n->data = i;

	if (t->data == j)
	{
		n->next = t;
		head = n;
		return;
	}

	while(t->next != NULL && t->next->data != j)
		t = t->next;

	if (t->next == NULL)
	{
		n->next = NULL;
		t->next = n;
	}
	else
	{
		n->next = t->next;
		t->next = n;
	}
}

void search(int i)
{
	struct node *t = head;

	while(t != NULL && t->data != i)
		t = t->next;

	if (t == NULL)
		printf("data: %d not found\n", i);
	else
		printf("data: %d found\n", i);
}

void delete(int i)
{
	struct node *t = head, *n = NULL;

	if (t->data == i)
	{
		head = t->next;
		free(t);
		return;
	}

	while(t != NULL && t->next->data != i)
		t = t->next;

	if (t == NULL)
	{
		printf("Data not found\n");
	}
	else
	{
		n = t->next;
		t->next = n->next;
		free(n);
		printf("Data deleted successfully\n");
	}
}

void main()
{
	int i, j, k, x = 0;

	while(x == 0)
	{
		printf("\n\n 1. Insert b\n 2. Insert e\n 3. Insert af\n 4. Insert bf\n 5. Search\n 6. Display\n 7. Delete\n 8. Exit\n\nEnter choise \n");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d", &j);
				insert_b(j);
				break;
			case 2:
				printf("Enter data\n");
				scanf("%d", &j);
				insert_e(j);
				break;
			case 3:
				printf("Enter element to insert after \n");
				scanf("%d", &k);
				printf("Enter data\n");
				scanf("%d", &j);
				insert_af(j, k);
				break;
			case 4:
				printf("Enter element to insert before \n");
				scanf("%d", &k);
				printf("Enter data\n");
				scanf("%d", &j);
				insert_bf(j, k);
				break;
			case 5:
				printf("Enter data\n");
				scanf("%d", &j);
				search(j);
				break;
			case 6:
				display();
				break;
			case 7:
				printf("Enter data\n");
				scanf("%d", &j);
				delete(j);
				break;
			case 8:
				x = 1;
				printf("Done");
				break;
			default:
				printf("Enter correct choise\n");
		}
	}
}
