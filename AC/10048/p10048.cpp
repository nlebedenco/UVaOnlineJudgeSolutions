#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int INFINITO = 1000000;

int D[100][100], n, m, q, caso = 1;

int main()
{
    while (cin >> n >> m >> q, 	n || m || q)
    {
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	       D[i][j] = INFINITO;

	for (int i = 0; i < n; i++) D[i][i] = 0;	
	
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c; a--; b--;
            D[a][b] = D[b][a] = c;         
        }
                
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    D[j][k] = min ( D[j][k], max( D[j][i], D[i][k]));
	 
	if (caso > 1) printf("\n");
	printf("Case #%d\n", caso++);
	for (int i = 0; i < q; i++)
	{
	    int a, b;
	    cin >> a >> b; a--; b--;
	    if (D[a][b] == INFINITO && a != b) printf("no path\n");
	    else printf("%d\n", D[a][b]);
	}
    }
}

