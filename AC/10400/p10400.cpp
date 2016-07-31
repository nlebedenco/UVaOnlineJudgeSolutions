#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int V[100];
bool T[100][64001];

int n, p, objetivo;
bool correto;
string resposta;

bool NoRange(int k)
{
        return k >= -32000 && k <= 32000;
}

void Calcula(int k, string r, int obj)
{
        if (k > 1)
        {
                if (not T[k][obj+32000])
                {
                        T[k][obj+32000] = true;
                        if (not correto && NoRange(obj+V[k])) Calcula(k-1, '-' + r, obj+V[k]);
                        if (not correto && NoRange(obj-V[k])) Calcula(k-1, '+' + r, obj-V[k]);
                        if (not correto && obj%V[k] == 0) Calcula(k-1, '*' + r, obj/V[k]);
                        if (not correto && NoRange(obj*V[k])) Calcula(k-1, '/' + r, obj*V[k]);
                }       
        }
        else
        {
                if (V[0] + V[1] == obj && NoRange(V[0]+V[1]))
                {
                        correto = true;
                        resposta = '+' + r; 
                }
                else if (V[0] - V[1] == obj && NoRange(V[0]*V[1]))
                {
                        correto = true;
                        resposta = '-' + r; 
                }

                else if (V[0] * V[1] == obj && NoRange(V[0]*V[1]) )
                {
                        correto = true;
                        resposta = '*' + r;
                }
                else if (V[0] / V[1] == obj && V[0]%V[1] == 0)
                {
                        correto = true;
                        resposta = '/' + r;
                }                       
        }
}

int main()
{
        cin >> n;
        while (n--)
        {
                cin >> p;
                for (int i = 0; i < p; i++) cin >> V[i];
                cin >> objetivo;
                        
                correto = false; memset(T, 0, p*sizeof(T[0]));
                resposta = "";
                Calcula(p-1, resposta, objetivo);

                if (correto) 
                        for (int i = 0; i < p; i++)
                        {
                                printf("%d", V[i]);
                                if (i < p-1) printf("%c", resposta[i]);
                                else printf("=%d\n", objetivo);
                        }               
                else printf("NO EXPRESSION\n");
        }
}
