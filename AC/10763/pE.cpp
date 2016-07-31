#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

const int SIZE = 500001;
int Matriz[SIZE][2];

int n;

int main()
{
	while (cin >> n, n)
	{
		memset(Matriz, 0, sizeof(Matriz));
		int a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			Matriz[a][0]++;  // sai de A
			Matriz[b][1]++;  // entra em B
			
		}
		bool correto = true;
		for (int i = 0; i < SIZE && correto; i++)
		{
			if (Matriz[i][0] != Matriz[i][1]) 
			{
				correto = false; 
				break;
			}
		}
		if (not correto) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
} 
