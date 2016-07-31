#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using namespace std;

int m, n;
int T[101][101];
int A[101], B[101];
int caso;
int main()
{
	caso = 0;
	while (cin >> m >> n, m && n)
	{
		caso++;
		for (int i = 1; i <= m; i++) cin >> B[i];
		for (int i = 1; i <= n; i++) cin >> A[i];

		// SMC
		for (int i = 1; i <= m; i++) T[i][0] = 0;
		for (int i = 1; i <= n; i++) T[0][i] = 0;

		for (int i  = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (A[i] == B[j]) T[i][j] = T[i-1][j-1] + 1;
				else if ( T[i-1][j] >= T[i][j-1] ) T[i][j] = T[i-1][j];
				else T[i][j] = T[i][j-1];
			}
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) res = max(res, T[i][j]);
				
		printf("Twin Towers #%d\n", caso);
		printf("Number of Tiles : %d\n\n", res);
			
	}
	return 0;
}
