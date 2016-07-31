#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct ponto
{
        int x, y;
};

ponto V[1000];
bool R[1000];
int n;

bool Menor(int k, int a, int b)
{
        int da = (V[k].x - V[a].x)*(V[k].x - V[a].x) + (V[k].y - V[a].y)*(V[k].y - V[a].y);
        int db = (V[k].x - V[b].x)*(V[k].x - V[b].x) + (V[k].y - V[b].y)*(V[k].y - V[b].y);
        if (da == db)
        {
                if (V[a].x == V[b].x) return (V[a].y < V[b].y);
                else return V[a].x < V[b].x;
        }
        else return (da < db);
}

void DoisMaisPerto(int k, int& a, int& b)
{
        for (int i = 0; i < n; i++)
                if (k != i)
                {
                        if (a == -1) a = i;
                        else if (Menor(k, i, a))
                        {
                                b = a;
                                a = i;
                        }
                        else
                        {
                                if (b == -1) b = i;
                                else if (Menor(k, i, b)) b = i;
                        }
                }
}

void Verifica(int k)
{
        int a = -1, b = -1;
        if (not R[k])
        {
                R[k] = true;
                DoisMaisPerto(k, a, b);
                Verifica(a);
                Verifica(b);
        }
}

int main()
{
        while (cin >> n, n)
        {
                for (int i = 0; i < n; i++) cin >> V[i].x >> V[i].y;
                
                memset(R, 0, sizeof(R));
                Verifica(0);
                
                bool correto = true;
                for (int i = 0; i < n && correto; i++) correto = R[i];
                if (correto) printf("All stations are reachable.\n");
                else printf("There are stations that are unreachable.\n");
        }
        return 0;
}