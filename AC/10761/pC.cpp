#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int BROKEN = -1;

int letras[26];
int temp[26];

string linha;
int TotalLinhas, Problemas;

int main()
{
	int Caso = 0;
	cout << "+----------+----------------+-----------------------------+\n";
	cout << "| Keyboard | # of printable | Additionally, the following |\n";
	cout << "|          |      lines     |  letter keys can be broken  |\n";
	cout << "+----------+----------------+-----------------------------+\n";
	
	while (cin >> linha, linha != "finish")
	{
		Caso++;

		memset(letras, 0, sizeof(letras));
		for (int i = 0; i < linha.size(); i++)
			letras[tolower(linha[i]) - 'a'] = BROKEN;
				
		TotalLinhas = 0, Problemas = 0; 
		
		while (not isalpha(cin.peek())) cin.ignore();
		
		do
		{
			getline(cin, linha); TotalLinhas++;
			memset(temp, 0, sizeof(temp));
			bool correto = true;
			for (int i = 0; i < linha.size() && correto; i++)
			{
				if (isalpha(linha[i]))
				{
					correto = (letras[tolower(linha[i]) - 'a'] != BROKEN);
					temp[tolower(linha[i]) - 'a'] = 1;
				}
			}
			if (correto) 
			{
				for (int i = 0; i < 26; i++) if (temp[i] == 1) letras[i] = 1;
			}
			else Problemas++;
		}
		while (linha != "END");
		
		string Possiveis("");
		for (int i = 0; i < 26; i++)
			if (letras[i] == 0) Possiveis += char('a' + i);
				
		printf("|   %3d    |      %3d       | %-28s|\n", Caso, TotalLinhas-Problemas, Possiveis.c_str());
		cout << "+----------+----------------+-----------------------------+\n";
	}	
	return 0;
};
 
