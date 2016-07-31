#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int m = 30;
int P[1000], V[1000], n, T[1000+1][m+1];

void mochila()
{
	for (int i = 0; i <= n; i++) T[i][0] = 0;
	for (int j = 0; j <= m; j++) T[0][j] = 0;
 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
		{
			if (P[i-1] > j) T[i][j] = T[i-1][j];
			else T[i][j] = max(T[i-1][j], T[i-1][j-P[i-1]]+V[i-1]);
		}
}

int main()
{
	int z;
	cin >> z;
	
	while (z--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> V[i] >> P[i];
		mochila();
		int k, total = 0;
		cin >> k;
		while (k--)
		{
			int a;
			cin >> a;
			total += T[n][a];
		}
		printf("%d\n", total);
	}
}

