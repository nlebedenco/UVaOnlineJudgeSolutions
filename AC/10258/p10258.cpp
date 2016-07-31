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

const char AC = 'C';
const char WA = 'I';

struct TCandidato
{
	int cod;
	bool aceito[9];
	int erros[9];
	int tempo;
	int acertos;
	
	TCandidato() { init(); }
	void init()
	{
		cod = 0;
		for (int i = 0; i < 9; i++) aceito[i] = false;
		for (int i = 0; i < 9; i++) erros[i] = 0;
		tempo = 0;
		acertos = 0;
	}
} C[100];

int a, p, t;
char r;
int TestCases;

int compara(const void* x, const void* y)
{
	TCandidato* b = (TCandidato*)x;
	TCandidato* a = (TCandidato*)y;
	
	if (a->acertos == b->acertos)
	{
		if (a->tempo == b->tempo) return (b->cod - a->cod);
		else return (b->tempo - a->tempo);
	}
	else return (a->acertos - b->acertos);
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
			while (cin.peek() == '\n') cin.get();
			for (int i = 0; i < 100; i++) C[i].init();
			while (cin.peek() != '\n' && !cin.eof())
			{
				cin >> a >> p >> t >> r; cin.get();
				a--; p--; // a and p must be 0-indexed !
				if (C[a].cod == 0) C[a].cod = a+1;
				if (not C[a].aceito[p])
				{
					if (r == WA) C[a].erros[p]++;
					else if (r == AC)
					{
						C[a].aceito[p] = true;
						C[a].tempo += t + 20 * C[a].erros[p];
						C[a].acertos++;
					}
				}
			}
			qsort(C, 100, sizeof(TCandidato), compara);
			for (int i = 0; i < 100; i++) 
				if (C[i].cod != 0) cout << C[i].cod << " " << C[i].acertos << " " << C[i].tempo << "\n";
			if (Caso < TestCases - 1) cout << "\n";
		}
	}
	
	return 0;
}
