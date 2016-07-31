#ifdef ONLINE_JUDGE
	#define show(A)
	#define NDEBUG
#else
	#define show(A)  cout << #A " = " << (A) << "\n"
#endif
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>

char* const INPUT_FILE = "input";
using namespace std;

int Cor[200];
int V[200][200];
bool Correto;
int n, t, a, b;

void Colore(int pai, int NovaCor)
{
        Cor[pai] = NovaCor;
	for (int filho = 0; Correto && filho < n; filho++)
           if (V[pai][filho] == 1)
	   {
              if (Cor[filho] == -1) Colore(filho, not Cor[pai]);
              else if (Cor[filho] == Cor[pai]) Correto = false;
           }   
}

int main()
{
	#ifndef ONLINE_JUDGE
		assert( freopen(INPUT_FILE, "rb", stdin) );
	#endif

	
	while (cin >> n, n)
	{
		cin >> t;
		memset(Cor, -1, sizeof(Cor));
		memset(V, 0, sizeof(V));

		for (int i = 0; i < t; i++)
		{
			cin >> a >> b; // par de vértices ligados por uma aresta
			V[a][b] = 1;
			V[b][a] = 1;
		}
		Correto = true;
		for (int i = 0; Correto && i < n; i++)
			if (Cor[i] == -1) Colore(i, 0);
		
		if ( Correto ) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}
