#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const char word[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};

int z, n, m, x, y;
char V[10][10];

int main()
{
	cin >> z;
	while (z--)
	{
		cin >> m >> n;
		x = y = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) 
			{	
				cin >> V[i][j];
				if (V[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
	
		int pos = 0;
		while (V[x][y] != '#')
		{
			if (pos > 0) printf(" ");
			if (x-1 > -1) 
				if (V[x-1][y] == word[pos])
				{
					printf("forth");
				       	x--;
				}
			if (y-1 > -1)
				if (V[x][y-1] == word[pos])
				{
					printf("left");
				       	y--;
				}
			if (y+1 < n)
				if (V[x][y+1] == word[pos])
				{
					printf("right");
					y++;
				}
			pos++;
		}
		printf("\n");
	}
	return 0;
}

