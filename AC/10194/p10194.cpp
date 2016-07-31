#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct team
{
	string nome;
	int gols_feitos, gols_levados, jogos, vitorias, empates, derrotas;
	team(string a): nome(a), gols_feitos(0), gols_levados(0), jogos(0), vitorias(0), empates(0), derrotas(0) {}
};

vector <team> V;
string Torneio;
int n, t, g;

map <string, int> M;

bool compara(const team& a, const team& b)
{
	if ((3*a.vitorias + a.empates) > (3*b.vitorias + b.empates) ) return true;
	else if ((3*a.vitorias + a.empates) < (3*b.vitorias + b.empates) ) return false;
	
	if (a.vitorias > b.vitorias) return true;
	else if (a.vitorias < b.vitorias) return false;
	
	if (a.gols_feitos-a.gols_levados > b.gols_feitos-b.gols_levados) return true;
	else if (a.gols_feitos-a.gols_levados < b.gols_feitos-b.gols_levados) return false;
	
	if (a.gols_feitos > b.gols_feitos) return true;
	else if (a.gols_feitos < b.gols_feitos) return false;
	
	if (a.jogos < b.jogos) return true;
	else if (a.jogos > b.jogos) return false;

	string x, y;
        x = a.nome;
	y = b.nome;
	for (int i = 0; i < x.size(); i++) x[i] = toupper(x[i]);
	for (int i = 0; i < y.size(); i++) y[i] = toupper(y[i]);
	return x < y;
}

int main()
{
	cin >> n; cin.get();
	while (n--)
	{
		M.clear();
		V.clear();
		getline(cin, Torneio);
		cin >> t; cin.get();
		while (t--)
		{
			string s;
			getline(cin, s);
			V.push_back(team(s));
			M.insert(make_pair(s, V.size()-1 ));
		}
		
		cin >> g; cin.get();
		while (g--)
		{
			string s1, s2, s3, s4;
			int g1, g2;

			getline(cin, s1, '#');
			getline(cin, s2, '@');
			getline(cin, s3, '#');
			getline(cin, s4, '\n');
			
			g1 = atoi(s2.c_str());
			g2 = atoi(s3.c_str());

			// Time 1
			team& T1 = V[ M[s1] ];
			T1.gols_feitos += g1;
			T1.gols_levados += g2;
			T1.jogos++;
			if (g1 > g2) T1.vitorias++;
			if (g1 < g2) T1.derrotas++;
			if (g1 == g2) T1.empates++;
			
			// Time 1
			team& T2 = V[ M[s4] ];
			T2.gols_feitos += g2;
			T2.gols_levados += g1;
			T2.jogos++;
			if (g1 > g2) T2.derrotas++;
			if (g1 < g2) T2.vitorias++;
			if (g1 == g2) T2.empates++;
		}
		sort(V.begin(), V.end(), compara);
		printf("%s\n", Torneio.c_str());
		for (int i = 0; i < V.size(); i++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
					i+1, V[i].nome.c_str(), 3*V[i].vitorias + V[i].empates, V[i].jogos, 
					V[i].vitorias, V[i].empates, V[i].derrotas, V[i].gols_feitos-V[i].gols_levados, 
					V[i].gols_feitos, V[i].gols_levados);
		}
		if (n>0) printf("\n");
	}	
	return 0;
}	
