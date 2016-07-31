#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int V[] = {1, 5, 10}, P[3], C, inserted, z;

int T(int c, int f, int t)
{
	int o = P[0]*V[0]+P[1]*V[1]+P[2]*V[2]-8*c-5*f-10*t; 
	int m = 10000000;
	if (o >= 8) m = min (m, T(c-1, f, t)); 
	if (f >= 2) m = min (m, T(c-1, f-2, t)); 
	if (t >= 1) m = min (m, T(c-1, f, t-1)); 
	if (f >= 1 && o >=3) m = min (m , T(c-1, f-1, t)); 
	if (t >= 1 && o >=3) m = min (m , T(c-1,f+1,t-1)); 
	return m; 
}

int main()
{
	cin >> z;
	while (z--)
	{
		cin >> C >> P[0] >> P[1] >> P[2];	
		
		printf("%d\n", T(C, P[1], P[2]));

		
		printf("%d\n", inserted);
	}
}

