#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n, cont;

struct node
{
        int k;
        vector <node*> filhos;
        node* pai;

        node (int a = 0, node* b = NULL):k(a), pai(b) {};
};

node V[10001];


void Visita(node& X)
{
        for (int i = 0; i < X.filhos.size(); i++) Visita(*(X.filhos[i]));
        
        if (X.k <= 0)
        {
                cont += X.k*(-1) + 1;
                X.pai->k -= X.k*(-1) + 1;
        }
        else if (X.k > 1)
        {
                cont += X.k - 1;
                X.pai->k += X.k - 1;
        }
}


int main()
{
        while (cin >> n, n)
        {
                int z = n;
                while (z--)
                {
                        int a, b, f, c;
                        cin >> a >> b >> f;
                        V[a].k = b; V[a].filhos.clear();
                        for (int i = 0; i < f; i++)
                        {
                                cin >> c; V[c].pai = V+a;
                                V[a].filhos.push_back(V+c);
                        }
                }
                cont = 0;
                for (int i = 1; i <= n; i++) 
                        if (V[i].pai == NULL) 
                        {
                                for (int j = 0; j < V[i].filhos.size(); j++) Visita(*(V[i].filhos[j]));
                                break;
                        }
                printf("%d\n", cont);
        }
                
}