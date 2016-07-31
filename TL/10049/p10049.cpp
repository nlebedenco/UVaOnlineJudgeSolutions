#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int inicial, chave, final;
	node(int a, int b, int c): inicial(a), chave(b), final(c) {}
	node() {}
};

vector <node> V;
int n;
node k;

node busca(int a)
{
	for (int i = 0; i < V.size(); i++)
		if ( (V[i].inicial >= a && V[i].final < a) || (V[i].inicial > a && V[i].final <= a) ) return V[i];
}

int main()
{
	V.clear();
	V.push_back(node(2, 2, 3));
	while (k = V.front(), k.inicial < 2000000000 && k.final < 2000000000)
	{
		//printf("%d, %d, %d\n", k.inicial, k.chave, k.final);
		int z = k.chave+1;
		node t = busca(z);
		V.push_back( node( V.back().final+1, z, V.back().final+t.chave) );
	}

	while (cin >> n, n)
	{
		if (n == 1) printf("1\n");
		else
		{
			k = busca(n);
			printf("%d\n", k.chave);
		}
	}
}

