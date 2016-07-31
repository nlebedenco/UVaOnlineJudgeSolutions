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
#include <functional>
#include <cstring>

char* const INPUT_FILE = "input";
using namespace std;

struct Candidato
{
	string Nome;
	string Partido;
	int Votos;
	
	Candidato()
	{
		Nome = "";
		Partido = "";
		Votos = 0;
	}
};

vector <Candidato> V;

bool Compara(const Candidato& a, const Candidato& b)
{
	return (a.Votos > b.Votos);
}

int TestCases;
int numCandidatos, numVotos;

int main()
{
	#ifndef ONLINE_JUDGE
		assert( freopen(INPUT_FILE, "rb", stdin) );
	#endif

	while (cin >> TestCases)
	{
		for (int Caso = 0; Caso < TestCases; Caso++)
		{
			cin >> numCandidatos; while (not isalpha(cin.peek())) cin.get(); // também tem espaços depois da droga dos números então tenho que ficar comendo caracteres até que a droga do caracter atual ( cin.peek() ) seja alpha!!!
			V.clear(); V.resize(numCandidatos);
			for (int i = 0; i < numCandidatos; i++)
			{	int br = 0;
				getline(cin, V[i].Nome); while((br = V[i].Nome.find(' ', br)) != string::npos) V[i].Nome.erase(br, 1);
				while (not isalpha(V[i].Nome[0]));
				getline(cin, V[i].Partido);
			}
			cin >> numVotos; while (not isalpha(cin.peek())) cin.get();
			for (int i = 0; i < numVotos; i++)
			{
				string S = ""; 
				int br = 0;
				getline(cin, S);  while((br = S.find(' ', br)) != string::npos) S.erase(br, 1);
				while (not isalpha(S[0]));
				while (S[S.size()-1] == ' '); // a meda do problema diz que nenhuma linha tem leading ou trailing spaces mas essa linha da TL, como pode????? Por causa disso vou ter que dar um trim antes nos nomes!!!
				if (not S.empty())
				{
					for (int j = 0; j < V.size(); j++)
					{
						if (V[j].Nome == S)
						{
							V[j].Votos++;
							break;
						}
					}
				}
			}
			sort(V.begin(), V.end(), Compara);
			if (V[0].Votos > V[1].Votos) cout << V[0].Partido << "\n";
			else cout << "tie\n";
			if (Caso < TestCases-1) cout << "\n";
		}	
		
	}

	return 0;
}
