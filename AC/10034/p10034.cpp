#include <stdio.h>
#include <string.h>
#include <float.h>
#include <math.h>
#define MAX 110
#define E 1e-10

typedef struct
{
    double x, y;
} Ponto;

Ponto pontos[MAX];
double mat[MAX][MAX], aux[MAX][MAX], s;
int n, m;
int marcado[MAX];

void prim()
{
    int i, j, nmarc = 0, x, y;
    double menor_aresta = DBL_MAX;
    
    memset(aux, 0, sizeof(aux));
    memset(marcado, 0, sizeof(marcado));
    marcado[0] = 1;
    
    while(nmarc < n - 1)
    {
       menor_aresta = DBL_MAX;
        
        // acha a menor aresta do grafo
       for(i = 0; i < n; i++)
          if(marcado[i])
          for(j = 0; j < n; j++)
              if(!marcado[j])
              if(mat[i][j] > E && mat[i][j] < menor_aresta)
              {
                  x = i;  y = j;
                  menor_aresta = mat[i][j];  
              }
           
       // adiciona a menor aresta ao grafo auxiliar
       marcado[x] = marcado[y] = 1;
       nmarc++;
       aux[x][y] = menor_aresta;
       //printf("Pegando o %d, %d = %.2lf\n", x, y, menor_aresta);
                       
    }  
    
}

int main()
{
  int i, j, ntest, npoints;
  double dist;
    
  scanf("%d", &ntest);
  while(ntest--)
  {
    scanf("%d", &npoints);
    
    for(i = 0; i < npoints; i++)
            scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
            
    n = npoints;
    // calcula as distancias de todos para todos
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            dist = sqrt(pow(pontos[i].x - pontos[j].x, 2) + pow(pontos[i].y - pontos[j].y, 2));
            //printf("%d, %d = %.2lf", i, j, dist);
            mat[i][j] = mat[j][i] = dist;
        }    
    
    prim();
    s = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            s += aux[i][j];
            //printf("%.2lf ", aux[i][j]);
        }
        //printf("\n");
    }        
            
    
    // somatório dos pesos das arestas pertencentes 'a árvore
    printf("%.2lf\n", s);
    if (ntest > 0) printf("\n");
  }        
  
  return 0;
}
    
