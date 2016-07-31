#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

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

const char FIM = 'X';
const char WHITE = 'O';
const string Validos = "ICLVHKFSX";
char Comando;
int M, N, X, Y, X1, X2, Y1, Y2;
char Cor;
string Nome;

struct {
	char Canvas[250][250];
	int Width, Height;
	} Tela;

void Limpar()
{
	for (int i = 0; i < Tela.Height; i++) 
	   for (int j = 0; j < Tela.Width; j++) Tela.Canvas[i][j] = WHITE;
}

void Dimensionar(int a, int b)
{	
	Tela.Width = a;
	Tela.Height = b; 
	Limpar();
}

void Colorir(int a, int b, char c)
{
	Tela.Canvas[b][a] = c;
}

void LinhaVertical(int a, int b1, int b2, char c)
{
	int z;
	if (b1 > b2)
	{
		z = b1;
		b1 = b2;
		b2 = z;
	}
	for (int i = b1; (i <= b2); i++) Tela.Canvas[i][a] = c; 
}

void LinhaHorizontal(int a1, int a2, int b, char c)
{
	int z;
	if (a1 > a2)
	{
		z = a1;
		a1 = a2;
		a2 = z;
	}
	for (int i = a1; (i <= a2); i++) Tela.Canvas[b][i] = c; 
}

void Retangulo(int a1, int b1, int a2, int b2, char c)
{
	for (int i = b1; i <= b2; i++)
		for (int j = a1; j <= a2; j++) Tela.Canvas[i][j] = c;
}

void FloodFill(int a, int b, char c)
{
	/* ** --> Usando Fila o Valladolid diz que dá Memory Limit Exceeded!!

	queue < pair <int, int> > Fila;	
	char Cor_Original = Tela.Canvas[b][a];
	Tela.Canvas[b][a] = c;
	Fila.push( pair <int, int> (b, a) );
	while (not Fila.empty())
	{
		b = Fila.front().first;
		a = Fila.front().second;
		Fila.pop();
		if ((b-1 > -1) && (Tela.Canvas[b-1][a] == Cor_Original))  // Norte
		{
			Tela.Canvas[b-1][a] = c;
			Fila.push( pair <int, int> (b-1, a) );
		}
		if ((a+1 < Tela.Width) && (Tela.Canvas[b][a+1] == Cor_Original))  // Leste
		{
			Tela.Canvas[b][a+1] = c;
			Fila.push( pair <int, int> (b, a+1) );
		}
		if ((b+1 < Tela.Height) && (Tela.Canvas[b+1][a] == Cor_Original))  // Sul
		{
			Tela.Canvas[b+1][a] = c;
			Fila.push( pair <int, int> (b+1, a) );
		}
		if ((a-1 > -1) && (Tela.Canvas[b][a-1] == Cor_Original))  // Oeste
		{
			Tela.Canvas[b][a-1] = c;
			Fila.push( pair <int, int> (b, a-1) );
		}
	}
	*/
	// Recursivamente passa!
	char Cor_Original = Tela.Canvas[b][a];
	Tela.Canvas[b][a] = c;
	if ((b-1 > -1) && (Tela.Canvas[b-1][a] == Cor_Original))  // Norte
		FloodFill(a, b-1, c);
	if ((a+1 < Tela.Width) && (Tela.Canvas[b][a+1] == Cor_Original))  // Leste
		FloodFill(a+1, b, c);
	if ((b+1 < Tela.Height) && (Tela.Canvas[b+1][a] == Cor_Original))  // Sul
		FloodFill(a, b+1, c);
	if ((a-1 > -1) && (Tela.Canvas[b][a-1] == Cor_Original))  // Oeste
		FloodFill(a-1, b, c);
}

void Imprime(string s)
{
	cout << s << "\n";
	for (int i = 0; i < Tela.Height; i++)
	{
		for (int j = 0; j < Tela.Width; j++) cout << Tela.Canvas[i][j];
		cout << "\n";
	}
}


int main()
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
     
	while (cin >> Comando, Comando != FIM)
	{
		if (Validos.find(Comando) == string::npos) cin.ignore(256, '\n'); // ignora comandos diferentes dos válidos
		switch(Comando)
		{
			case 'I': cin >> M >> N;
				  Dimensionar(M, N);
				  break;
			case 'C': Limpar();
				  break;
			case 'L': cin >> X >> Y >> Cor;
				  Colorir (X-1, Y-1, Cor);
			 	  break;
			case 'V': cin >> X >> Y1 >> Y2 >> Cor; 
				  LinhaVertical(X-1, Y1-1, Y2-1, Cor);
				  break;
			case 'H': cin >> X1 >> X2 >> Y >> Cor;
				  LinhaHorizontal(X1-1, X2-1, Y-1, Cor);
				  break;
			case 'K': cin >> X1 >> Y1 >> X2 >> Y2 >> Cor;
				  Retangulo(X1-1, Y1-1, X2-1, Y2-1, Cor);
				  break;
			case 'F': cin >> X >> Y >> Cor;
				  if (Cor != Tela.Canvas[Y-1][X-1]) FloodFill(X-1, Y-1, Cor);  // Tem que testar pra saber se o ponto já está pitado da cor desejada!
				  break;
			case 'S': cin >> Nome;
				  Imprime(Nome);
				  break;
		}
	}
	return 0;
}
