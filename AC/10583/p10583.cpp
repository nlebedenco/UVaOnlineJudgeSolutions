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
#include <queue>
#include <cassert>

char* const INPUT_FILE = "input";
using namespace std;

vector < vector <int> > Aluno;
vector <int> Verificado;
queue<int> Fila;
int numAlunos, Pares;

int main()
{
	#ifndef ONLINE_JUDGE
		assert( freopen(INPUT_FILE, "rb", stdin) );
	#endif

	int Caso = 0;
	while (cin >> numAlunos >> Pares, (numAlunos || Pares) )
	{
		Caso++;
		Aluno.clear(); Verificado.clear();
		Aluno.resize(numAlunos); Verificado.resize(numAlunos);
		for (int i = 0; i < Pares; i++)
		{
			int a, b;
			cin >> a >> b; a--; b--;
			Aluno[b].push_back(a);
			Aluno[a].push_back(b);
		}
		int grupo  = 0;
		int Atual = 0;
		
		while (Atual < numAlunos)
		{
			grupo++;
			Fila.push(Atual); Verificado[Atual] = grupo;
			while (not Fila.empty())
			{
				int P = Fila.front(); Fila.pop();
				for (int i = 0; i < Aluno[P].size(); i++)
				{
					if (not Verificado[Aluno[P][i]])
					{
						Verificado[Aluno[P][i]] = grupo;
						Fila.push(Aluno[P][i]);
					}
				}
			}
			// Pega o próximo sem grupo
			for (; Verificado[Atual] > 0; Atual++);
		}
		cout << "Case " << Caso << ": " << grupo << "\n";
	}
	return 0;
}
