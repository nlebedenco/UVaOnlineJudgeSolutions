#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int n = 1025;
const int m = 1025;

int T[n][m];
int z, d, w, a, b, c;

int res, res_x, res_y;

void Coloca(int x, int y, int p, int s)
{
	int start_i = x-s > -1?x-s:0;
	int end_i = x+s < n?x+s:n-1; 
	int start_j = y-s > -1?y-s:0;
	int end_j = y+s < m?y+s:m-1; 

	for (int i = start_i; i <= end_i; i++)
		for (int j = start_j; j <= end_j; j++)
		{
			T[i][j] += p;
			if (T[i][j] > res)
			{
				res = T[i][j];
				res_x = i;
				res_y = j;
			}
		}
}

int main()
{
	cin >> z;
	while (z--)
	{
		memset(T, 0, sizeof(T));
		res = res_x = res_y = 0;
		cin >> d >> w;
		while (w--)
		{
			cin >> a >> b >> c;
			Coloca(a, b, c, d);
		}
		printf("%d %d %d\n", res_x, res_y, res);
	}
}

