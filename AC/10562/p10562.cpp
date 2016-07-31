#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n;
const int SIZE = 202;
char M[SIZE][SIZE];

bool isValid(char c)
{
	return ( isprint(c) && not isspace(c) );
}

void Percurso(int a, int b)
{
	printf("%c(", M[a][b]); // visita 
	// Percurso de filhos
	if (a+1 < SIZE)
	{
		if ( M[a+1][b] == '|') // temos filhos logo precisamos percorrê-los
		{
				int i = b;
				while (i-1 > -1 && M[a+2][i-1] == '-') i--; // temos que descobrir o início dos filhos
				for (int j = i; j < SIZE; j++)
					if (M[a+2][j] == '-')
					{
						if ( isValid( M[a+3][j]) ) Percurso(a+3, j);
					} 
					else break;
		}
	}
	printf(")");
}

string trim(string S)
{
	S.erase(remove_if(S.begin(), S.end(), bind2nd(equal_to<char>(), ' ') ), S.end());
	return S;
}

int main()
{
	cin >> n;
	while (n--)
	{
		string S; memset(M, 0, sizeof(M));
		
		int lin = 0;
		while (getline(cin, S), S != "#") 
			if (S != "" && trim(S) != "") 
			{
				for (int i = 0; i < S.size(); i++) M[lin][i] = S[i];
				lin++;
			}

		printf("(");
		for (int i = 0; i < SIZE; i++)
			if ( isValid(M[0][i]) )	Percurso(0, i);
		printf(")\n");
	}
	return 0;
}

