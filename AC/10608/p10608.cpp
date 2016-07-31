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
#include <cstring>

const char* const INPUT_FILE = "input";
using namespace std;

int Contado[30000];
vector< vector<int> > Matriz(30000);

int TestCases, numPessoas, numPares, a, b, grupo;

void ContaNo(int indice) // Conta Nó
{
	if (not Contado[indice])
	{
		Contado[indice] = grupo;
		for (int i = 0; i < Matriz[indice].size(); i++) ContaNo(Matriz[indice][i]);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif

	cin >> TestCases;
	for (int Caso = 0; Caso < TestCases; Caso++)
	{
		memset(Contado, 0, 30000);
		for (int i = 0; i < 30000; i++) Matriz[i].clear();
		
		cin >> numPessoas >> numPares;
		for (int i = 0; i < numPares; i++)
		{
			cin >> a >> b; a--; b--;  //como somos indexed 0 temos que decrementar a e b
			Matriz[a].push_back(b); 
			Matriz[b].push_back(a);
		}
		
		grupo = 0; // número de grupos encontrados
		for (int no = 0; no < numPessoas; no++)
		{
			// percorremos todos os nós, se ele estiver marcado com 0
			if (not Contado[no])
			{
				grupo++; // incrementamos o contador de grupo
				ContaNo(no);
			}
		}
		// ao final tendo todos os grupos separados podemos percorrer contando
		int Resultado = 0;
		for (int i = 1; i <= grupo; i++)
		{
			int Encontrados = 0;
			for (int j = 0; j < numPessoas; j++) if (Contado[j] == i) Encontrados++;
			Resultado = max(Resultado, Encontrados);
		}
		
		cout << Resultado << "\n";
	}
	return 0;
}
