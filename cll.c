#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
} node_t;
node_t *head = NULL;

void insert_node(int n)
{
	node_t *trav = NULL;
	node_t *t = (node_t*)calloc(1, sizeof(node_t));
	t->val = n;
	
	if(!head)
	{
		head = t;
		t->next = head;
	}
	else
	{
		trav = head;
		while(trav->next != head)
			trav = trav->next;

		t->next = head;
		head = t;
		trav->next = head;
	}
}

void delete_node(int n)
{
	node_t *t = head, *trav = head;

	if(!t)
	{
		printf("Empty list\n");
		return;
	}

	if(t->val == n)
	{
		while(trav->next != head)
			trav = trav->next;
		head = t->next;
		trav->next = head;
		free(t);
	}
	else
	{
		while(trav->next != head && trav->next->val != n)
			trav = trav->next;
		if(trav->next == head)
		{
			printf("Node not found\n");			
		}
		else
		{
			t = trav->next;
			trav->next = t->next;
			free(t);
		}	
	}
}

void search_node(int n)
{
	int count = 0;
	node_t *t = head;

	if(!t)
	{
		printf("Empty list\n");
		return;
	}
	if(t->val == n)
	{
		printf("Node found at %d\n", count);
		return;
	}
	count++;
	while(t->next != head && t->next->val != n && ++count)
		t = t->next;

	if(t->next == head)
	{
		printf("Node not found\n");
	}
	else
	{
		printf("Node found at %d\n", count);
	}
}

void traverse_node()
{
	node_t *t = head;
	if(!t)
	{
		printf("Empty list\n");
		return;
	}

	while(t->next != head)
	{
		printf("%d ", t->val);
		t = t->next;
	}

	printf("%d\n", t->val);
}

void reverse_ll(node_t *trav)
{
	if(!trav)
		return;
	else if(trav->next != head)
		reverse_ll(trav->next);
	printf("%d ", trav->val);
}

int main()
{
	int i, n;
	while(1)
	{
		printf("1.Insert 2. Delete 3.Search 4.Traverse 5.Reverse 10.Done\n");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				scanf("%d", &n);
				insert_node(n);
				break;
			case 2:
				scanf("%d", &n);
				delete_node(n);
				break;
			case 3:
				scanf("%d", &n);
				search_node(n);	
				break;
			case 4:
				traverse_node();
				break;
			case 5:
				reverse_ll(head);
				break;
			case 10:
				break;
			default:
				printf("Enter valid option\n");
		}
		if(i==10)
			break;
	}
}
