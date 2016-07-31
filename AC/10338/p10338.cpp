#ifdef ONLINE_JUDGE
	#define show(A)
	#define NDEBUG
#else
	#define show(A)  cout << #A " = " << (A) << "\n"
#endif
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

char* const INPUT_FILE = "input";
using namespace std;

int TestCases;
string S;

vector<long long> Repetidas;

long long fatorial(int n)
{
	long long resposta = 1;
	for (int i = 1; i <= n; i++) resposta *= i;
	return resposta;
	
}

long long Calcula(int n, vector<long long> V)
{
	if (V.empty()) return fatorial(n);
	else
	{
		long long resposta = 1;
		for (int i = 1; i <= n; i++) 
		{
			resposta *= i;
			for (int j = 0; j < V.size(); j++) 
				if (resposta%fatorial(V[j]) == 0)
				{
					resposta /= fatorial(V[j]); 
					V[j] = 1;
				}
		}
		return resposta;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		assert( freopen(INPUT_FILE, "rb", stdin) );
	#endif

	while(cin >> TestCases)
	{
		for (int Caso = 0; Caso < TestCases; Caso++)
		{
			cin >> S;
			sort(S.begin(), S.end());
			
			Repetidas.clear();
			int i = 0; 
			while (i < S.size())
			{
				char c = S[i]; int R = 0;
				for (; i < S.size() && S[i] == c; i++) R++;
				if (R > 1) Repetidas.push_back(R);
			}
			
			//for(int i = 0; i < Repetidas.size(); i++) show(Repetidas[i]);
			cout << "Data set " << Caso+1 << ": " << Calcula(S.size(), Repetidas) << "\n";
		}
	}
	return 0;
}
