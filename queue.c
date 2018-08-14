#include<stdio.h>
#include<stdlib.h>

#define Q_SIZE	10

typedef struct node
{
	int val;
	struct node *next;
} node_t;

int front = 0, rear = -1;
node_t *head = NULL;

int isempty()
{
}

int isfull()
{
}

void enq(int n)
{
	node_t *t = (node_t*)calloc(1, sizeof(node_t));
	t->val = n;

	t->next = head;
	head = t;
	rear += 1;
}

int deq()
{
	int n = 0;
	node_t *t = head, *trav = NULL;
	if(!head)
	{
		printf("Q is empty\n");
		return -1;
	}

	if(t->next == NULL)
	{
		head = t->next;
		n = t->val;
	}
	else
	{
		while(t->next != NULL)
		{
			trav = t;
			t = t->next;
		}

		trav->next = t->next;
		n = t->val;
	}
	free(t);
	front += 1;
	return n;
}

int get_top()
{
	node_t *t = head;
	if(!head)
		return -1;

	while(t->next)
		t = t->next;

	return t->val;
}

void traverse()
{
	node_t *t = head;

	while(t)
	{
		printf("%d ", t->val);
		t = t->next;
	}
	printf("\n");
}

int main()
{
	int i, n;
	while(1)
	{
		printf("1.Enqueue 2.Dequeue 3.Top 4.Count 5.Done\n");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				scanf("%d", &n);
				enq(n);
				break;
			case 2:
				printf(">>%d\n", deq());
				break;
			case 3:
				printf("##%d\n", get_top());
				break;
			case 4:
				printf(">> rear=%d, front=%d\n", rear, front);
				traverse();
				break;
			default:
				printf("Enter valid option\n");
		}
		if(i == 5)
			break;
	}
}
