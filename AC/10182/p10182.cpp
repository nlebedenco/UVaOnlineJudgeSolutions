#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int main()
{
	while (cin >> n)
	{
		int a = 0, b = 0;
		int casa = 1, i = 1;
		while (casa < n)
		{	
			// Desce (i casas)
			for (int j = 0; j < i && casa < n; j++)
			{
				b++;
				casa++;
			}
			// Diagonal Inferior Esquerda (i-1 casas)
			for (int j = 0; j < i-1 && casa < n; j++)
			{
				a--; b++;
				casa++;
			}
			// Esquerda (i casas)
			for (int j = 0; j < i && casa < n; j++)
			{
				a--;
				casa++;
			}
			// Sobe (i casas)
			for (int j = 0; j < i && casa < n; j++)
			{
				b--;
				casa++;
			}
			// Diagonal Superior Direita (i casas)
			for (int j = 0; j < i && casa < n; j++)
			{
				a++; b--;
				casa++;
			}
			// Direita (i casas)
			for (int j = 0; j < i && casa < n; j++)
			{
				a++;
				casa++;
			}
			i++;
		}

		printf("%d %d\n", a, b); 
	}

	return 0;
}

