#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool T[5000][5000];
char V[5000];

bool correto, conexo;
int z, n, m;

void Marca(int k, char cor)
{
		V[k] = cor;
		for (int i = 0; i < n && correto; i++)
		{
			if (T[k][i])
			{
				if (V[i] == 0) Marca(i, (cor%3)+1);
				else if (V[i] != (cor%3)+1) correto = false;
			}

			if (T[i][k])
			{
				if (V[i] == 0) Marca(i, (cor>1?cor-1:3));
				else if (V[i] != (cor>1?cor-1:3)) correto = false;
			}
		}
}


int main()
{
	scanf("%d\n", &z); n = 5000;
	for (int caso = 1; caso <= z; caso++)
	{	
		memset(T, 0, n*sizeof(T[0]) );
		memset(V, 0, n*sizeof(V[0]) );

		scanf("%d%d\n", &n, &m);		
		while (m--)
		{
			int a, b;
			scanf("(%d>%d)\n", &a, &b);
			T[a-1][b-1] = true;
		}

		correto = conexo = true;
		Marca(0, 1);
		for (int i = 0; i < n && correto; i++)
		{
			if (not V[i])
			{
				conexo = false;
				Marca(i, 1);
			}
		}

		if (not correto) printf("Community %d: Conflicting Records\n", caso);
		else if (not conexo) printf("Community %d: Not Enough Data\n", caso);
		else printf("Community %d: Observation Complete\n", caso);
	}
	return 0;
}
