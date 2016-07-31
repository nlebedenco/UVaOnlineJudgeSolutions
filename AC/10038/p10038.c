#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  int a,b,i,count,jolly,posicao;
  int v[3000];

int main()
{

  #ifndef ONLINE_JUDGE
    freopen("input", "rb", stdin);
    //freopen("10038.out", "wb", stdout);
  #endif

  while((scanf("%d", &count)) != EOF)
  {
    memset(v, 0, sizeof(v));
    jolly=1;	  
    scanf("%d", &a);
    for(i = 2; i <= count; i++)
    {
      scanf("%d", &b);
      posicao = abs(a - b);
      v[posicao] = 1;    
      a = b;
    }    
    
    for(i=1; i < count; i++)
    {
	if (v[i]==0)
	{
	  jolly=0;
	  break;
	}
    }
    
    if (jolly)
      puts("Jolly");
    else
      puts("Not jolly");
  }

  return 0;
}



