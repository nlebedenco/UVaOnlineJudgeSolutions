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
#include <cstdio>
#include <cmath>

const char* const INPUT_FILE = "input";
using namespace std;

int TestCases;
string S1, S2;
unsigned int D1, D2, maxDiv;

unsigned int MDC(unsigned int a, unsigned int b)
{
	if (a == b) return a;
	if (b > a) swap(a, b);
	unsigned int r = 1;
	while (r != 0)
	{
		r = a % b; 
		a = b; 
		b = r;
	}
	return a;
}

//Converte um número de uma base qualquer para decimal
unsigned int ConverteDecimal(const string& S, const int Base)
{
	unsigned int result = 0;
	for (int i = 0; i < S.size(); i++) 
		result += ( (unsigned int)pow(double(Base), i) * (S[S.size()-i-1] - '0') );
	return result;	
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
			cin >> S1 >> S2;
			
			if (S1 == S2 || (S1[S1.size()-1] == '0' && S2[S2.size()-1] == '0') ) printf("Pair #%d: All you need is love!\n", Caso+1);
			else if (MDC(ConverteDecimal(S1, 2), ConverteDecimal(S2, 2)) > 1) printf("Pair #%d: All you need is love!\n", Caso+1);
			else printf("Pair #%d: Love is not all you need!\n", Caso+1);
		}
	}
	return 0;
}
