#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int T[256];
int V[3][3];

string r;

int Soma(string s)
{
	int t = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (j != T[s[i]]) t += V[i][j];
	return t;
}

int main()
{
	T['B'] = 0; T['G'] = 1; T['C'] = 2;
	
	while (cin >> V[0][0] >> V[0][1] >> V[0][2] 
		   >> V[1][0] >> V[1][1] >> V[1][2] 
		   >> V[2][0] >> V[2][1] >> V[2][2] )
	{
		unsigned int MINIMO = -1; r = "";
		string s = "BCG";
		do
		{
			int t = Soma(s);
			if ( t < MINIMO )
			{
				MINIMO = t;
				r = s;
			}
		} while (next_permutation(s.begin(), s.end()));

		printf("%s %d\n", r.c_str(), MINIMO);
	}	
}	
		
