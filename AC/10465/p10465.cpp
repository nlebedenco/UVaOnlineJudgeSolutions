#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a, b, t, m, n, A, B, T;

/*  a e b são os candidatos a quantidade de cada tipo de cerveja
 *  t o tempo disponível
 *  A e B são as melhores respostas encontradas até o momento
 *  T é o melhor tempo encontrado
 *  m e n são o tempo que leva para tomar cada tipo de cerveja 
 */

int main()
{
        while (cin >> m >> n >> t)
        {
		if (m > n) swap(m, n);
		A = a = t / m;
		B = b = 0;
		T = a*m;
		while (a*m + b*n <= t && a > -1)
		{
			if (a*m + b*n > T)
			{
				T = a*m + b*n;
				A = a;
				B = b;
			}
			if (T == t) break;
			a--;
			while (a*m + (b+1)*n <= t) b++; 
		}
		
		printf("%d", A+B);
		if (T < t) printf(" %d\n", t-T);
		else printf("\n");
	}
}
