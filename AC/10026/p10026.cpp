#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node 
{
	int time, fine, k;
};

node V[1000];
int z, n;

bool compara (const node& a, const node& b)
{
	return (a.fine * b.time) > (b.fine * a.time);  // a vem antes de b se essa condição for verdadeira
}

int main()
{
	cin >> z;
	while (z--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> V[i].time >> V[i].fine;
			V[i].k = i+1;
		}
		stable_sort(V, V+n, compara);  // Ordenação estável !!
		for (int i = 0; i < n; i++)
		{
			printf("%d", V[i].k);
			if (i < n-1) printf(" ");
		}
		printf("\n");
		if (z) printf("\n");
	}
}
