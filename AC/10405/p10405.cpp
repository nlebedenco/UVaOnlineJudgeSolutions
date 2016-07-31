#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string A, B;
int T[1001][1001];

void SMC()
{
  int n = A.size(), m = B.size();
  for (int i = 0; i <= n; i++) T[i][0] = 0;
  for (int j = 0; j <= m; j++) T[0][j] = 0;
  for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++)
        if (A[i-1] == B[j-1]) 
            T[i][j] = T[i-1][j-1]+1;
        else T[i][j] = max(T[i-1][j], T[i][j-1]);
			
} 

int main()
{
	while (getline(cin, A) && getline(cin, B))
	{
		SMC();
		printf("%d\n", T[A.size()][B.size()]);
	}
}