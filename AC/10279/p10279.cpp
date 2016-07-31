#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int z, n;
char V[11][11];
vector <string> mines;
vector <string> hits;

int main()
{
	cin >> z;
        while (z--)
        {
                cin >> n;
                memset(V, '.', sizeof(V));
                mines.clear(); mines.resize(n);
                hits.clear(); hits.resize(n);
                for (int i = 0; i < n; i++) cin >> mines[i];
                for (int i = 0; i < n; i++) cin >> hits[i];

                bool EXPLODED = false;
                for (int i = 0; i  < n /*&& not EXPLODED*/; i++)
                        for (int j = 0; j < n /*&& not EXPLODED*/; j++)
                                if (hits[i][j] == 'x')
                                {
                                        if (mines[i][j] == '*') EXPLODED = true;
                                        else  // conta as minas em volta
                                        {
						V[i][j] = '0';
                                                if (i-1 > -1) if (mines[i-1][j] == '*') V[i][j]++;
                                                if (i+1 < n) if (mines[i+1][j] == '*') V[i][j]++;
                                                if (j-1 > -1) if (mines[i][j-1] == '*') V[i][j]++;
                                                if (j+1 < n) if (mines[i][j+1] == '*') V[i][j]++;
                                                
                                                if (i-1 > -1 && j-1 > -1)  if (mines[i-1][j-1] == '*') V[i][j]++;
                                                if (i-1 > -1 && j+1 < n)  if (mines[i-1][j+1] == '*') V[i][j]++;
                                                if (i+1 < n && j-1 > -1)  if (mines[i+1][j-1] == '*') V[i][j]++;
                                                if (i+1 < n && j+1 < n)  if (mines[i+1][j+1] == '*') V[i][j]++; 
                                        }
                                }
                                
                if (EXPLODED) for (int i = 0; i < n; i++)
                	      {
                        	for (int j = 0; j < n; j++) 
					if (mines[i][j] == '*') cout << '*';
					else cout << V[i][j];
	                        cout << '\n';
        	              }         
                else  for (int i = 0; i < n; i++)
                      {
                        for (int j = 0; j < n; j++) cout << V[i][j];
                        cout << '\n';
                      }         
                if (z > 0) 
                        cout << '\n';
        }
}
