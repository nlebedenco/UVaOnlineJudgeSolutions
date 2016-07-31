#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool T[22501][51];
int P[100], n, m, z;

void mochila()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > 0; j--)
			if (j+P[i] <= m)
				for (int k = 1; k <= n/2; k++)
					if (T[j][k])
					{
						T[j+P[i]][k+1] = true;
						if (T[m][n/2] || (n%2 != 0 && T[m][n/2+1])) return;
					}
		T[P[i]][1] = true;
	}
}

int main()
{
	cin >> z;
	while (z--)
	{
		cin >> n;
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> P[i];
			p += P[i];
		}
		m = p/2;
		memset(T, 0, m*sizeof(T[0]));		
		mochila();

		for (; m > 0; m--)
		{
			if (T[m][n/2]) break;
			else if (n%2 != 0 && T[m][n/2+1]) break;
		}

		int a = m, b = p-m;
		if (a > b) swap(a, b);
		printf("%d %d\n", a, b);
		if (z) printf("\n");
	}	
}
