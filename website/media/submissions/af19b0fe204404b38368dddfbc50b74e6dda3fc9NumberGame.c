#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node;
typedef struct node NODE;
typedef NODE *link;
struct node
{

	int elem;
	link next;
};
typedef struct
{
	int size;
	link start;
}head;


int main()
{
	int T, N;
	head h;
	int i, j, a, b, t = 1;
	h.start = NULL;
	h.size = 0;
	link nl = (link)malloc(sizeof(NODE));
        printf("Enter the number of\nTest Cases(Between 1 to 100)\nNumber of Integers In the game(Between 1 to 100)\nThe 'N' Integers(Between 1 to 100)\n");
	scanf("%d",&T);
	char c[100][6];
	for(i=0;i<T;i++)
	{
		scanf("\n%d",&N);
		
		scanf("%d",nl->elem);
		nl->next = NULL;
		h.start = nl;
		h.size++;
		for(j=0;j<N;j++)
		{
			scanf("%d",nl->elem);
			nl->next = h.start;
			h.start = nl;
			h.size++;
		}
		while(h.size != 1)
		{
			a = h.start->elem;
			b = h.start->next->elem;
			nl = h.start;
			nl = nl->next;
			h.start = nl;
			free(nl);
			h.start->elem = a+b-t;
			h.size--;
			if(h.size == 1)
				break;
			a = h.start->elem;
			b = h.start->next->elem;
			nl = h.start;
			nl = nl->next;
			h.start = nl;
			free(nl);
			h.start->elem = a+b-t;
			h.size--;
			t++;
		}
		if(h.start->elem%2 == 0)
                c[i][6] = 'L','O','O','S','E','\0';
		else
		c[i][6] = 'W','I','N','\0';
	}
	
	for(i=0;i<T;i++)
	printf("%s",c[i]);
}
	
