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
int Contador, numPalavras;
string Palavra;
vector<string> Palavras;
vector<string> Resultado;
typedef vector<string>::iterator StringIterator;


int LetrasComuns (string S1, string S2)
{
	int i;
	for (i = 0; i < S1.size() && i < S2.size() && S1[i] == S2[i]; i++);
	return i;
}

string ProximaPalavra(string S)
{

	StringIterator it = find(Palavras.begin(), Palavras.end(), S);
	*it = "";
	
	string MelhorPalavra = "";
	for (int i = 0; i < Palavras.size(); i++)
		if (not Palavras[i].empty())
			MelhorPalavra = LetrasComuns(MelhorPalavra, S) > LetrasComuns(Palavras[i], S)? MelhorPalavra: Palavras[i];
	
	return MelhorPalavra;
}

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif

	cin >> TestCases;
	for (int Caso = 0; Caso < TestCases; Caso++)
	{
		cin >> numPalavras; 
		Palavras.clear(); Palavras.reserve(numPalavras); 
		Resultado.clear(); Resultado.reserve(numPalavras);
		Contador = 0;
		for (int i = 0; i < numPalavras; i++)
		{
			cin >> Palavra;
			Palavras.push_back(Palavra);
		}
		
		
		string PalavraAnterior = Palavras[0]; 
			Resultado.push_back(PalavraAnterior); 
		while (Resultado.size() < numPalavras) 
		{
			string PalavraDaVez = ProximaPalavra(PalavraAnterior);
			Resultado.push_back(PalavraDaVez);
			PalavraAnterior = PalavraDaVez;
		}
		
		Contador += Resultado[0].size();
		for (int i = 1; i < Resultado.size(); i++)
			Contador += Resultado[i].size() - LetrasComuns(Resultado[i], Resultado[i-1]);
		
		cout << Contador << "\n";
		for (int i = 0; i < Resultado.size(); i++) cout << Resultado[i] << "\n";
	}
	
	return 0;
}
