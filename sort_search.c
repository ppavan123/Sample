#include <stdio.h>

void bsort(int array[], int n)
{
	int i,j,temp,flag=0;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
				flag=1;
			}
		}

		if(flag==0)
		{
			printf("sorted\n");
			break;
		}
	}
}

void ssort(int array[], int n)
{
	int i,j,k,temp;

	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(array[k]>array[j])
			{
				k=j;
			}
		}

		if(k!=i)
		{
			temp=array[i];
			array[i]=array[k];
			array[k]=temp;
		}
	}
}

int search(int array[], int n, int x)
{
	int start=0, end=n-1, mid=0;

	while(start<=end)
	{
		mid=(start+end)/2;

		if(x==array[mid])
			return x;
		else if(x<array[mid])
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}

int main()
{
	int n=10, i, x, ret;
	int array[10] = {9, 5, 10, 2, 4, 1, 6, 3, 8, 7};

	ssort(array, n);
	for (i=0;i<n;i++)
	{
		printf("%d ", array[i]);
	}

	for (i=0;i<n;i++)
	{
		scanf("%d", &x);
		if ((ret=search(array, n, x)) < 0)
			printf("entry not found\n");
		else
			printf("found entry=%d at %d\n", x, ret);
	}
	return 0;
}
