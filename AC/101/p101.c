#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char P[25];
char V[25][25];

char cmd[4+1] = {0};
char modifier[4+1] = {0};

int a, b;
char done = 0;

void push(int k, int x)
{
	int j;
	for (j = 0; j < n; ++j)
		if (V[x][j] == -1)
		{
			V[x][j] = k;
			break;
		}	
	P[k] = x;	
}

void move(int k, int x)
{
	int i = P[k], j;
	push(k, x); /* push in new queue */
	/* remove from old queue */
	for (j = n-1; (j >= 0) && (V[i][j] != k); --j);
	V[i][j] = -1;	
}

void clear_top(int k)
{
	int i = P[k];
	int j;
	for (j = n-1; (j >= 0) && (V[i][j] != k); --j)
	{
		int x = V[i][j];
		push(x, x);
		V[i][j] = -1;
	}	
}

void pile(int k, int x)
{
	int i = P[k], j;
	for (j = 0; (j < n) && (V[i][j] != k); ++j);
	for (; j < n && V[i][j] != -1; ++j)
	{
		push(V[i][j], x);
		V[i][j] = -1;
	}
}

void print_output()
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		printf("%d:", i);
		for (j = 0; (j < n) && (V[i][j] >= 0); ++j)
			printf(" %d", V[i][j]);
		printf("\n");	
	}
}

int main()
{
	scanf("%d\n", &n);
	int i,j;
	for (i = 0; i < n; ++i)
	{
		V[i][0] = i;
		for (j = 1; j < n; ++j)
			V[i][j] = -1;
		P[i] = i;
	}	
		
	while (!done)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "quit") == 0)
			done = 1;
		else
		{
			scanf("%d %s %d\n", &a, modifier, &b);
			if ((a != b) && (P[a] != P[b]))
			{
				if (strcmp(cmd, "move") == 0)
				{
					if (strcmp(modifier, "onto") == 0)
					{
						clear_top(a);
						clear_top(b);
						move(a, P[b]);
					}
					else if (strcmp(modifier, "over") == 0)
					{
						clear_top(a);
						move(a, P[b]);
					}
				}
				else if (strcmp(cmd, "pile") == 0)
				{
					if (strcmp(modifier, "onto") == 0)
					{
						clear_top(b);
						pile(a, P[b]);
					}
					else if (strcmp(modifier, "over") == 0)
					{
						pile(a, P[b]);
					}
				}
			}
			/* printf("%s %d %s %d\n", cmd, a, modifier, b); */
			/* print_output(); */
		}
	}
	
	print_output();
	return 0;
}
