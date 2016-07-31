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


vector <int> V;
int TestCases, Relatives;

int somatorio(int x)
{
	int Resultado = 0;
	for (int i = 0; i < V.size(); i++) Resultado += abs(V[i] - x);
	return Resultado;
}

int main()
{
	#ifndef ONLINE_JUDGE
		assert( freopen(INPUT_FILE, "rb", stdin) );
	#endif

	while (cin >> TestCases)
	{
		for (int Caso = 0; Caso < TestCases; Caso++)
		{
			cin >> Relatives;
			V.clear(); V.resize(Relatives);
			for (int j = 0; j < Relatives; j++) cin >> V[j];
			
			sort(V.begin(), V.end()); 
			if (V.size() == 1) cout << "0\n";
			else if (V.size() == 2) cout << abs(V[0] - V[1]) << "\n";
			else cout << somatorio(V[V.size() / 2]) << "\n";
		}
	}
	return 0;
}
