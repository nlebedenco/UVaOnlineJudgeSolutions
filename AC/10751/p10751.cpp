/* O objetivo é descobrir o maior número de diagonais (d) que se pode desenhar
na matriz de pontos para um dado n a resposta desejada será então
n^2 - d + d*raiz(2)
O número de diagonais pode ser calculado verificando-se que a melhor configuração
é sempre assim:
._._.
|   |
. ._.
|  \
._._.
F(3) = 1 diagonal

._._._.
|     |
. . ._.
| |\ \
. . . .
|  \ \|
._._. .
F(4) = 1 + 2 + 1 diagonais
F(5) = 1 + 2 + 3 + 2 + 1
F(6) = 1 + 2 + 3 + 4 + 3 + 2 + 1
...
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int T(int n)
{
	if (n < 1) return 0;
	return n*(n-1)/2;
}

int z, n;
int main()
{
	cin >> z;
	while (z--)
	{
		cin >> n;
		if (n == 1) printf("0.000\n");
		else
		{
			int d = T(n-1) + T(n-2);
			printf("%.3f\n", (n*n - d) + d*sqrt(2));
		}
	}
	return 0;		
}
