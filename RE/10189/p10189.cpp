#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#ifdef VALLADOLID 
	#define ONLINE_JUDGE
#endif

#ifdef ONLINE_JUDGE 
	#define NDEBUG
#endif

#include <assert.h>

#ifndef ONLINE_JUDGE
	#define TEST_INPUT_FILE "input"
	#ifdef DEBUG_OUTPUT
		#define TEST_OUTPUT_FILE "model.out"
	#endif
#endif

using namespace std;

	const char MINA = '*';

	vector <string> Campo;
	int Linhas, Colunas;
	string Entrada; 

void Incrementa(int a, int b)
{
	if (Campo[a][b] == MINA) return;
	if (Campo[a][b] == '.') Campo[a][b] = '0';
	Campo[a][b]++;
	
}

void IncrementaVizinhos(int a, int b)
{
	if (a-1 > -1 ) Incrementa(a-1, b); // norte
	if ((a-1 > -1) && (b+1 < Colunas)) Incrementa(a-1, b+1); // Nordeste
	if (b+1 < Colunas) Incrementa(a, b+1); // Leste
	if ((a+1 < Linhas) && (b+1 < Colunas)) Incrementa(a+1, b+1); // Sudeste
	if (a+1 < Linhas) Incrementa(a+1, b); // Sul
	if ((a+1 < Linhas) && (b-1 > -1)) Incrementa(a+1, b-1); // Sudoeste
	if (b-1 > -1) Incrementa(a, b-1); //Oeste
	if ((a-1 > -1) && (b-1 > -1)) Incrementa(a-1, b-1); // Noroeste
}

int main()
	
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
		
	int TestCase = 0;
	while (cin >> Linhas >> Colunas, Linhas && Colunas)
	{
		if (TestCase > 0) cout << "\n";  // só imprime uma quebra de linha a mais entre dois output cases!
		
		Campo.clear(); Campo.reserve(Linhas);	
		for (int i = 0; i < Linhas; i++)
		{
			cin >> Entrada;
			Campo.push_back(Entrada);
		}
		
		for (int i = 0; i < Linhas; i++)
			for (int j = 0; j < Colunas; j++)
				if (Campo[i][j] == MINA) IncrementaVizinhos(i, j);

		for (int i = 0; i < Linhas; i++)
		{
			unsigned int Indice = Campo[i].find('.');
			while( Indice != string::npos) 
			{
    				Campo[i].replace(Indice, 1, "0");
				Indice = Campo[i].find('.');
			}
		}
		cout << "Field #" << ++TestCase << ":\n";
		for (int i = 0; i < Linhas; i++) cout << Campo[i] << "\n";
	}	
	
	return 0;
}


