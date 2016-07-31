#ifdef ONLINE_JUDGE
	#define show(A)
	#define NDEBUG
#else
	#define show(A) cout << #A " = " << (A) << "\n"
#endif
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <queue>

char * const INPUT_FILE = "input.10336";
using namespace std;

const char MARCADOR = '*';

int grupos[26];

vector <string> Mapa;
typedef pair<int, int> ponto;
queue<ponto> Fila;

int TestCases, Linhas, Colunas;
string Entrada;
char Letra;

vector <pair <int, char> > Resultado;

void EnfilaVizinhos(ponto T, char c)
{
	if (T.first > -1 && T.second > -1 && T.first < Linhas && T.second < Colunas)
		if (Mapa[T.first][T.second] == c) 
		{
			Mapa[T.first][T.second] = MARCADOR;
			Fila.push(T);
		}
}	

bool Compara(const pair <int, char>& a, const pair<int, char>& b)
{
	if (a.first > b.first) return true;
	else if (a.first == b.first) return a.second < b.second;
	else return false; 
		
}

int main()
{
	#ifndef ONLINE_JUDGE
		assert(freopen(INPUT_FILE, "rb", stdin));
	#endif
	
	cin >> TestCases;
	for (int Caso = 0; Caso < TestCases; Caso++)
	{
		Mapa.clear();
		cin >> Linhas >> Colunas;
		for (int i = 0; i < Linhas; i++) 
		{
			cin >> Entrada; 
			Mapa.push_back(Entrada);
		}
		
		for (int i = 0; i < 26; i++) grupos[i] = 0;  // limpa grupos
		
		for (int i = 0; i < Linhas; i++)
			for (int j = 0; j < Colunas; j++)
				if (Mapa[i][j] != MARCADOR)
				{
 				 	while (not Fila.empty()) Fila.pop(); // Esvazia Fila
					Letra = Mapa[i][j]; grupos[Letra - 'a']++; // incrementa grupo de letra
					Fila.push(ponto(i, j)); Mapa[i][j] = MARCADOR;
					while(not Fila.empty())
					{
						ponto Q, P = Fila.front(); Fila.pop();
						Q = P; Q.first--; EnfilaVizinhos(Q, Letra);
						Q = P; Q.first++; EnfilaVizinhos(Q, Letra);
						Q = P; Q.second--; EnfilaVizinhos(Q, Letra);
						Q = P; Q.second++; EnfilaVizinhos(Q, Letra);
					}
				}
		Resultado.clear();
		for (int i = 0; i < 26; i++) 
			if (grupos[i] > 0) Resultado.push_back(pair<int, char>(grupos[i], char('a' + i)));

		sort(Resultado.begin(), Resultado.end(), Compara);		
		
		cout << "World #" << Caso +1 << "\n";
		for (int i = 0; i < Resultado.size(); i++) cout << Resultado[i].second << ": " << Resultado[i].first << "\n";
	}	
	
	
	return 0;
}

