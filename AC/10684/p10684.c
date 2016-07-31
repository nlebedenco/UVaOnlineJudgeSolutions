#include <stdio.h>
#include <stdlib.h>

int i,n,bet;
long long maximo,soma;

int main()
{
        while(scanf("%d",&n),n)
        {
                maximo=soma=0;
                for (i=1;i<=n;i++)
                {
                        scanf("%d",&bet);
                        soma+=bet;
                        if(soma<0)soma=0;
                        if(soma>maximo)maximo=soma;
                }

                if(maximo) printf("The maximum winning streak is %lld.\n",maximo);
                else printf("Losing streak.\n");
        }

        return 0;

}
