#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

const char direction[] = {' ', 'N', 'E', 'S', 'W'};

string V[60];
int n, m, z, x, y, dir;
char cmd;

int main()
{
	cin >> z;
	while (z--)
	{
		cin >> m >> n;
		cin.get();
		for (int i = 0; i < m; i++) getline(cin, V[i]);
		
		cin >> x >> y;
		x--; y--; // to make it 0-indexed
		dir = 1; // North

		while (cin >> cmd, cmd != 'Q')
		{
			switch(cmd)
			{
				case 'R': dir = dir % 4 + 1; break;
				case 'L': dir = (dir > 1)?dir-1:4; break;
				case 'F':
					  if (dir == 1) 
					  { 
						  if (x-1 > -1)
							  if (V[x-1][y] != '*') x--;
					  }
					  else if (dir == 2) 
					  {
						if (y+1 < n)
							if (V[x][y+1] != '*') y++;
					  }
					  else if (dir == 3) 
					  {
						  if (x+1 < m)
							  if (V[x+1][y] != '*') x++;
					  }
					  else if (dir == 4) 
					  {
						  if (y-1 > -1)
							  if (V[x][y-1] != '*') y--;
					  }
			}	
		}
		printf("%d %d %c\n", x+1, y+1, direction[dir]);
		if (z > 0) printf("\n");
	}	
	return 0;
}
