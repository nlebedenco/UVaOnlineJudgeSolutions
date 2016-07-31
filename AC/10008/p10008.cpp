#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int z;
string s;
int C[256];
struct node
{
	char c;
	int x;
	node() { node(0,0); }
	node (char a, int b):c(a), x(b) {}
};
vector <node> V;

bool compara(const node& a, const node& b)
{
	if (a.x == b.x) return a.c < b.c;
	else return (a.x > b.x); 
}

int main()
{
	cin >> z; cin.get();
	memset(C, 0, sizeof(C));
	V.clear();
	while (z--)
	{
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
				C[ s[i] ]++;
	}
	
	for (char c = 'A'; c <= 'Z'; c++) 
	{
		int k = C[c] + C[c + 32];
		if (k > 0) V.push_back(node(c, k));
	}
	sort(V.begin(), V.end(), compara);
	for (int i = 0; i < V.size(); i++) printf("%c %d\n", V[i].c, V[i].x);
	
	return 0;
}

