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
const int SUNDAY 	= 1;
const int MONDAY 	= 2;
const int TUESDAY 	= 3;
const int WEDNESDAY 	= 4;
const int THURSDAY 	= 5;
const int FRIDAY 	= 6;
const int SATURDAY 	= 0;


int TestCases, Dias, Partidos, Periodo, Resultado;
vector <char> Simulado(3650);
int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif
     
	while(cin >> TestCases)
	{
		for (int Caso = 0; Caso < TestCases; Caso++)
		{
			fill(Simulado.begin(), Simulado.end(), 0); Resultado = 0;
			cin >> Dias >> Partidos;
			for (int x = 0; x < Partidos; x++)
			{
				cin >> Periodo;
				for (int i = 0; i <= Dias; i++) if ( (i % 7 != FRIDAY) and ( i % 7 != SATURDAY)) if (i % Periodo == 0) Simulado[i]++;
			}
			for (int i = 0; i <= Dias; i++) if (Simulado[i] > 0) Resultado++;
			
			cout << Resultado << "\n";
		}
	}
	return 0;
}
