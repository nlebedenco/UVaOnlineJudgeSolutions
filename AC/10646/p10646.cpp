#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int z;
vector <string> pilha;
vector <string> res;
int Valor(char c)
{
        if (isdigit(c)) return (c - '0');
        else return 10;
}

int main()
{
        cin >> z;
        for (int caso = 1; caso <= z; caso++)
        {
                pilha.clear(); pilha.resize(52);
                res.clear();
                for (int i = 0; i < 52; i++) cin >> pilha[i];
                
                int Y = 0; int topo = 26;
                for (int i = 0; i < 3; i++)
                {
                        Y += Valor(pilha[topo][0]);
                        topo -= 10 - Valor(pilha[topo][0]) + 1;
                }

                for (int i = 0; i <= topo; i++) res.push_back(pilha[i]);
                for (int i = 26; i < 52; i++) res.push_back(pilha[i]);
                printf("Case %d: %s\n", caso, res[Y].c_str());
        }
        return 0;
}