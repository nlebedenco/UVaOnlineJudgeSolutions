#include <stdio.h>
#include <stdlib.h>
#define N 55
#define EMBRANCO -1

int i,j,k,d,q,n,tam,custo;
int m[N][N];
int corte[N];

int main()
{
	while (scanf("%d", &tam), tam)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)scanf("%d",&corte[i]);
		corte[0]=0;
		corte[n+1]=tam;
		for(i=0;i<=n+1;i++) m[i][i]=0;
		for (d=2; d<= n + 1 ; d++)
		{
			for (i=0;i<=n-d+1;i++)
			{
				j=i+d;
				m[i][j]=EMBRANCO;
				for (k=i+1;k<j;k++)
				{
					custo=m[i][k]+m[k][j]+(corte[j]-corte[i]);
					if (m[i][j]==EMBRANCO || custo < m[i][j]) m[i][j]=custo;
				}
			}
		}
		printf("The minimum cutting is %d.\n",m[0][n+1]);
	}
	return 0;
}
