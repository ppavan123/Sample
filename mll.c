#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node_t;

node_t *root;

void del(node_t *m)
{
	node_t *t = root;

	if (t != NULL && m!= NULL)
	{
		while (t->next != m)
			t = t->next;
	}

	t->next = m->next;
	free(m);
}

node_t* mid()
{
	node_t *t1, *t2;
	t1 = t2 = root;

	while (t1->next != NULL &&  t2!= NULL && t2->next != NULL)
	{
		t1 = t1->next;
		t2 = t2->next->next;
	}
	printf("\n");
	printf("Mid: %d\n", t1->data);	
	return t1;
}

void push(int i)
{
	node_t *node = (node_t*)calloc(1, sizeof(node_t));
	node->data = i;
	if (root == NULL)
	{
		root = node;
		node->next = NULL;
	}
	else
	{
		node->next = root;
		root = node;
	}
}

void print()
{
	if (root == NULL)
		return;

	node_t *t = root;
	while(t->next != NULL)
	{
		printf("%d->", t->data);
		t = t->next;
	}
	printf("%d\n", t->data);
}

void rev()
{
	node_t *p, *c, *n;

	p = NULL;
	c = root;
	while(c != NULL)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	root = p;
}

void main()
{
	int i;
	for (i = 1; i <= 11; i++)
		push(i);

	print(i);
	rev();
	print(i);
	node_t *m = mid();
	del(m);
	print(i);
}
