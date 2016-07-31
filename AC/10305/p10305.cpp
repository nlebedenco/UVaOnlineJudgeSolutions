#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m, pos;
bool T[100][100], S[100];

void Visita(int k)
{
	S[k] = true;
	for (int i = 0; i < n; i++) if (T[k][i] && not S[i]) Visita(i);

	printf("%d", k+1); 
	if (++pos == n) printf("\n");
	else printf(" ");
}

int main()
{
	while (cin >> n >> m, n || m)
	{
		memset(T, 0, sizeof(T));
		memset(S, 0, sizeof(S));

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b; a--; b--;
			T[b][a] = true;
		}		

		pos = 0;

		for (int i = 0; i < n; i++)
			if (not S[i]) Visita(i);
	}
}
