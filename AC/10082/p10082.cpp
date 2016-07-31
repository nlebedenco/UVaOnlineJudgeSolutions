#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

#ifdef ONLINE_JUDGE 
	#define NDEBUG
#endif

#include <assert.h>
#define INPUT_FILE "input"

using namespace std;

const string Tabela = "`1234567890-=QQWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
string Linha;

char Decodifica(char c)
{
	if (c == ' ') return c;
	int it = Tabela.find(c);
	if (it != string::npos) return (Tabela[it-1]);
	else return string::npos;
}

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif

	while (getline(cin, Linha), cin)
	{
		for (int i = 0; i < Linha.size(); i++) cout << Decodifica(Linha[i]);
		cout << "\n";
	}
	return 0;
}
