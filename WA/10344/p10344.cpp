#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int V[5];
bool encontrou;

void Testa(int a, int i)
{
        if (i > 1)
        {
                if (not encontrou) Testa(a-V[i], i-1);
                if (not encontrou) Testa(a+V[i], i-1);
                if (not encontrou && a % V[i] == 0) Testa(a / V[i] ,i-1);
        }
        else encontrou = (V[i] + V[i-1] == a || V[i] - V[i-1] == a || V[i] * V[i-1] == a);
}

int main()
{
        while (cin >> V[0] >> V[1] >> V[2] >> V[3] >> V[4], V[0] || V[1] || V[2] || V[3] || V[4])
        {
                sort(V, V+5);
                encontrou = false;
                while (not encontrou && next_permutation(V, V+5))
                        Testa(23, 4);
                
                if (encontrou) printf("Possible\n");
                else printf("Impossible\n");
        }       
}