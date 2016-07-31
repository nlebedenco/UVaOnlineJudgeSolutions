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

const char VAZIO = '-';
const char MARCADO = 'o';

string linhaoriginal;
int TestCases;
int Resultado;

void resolve(string linha, int x)
{
	string linharecebida = linha;
	for (int i = x; i < linha.size(); i++)
	{
		if (linha[i] == MARCADO)
		{
			if (i+1 < linha.size()) if (linha[i+1] == MARCADO)
				if (i+2 < linha.size()) if (linha[i+2] == VAZIO)
				{
					linha[i] = VAZIO;
					linha[i+1] = VAZIO;
					linha[i+2] = MARCADO;
					resolve(linha, 0);
				}
			linha = linharecebida;
			if (i-1 > -1) if (linha[i-1] == MARCADO)
				if (i-2 > -1) if (linha[i-2] == VAZIO)
				{
					linha[i] = VAZIO;
					linha[i-1] = VAZIO;
					linha[i-2] = MARCADO;
					resolve(linha, 0);
				}
		}
	}
	int Total = 0; //cout << "Resultado: " << linha << "\n";
	for (int i = 0; i < linha.size(); i++) if (linha[i] == MARCADO) Total++;
	Resultado = min(Resultado, Total);
}

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif

	while (cin >> TestCases)
	{
		for (int Caso = 0; Caso < TestCases; Caso++)
		{
			cin >> linhaoriginal;
			Resultado = 13;
			resolve(linhaoriginal, 0);
			
			cout << Resultado << "\n";
		}
	}
	
	return 0;
}
