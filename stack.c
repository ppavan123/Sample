#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE	10

typedef struct node
{
	int val;
	struct node *next;
} node_t;

int top = 0;
node_t *head = NULL;

int isempty()
{
	if(top == 0)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(top == STACK_SIZE)
		return 1;
	else
		return 0;
}

void push(int n)
{
	if(isfull())
	{
		printf("Stack overflow\n");
		return;
	}
	node_t *t = (node_t*)calloc(1, sizeof(node_t));
	t->val = n;

	t->next = head;
	head = t;
	top += 1;
}

int pop()
{
	int n = 0;
	node_t *t = head;
	if(!head || isempty())
	{
		printf("Stack underflow\n");
		return -1;
	}
	head = t->next;
	n = t->val;
	free(t);
	top -= 1;
	return n;
}

int get_top()
{
	if(head)
		return head->val;
	else
	{
		printf("Empty stack\n");
		return -1;
	}
}

int main()
{
	int i, n;
	while(1)
	{
		printf("1.Push 2.Pop 3.Top 4.Count 5.Done\n");
		scanf("%d", &i);
		switch(i)
		{
			case 1:
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				printf(">>%d\n", pop());
				break;
			case 3:
				printf("##%d\n", get_top());
				break;
			case 4:
				printf(">> Total=%d\n", top);
				break;
			default:
				printf("Enter valid option\n");
		}
		if(i == 5)
			break;
	}
}
