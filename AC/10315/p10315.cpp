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

const string SEQUENCIA = "23456789VWXYZ";
const int STRAIGHT_FLUSH 	= 160;
const int FOUR_OF_A_KIND 	= 140;
const int FULL_HOUSE		= 120;
const int FLUSH			= 100;
const int STRAIGHT		= 80;
const int THREE_OF_A_KIND	= 60;
const int TWO_PAIR		= 40;
const int PAIR			= 20;
const int NADA			= 0;


string w1, w2, w3, w4, w5, b1, b2, b3, b4, b5;
vector <string> Branco, Preto;
int Jogo_Branco, Jogo_Preto;

string Codifica(string s)
{
	string Resultado = s;
	switch (Resultado[0])
	{
		case 'A': Resultado[0] = 'z'; break;
		case 'K': Resultado[0] = 'y'; break;
		case 'Q': Resultado[0] = 'x'; break;
		case 'J': Resultado[0] = 'w'; break;
		case 'T': Resultado[0] = 'v'; break;
		case '9': Resultado[0] = 'u'; break;
		case '8': Resultado[0] = 't'; break;
		case '7': Resultado[0] = 's'; break;
		case '6': Resultado[0] = 'r'; break;
		case '5': Resultado[0] = 'q'; break;
		case '4': Resultado[0] = 'p'; break;
		case '3': Resultado[0] = 'o'; break;
		case '2': Resultado[0] = 'n'; break;
	}; 
	
	return Resultado;
}

bool MesmoNaipe(const vector<string>& t)
{
	bool correto = true;
	for (int i = 1; i < t.size() && correto; i++) correto = (t[i][1] == t[i-1][1]);
	return correto;
}

bool Consecutivas(const vector<string>& t)
{
	bool correto = true;
	for (int i = 1; i < t.size() && correto; i++) correto = (t[i][0] == t[i-1][0] +1);
	return correto;
}

bool Quadra(vector<string>& t)
{
	bool correto = false;
	if ( (t[0][0] == t[1][0]) && (t[0][0] == t[2][0]) && (t[0][0] == t[3][0]) ) 
	{
		t.push_back(t[0]);  // pro desempate
		return true;
	}
	if ( (t[1][0] == t[2][0]) && (t[1][0] == t[3][0]) && (t[1][0] == t[4][0]) )
	{
		t.push_back(t[1]); // pro desempate
		return true;
	}
	return false;
}

bool FullHouse(vector<string>& t)
{
	if ( (t[0][0] == t[1][0]) && ((t[2][0] == t[3][0]) && (t[2][0] == t[4][0])) ) 
	{
		t.push_back(t[2]);  // pro desempate
		return true;
	}
	if ( ((t[0][0] == t[1][0]) && (t[0][0] == t[2][0])) && (t[3][0] == t[4][0]) )
	{
		t.push_back(t[0]);  // pro desempate
		return true;
	}
	return false;
}

bool Trinca(vector<string>& t)
{
	if ( (t[0][0] == t[1][0]) && (t[0][0] == t[2][0]) ) 
	{
		t.push_back(t[0]);
		return true;
	}
	if ( (t[1][0] == t[2][0]) && (t[1][0] == t[3][0]) ) 
	{
		t.push_back(t[1]);
		return true;
	}
	if ( (t[2][0] == t[3][0]) && (t[2][0] == t[4][0]) ) 
	{
		t.push_back(t[2]);
		return true;
	}
	return false;
}

bool TwoPair(vector<string>& t)
{
	if ( (t[0][0] == t[1][0]) && (t[2][0] == t[3][0]) )
	{
		t.push_back( max(t[0], t[2]) );
		t.push_back( min(t[0], t[2]) );
		t.push_back(t[4]);
		return true;
	}
	if ( (t[0][0] == t[1][0]) && (t[3][0] == t[4][0]) )
	{
		t.push_back( max(t[0], t[3]) );
		t.push_back( min(t[0], t[3]) );
		t.push_back(t[2]);
		return true;
	}
	if ( (t[1][0] == t[2][0]) && (t[3][0] == t[4][0]) )
	{
		t.push_back( max(t[1], t[3]) );
		t.push_back( min(t[1], t[3]) );
		t.push_back(t[0]);
		return true;
	}
	return false;
}

bool Pair(vector<string>& t)
{
	if (t[0][0] == t[1][0]) 
	{
		t.push_back(t[0]);
		t.push_back(t[4]);
		t.push_back(t[3]);
		t.push_back(t[2]);
		return true;
	}
	if (t[1][0] == t[2][0])
	{
		t.push_back(t[1]);
		t.push_back(t[4]);
		t.push_back(t[3]);
		t.push_back(t[0]);
		return true;
	}
	if (t[2][0] == t[3][0])
	{
		t.push_back(t[2]);
		t.push_back(t[4]);
		t.push_back(t[1]);
		t.push_back(t[0]);
		return true;
	}
	if (t[3][0] == t[4][0])
	{
		t.push_back(t[3]);
		t.push_back(t[2]);
		t.push_back(t[1]);
		t.push_back(t[0]);
		return true;
	}
	return false;
}

int Jogo(vector<string>& t)
{
	if ( MesmoNaipe(t) ) // Tem straight flush ou flush!
	{
		if ( Consecutivas(t) ) return STRAIGHT_FLUSH;
		else return FLUSH;
	}
	else
	{
		if ( Consecutivas(t) ) return STRAIGHT;
		else
		{
			if ( Quadra(t) ) return FOUR_OF_A_KIND;
			else if ( FullHouse(t) ) return FULL_HOUSE;
			else if ( Trinca(t) ) return THREE_OF_A_KIND;
			else if ( TwoPair(t) ) return TWO_PAIR;
			else if ( Pair(t) ) return PAIR;
			else return NADA;
		}
	}
}

int Desempate (char b, char p)
{
	if ( b > p ) 
	{
		cout << "White wins." << "\n"; 
		return true;
	}
	else if ( b < p ) 
	{
		cout << "Black wins." << "\n"; 
		return true;
	}
	else return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif
     
	while (cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5)
	{
		Branco.clear(); Branco.reserve(9);
		Branco.push_back(Codifica(w1));
		Branco.push_back(Codifica(w2));
		Branco.push_back(Codifica(w3));
		Branco.push_back(Codifica(w4));
		Branco.push_back(Codifica(w5));
		Preto.clear(); Preto.reserve(9);
		Preto.push_back(Codifica(b1));
		Preto.push_back(Codifica(b2));
		Preto.push_back(Codifica(b3));
		Preto.push_back(Codifica(b4));
		Preto.push_back(Codifica(b5));
		
		sort(Branco.begin(), Branco.end());
		sort(Preto.begin(), Preto.end());
		
		Jogo_Branco = Jogo(Branco);
		Jogo_Preto =  Jogo(Preto);
		
		if (Jogo_Branco < Jogo_Preto)  cout << "Black wins.\n";
		else if (Jogo_Branco > Jogo_Preto) cout << "White wins.\n";
		else  // empatou vê o critério de desempate!
		{
			int desempatado;
			switch (Jogo_Branco)
			{
				case STRAIGHT_FLUSH: if (not Desempate(Branco[4][0], Preto[4][0]) ) cout << "Tie.\n"; break;
				case STRAIGHT: if (not Desempate(Branco[4][0], Preto[4][0]) ) cout << "Tie.\n"; break;
				case FOUR_OF_A_KIND: if (not Desempate(Branco[5][0], Preto[5][0]) ) cout << "Tie.\n"; break;
				case FULL_HOUSE: if (not Desempate(Branco[5][0], Preto[5][0]) ) cout << "Tie.\n"; break;
				case THREE_OF_A_KIND: if (not Desempate(Branco[5][0], Preto[5][0]) ) cout << "Tie.\n"; break;
				case TWO_PAIR: if (not Desempate(Branco[5][0], Preto[5][0]) ) 
							if (not Desempate(Branco[6][0], Preto[6][0]) ) 
								if (not Desempate(Branco[7][0], Preto[7][0]) ) cout << "Tie.\n";
						break;
				case PAIR: if (not Desempate(Branco[5][0], Preto[5][0]) )
						if (not Desempate(Branco[6][0], Preto[6][0]) )
							if (not Desempate(Branco[7][0], Preto[7][0]) )
								if (not Desempate(Branco[8][0], Preto[8][0]) ) cout << "Tie.\n";
						break;
				case FLUSH: int j; desempatado = 0;
					    for (j = 4; j > -1 && not desempatado; j--) desempatado = Desempate(Branco[j][0], Preto[j][0]);
					    if (not desempatado) cout << "Tie.\n" ;
					    break;
				case NADA: int k; desempatado = 0;
					   for (k = 4; k > -1 && not desempatado; k--) desempatado = Desempate(Branco[k][0], Preto[k][0]);
					   if (not desempatado) cout << "Tie.\n";
					   break;
			}
		}
	}
	return 0;
}
