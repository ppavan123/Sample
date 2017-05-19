#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int val;
    struct node* next;
};

struct hash
{
    struct node* head;
    int count;
};

struct hash* phash;
int buckets = 10;

void h_insert(int val)
{
        int idx;
        struct node* node;

        idx = val % buckets;
        node = (struct node*)malloc(sizeof(struct node));
        node->val = val;
        node->next = NULL;

        if(phash[idx].head == NULL)
        {
            phash[idx].head = node;
        }
        else
        {
            node->next = phash[idx].head;
            phash[idx].head = node;
        }

        phash[idx].count++;
}

void h_search(int val)
{
        int idx;
        struct node* trav;

        idx = val % buckets;

        trav = phash[idx].head;
        while(trav != NULL)
        {
            if(trav->val == val)
            {
                printf("Hash node found, val : %d\n", val);
            }
            trav = trav->next;
        }
}

void h_display()
{
        int i;
        struct node* head;

        for(i=0;i<buckets;i++)
        {
            head = phash[i].head;
            printf("Bucket : %d , count : %d\n", (i+1), phash[i].count);

            while(head!=NULL)
            {
                printf("Val : %d\n", head->val);
                head = head->next;
            }
        }
}

int main()
{
    int i, j;
    printf("Create Hash Table\n");
    phash = (struct hash*)calloc(buckets, sizeof(struct hash));
    printf("Hash Insert\n");
    for(i=0;i<buckets;i++)
        h_insert(i);

    printf("Hash Insert\n");
    for(j=0;j<buckets;j++)
        h_insert(j+10);

    printf("Display Hash\n");
    h_display();

    h_search(4);
    h_search(11);
}
