#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
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

const int COLUNAS = 8;
const int LINHAS = 8;
const char REI_BRANCO = 'K';
const char REI_PRETO  = 'k';

vector <string> Tabuleiro;
string Linha;
int numGame = 0;

bool ReiPresente(const char REI)
{
	for (int i = 0; i < LINHAS; i++) if (Tabuleiro[i].find( REI ) != string::npos) return true;
	return false;
}

void EncontraPeca(char c, int *a, int *b)
{
	*b = string::npos;
	for (int i = 0; i < LINHAS && *b == string::npos; i++)
	{
		*a = i;
		*b = Tabuleiro[i].find( c );
	}
}

// Encontra o Rei Branco e vê se ele está em cheque
bool ReiEmCheque(const char REI, const char DAMA, const char BISPO, const char CAVALO, const char TORRE, const char PEAO)
{
	int lin = 0, col = 0 ;
	EncontraPeca(REI, &lin, &col);
	
	// Percorremos os 6 sentidos em torno do rei até encontrarmos uma peça
	// se a peça for adversária, vemos se alcança o rei
	
	// na vertical e horizontal pode ser uma Dama ou Torre adversária
	
	int i, j;
	
	if (col+1 < COLUNAS) 
	{ 
		for (i = col+1; i < COLUNAS && Tabuleiro[lin][i] == '.'; i++);
		if (i < COLUNAS) if ((Tabuleiro[lin][i] == TORRE) || (Tabuleiro[lin][i] == DAMA)) return true;
	}
	if (col-1 > -1)
	{
		for (i = col-1; i > -1 && Tabuleiro[lin][i] == '.'; i--);
		if (i > -1) if ((Tabuleiro[lin][i] == TORRE) || (Tabuleiro[lin][i] == DAMA)) return true;
	}
	if (lin+1 < LINHAS) 
	{
		for (i = lin+1; i < LINHAS && Tabuleiro[i][col] == '.'; i++);
		if (i < LINHAS) if ((Tabuleiro[i][col] == TORRE) || (Tabuleiro[i][col] == DAMA)) return true;
	}
	if (lin-1 >-1) 
	{
		for (i = lin-1; i > -1 && Tabuleiro[i][col] == '.'; i--);
		if (i > -1) if ((Tabuleiro[i][col] == TORRE) || (Tabuleiro[i][col] == DAMA)) return true;
	}
	
	// nas diagonais pode ser Dama ou Bispo
	
	if (col-1 > -1 && lin-1 > -1) 
	{
		for (i=lin-1, j=col-1; (i > -1) && (j > -1) && (Tabuleiro[i][j] == '.'); i--, j--);
		if (i > -1 && (j > -1) ) if ((Tabuleiro[i][j] == BISPO) || (Tabuleiro[i][j] == DAMA)) return true;
	}
	if (col+1 < COLUNAS && lin-1 > -1) 
	{
		for (i=lin-1, j=col+1; i > -1 && j < COLUNAS && Tabuleiro[i][j] == '.'; i--, j++);
		if (i > -1 && j < COLUNAS) if ((Tabuleiro[i][j] == BISPO) || (Tabuleiro[i][j] == DAMA)) return true;
	}
	if (col+1 < COLUNAS && lin+1 < LINHAS)
	{
		for (i=lin+1, j=col+1; i < LINHAS && j < COLUNAS && Tabuleiro[i][j] == '.'; i++, j++);
		if (i < LINHAS && j < COLUNAS) if ((Tabuleiro[i][j] == BISPO) || (Tabuleiro[i][j] == DAMA)) return true;
	}
	if (col-1 > -1 && lin+1 < LINHAS)
	{
		for (i=lin+1, j=col-1; i < LINHAS && j > -1 && Tabuleiro[i][j] == '.'; i++, j--);
		if (i < LINHAS && j > -1) if ((Tabuleiro[i][j] == BISPO) || (Tabuleiro[i][j] == DAMA)) return true;
	}
	
	// nas duas casas das digonais acima pode ser peão
	
	if (REI == REI_BRANCO)
	{
		if (lin-1 > -1 && col+1 < COLUNAS) if (Tabuleiro[lin-1][col+1] == PEAO) return true;
		if (lin-1 > -1 && col-1 > -1) if (Tabuleiro[lin-1][col-1] == PEAO) return true;
	}
	
	if (REI == REI_PRETO)
	{
		if (lin+1 < LINHAS && col+1 < COLUNAS) if (Tabuleiro[lin+1][col+1] == PEAO) return true;
		if (lin+1 < LINHAS && col-1 > -1) if (Tabuleiro[lin+1][col-1] == PEAO) return true;
	}
	
	// e pode haver cavalos em até oita casas em redor do rei então vejamos...
	
	if (lin-2 > -1 && col-1 > -1) if (Tabuleiro[lin-2][col-1] == CAVALO) return true;
	if (lin-2 > -1 && col+1 < COLUNAS) if (Tabuleiro[lin-2][col+1] == CAVALO) return true;
	if (lin-1 > -1 && col-2 > -1) if (Tabuleiro[lin-1][col-2] == CAVALO) return true;
	if (lin-1 > -1 && col+2 < COLUNAS) if (Tabuleiro[lin-1][col+2] == CAVALO) return true;
	if (lin+2 < LINHAS && col-1 > -1) if (Tabuleiro[lin+2][col-1] == CAVALO) return true;
	if (lin+2 < LINHAS && col+1 < COLUNAS) if (Tabuleiro[lin+2][col+1] == CAVALO) return true;
	if (lin+1 < LINHAS && col-2 > -1) if (Tabuleiro[lin+1][col-2] == CAVALO) return true;
	if (lin+1 < LINHAS && col+2 < COLUNAS) if (Tabuleiro[lin+1][col+2] == CAVALO) return true;
	
	
	return false;
}

int main()
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
     
	int i = 0;
	while (cin >> Linha)
	{
		if (++i <= LINHAS) Tabuleiro.push_back(Linha);
		else
		{
			if (not (ReiPresente('K') and ReiPresente('k'))) return 0; // se encontrou um tabuleiro sem reis
			
			if (ReiEmCheque('K', 'q', 'b', 'n', 'r', 'p')) cout << "Game #" << ++numGame << ": white king is in check." << "\n";
			else if (ReiEmCheque('k', 'Q', 'B', 'N', 'R', 'P')) cout << "Game #" << ++numGame << ": black king is in check." << "\n";
			else cout << "Game #" << ++numGame << ": no king is in check." << "\n";
			
			Tabuleiro.clear(); // Limpa o tabuleiro!
			Tabuleiro.push_back(Linha); // pega a linha do último teste do while que ficou pendente...
			i = 1; // ... e reseta o contador de linhas
		}
	}
	return 0;
}
