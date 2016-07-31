#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

#ifdef ONLINE_JUDGE 
	#define NDEBUG
#endif

#include <assert.h>
#define INPUT_FILE "input"

using namespace std;

// 0 1 1 2 3 5 8 13 21 34 55 89 144...

string soma(string a, string b)
{
	// sabemos que b > a sempre...
	string resultado;
	resultado.reserve(100);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int vai = 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (i < a.size())
		{
			if (a[i] + b[i] - 2 * '0' + vai > 9) 
			{
				resultado.push_back( (a[i] + b[i] - 2 * '0' + vai) % 10 + '0');
				vai = 1;
			}
			else 
			{
				resultado.push_back( (a[i] + b[i] + vai - '0'));
				vai = 0;
			}
		}
		else 
		{
			if (b[i] - '0' + vai > 9) 
			{
				resultado.push_back((b[i] - '0' + vai)%10 + '0');
				vai = 1;
			}
			else
			{	resultado.push_back(b[i] + vai);
				vai = 0;
			}
		}
	}
	if (vai) resultado.push_back('0' + vai);
	reverse(resultado.begin(), resultado.end());
	return resultado;
}

int compara(string a, string b)
{
	if (a.size() != b.size()) return ((int)a.size() - (int)b.size())/ abs((int)a.size() - (int)b.size());
	else
	{
		int igual = 0;
		for (int i = 0; i < a.size() && igual == 0; i++) igual = (a[i] - b[i]);
		if (igual != 0) igual /= abs(igual);
		return igual;
	}
}

long Fibonacci(string m, string n)
{
	string a = "0";
	string b = "1";
	string c = "0";
	long cont = 0;
	while (compara(c, n) <= 0)
	{
		if (compara(c, m) >= 0 && compara(c, "1") >= 0) cont++;
		c = soma(a, b);
		a = b;
		b = c;
	}
	return cont;
}
	
int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif
     
	string Minimo, Maximo;
	while (cin >> Minimo >> Maximo, Minimo != "0" || Maximo != "0") cout << Fibonacci(Minimo, Maximo) << "\n";
	return 0;
}
