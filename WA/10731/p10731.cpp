#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool T[26][26];
char a, b, c, d, e, x, S[27];
int V[26], marca, grupo, visitado[26], n, z;

void Visita(int k)
{
        visitado[k] = true;
        for (int i = 0; i < 26; i++)
                if (T[k][i] && not visitado[i]) Visita(i);
        V[marca--] = k;
}

void VisitaInversa(int k)
{
        visitado[k] = grupo;
        for (int i = 0; i < 26; i++)
                if (T[i][k] && not visitado[i])
                        VisitaInversa(i);
}

void ImprimeLinha(int g)
{
        for (int i = 0; i < 26; i++)
                if (visitado[i] == g) printf("%c ", i + 'A');
        printf("\n");
}


void Imprime()
{
        for (int i = 0; i < 26; i++)
                if (not S[visitado[i]] && visitado[i])
                {
                        S[visitado[i]] = true;
                        ImprimeLinha(visitado[i]);      
                        Imprime();
                        
                }
}



int main()
{
        while (cin >> n, n)
        {
                memset(T, 0 ,sizeof(T));
                memset(S, 0, sizeof(S));
                z = 0;
                while (n--)
                {
                        cin >> a >> b >> c >> d >> e >> x;
                        a -= 'A'; b -= 'A'; c -= 'A'; d -= 'A'; e -= 'A'; x -= 'A';
                        if (not S[a]) z++;
                        if (not S[b]) z++;
                        if (not S[c]) z++;
                        if (not S[d]) z++;
                        if (not S[e]) z++;
                        S[a] = S[b] = S[c] = S[d] = S[e] = true;
                        T[x][a] = T[x][b] = T[x][c] = T[x][d] = T[x][e] = true;
                }
                
                for (int i = 0; i < 26; i++) T[i][i] = false;
                memset(V, 0, sizeof(V));
                marca = z-1;

                memset(visitado, 0, sizeof(visitado));
                
                for (int i = 0; i < 26; i++)
                        if (S[i] && not visitado[i]) Visita(i);

                memset(visitado, 0, sizeof(visitado));
                grupo = 0;
                for (int i = 0; i < z; i++)
                        if (not visitado[V[i]] )
                        {
                                grupo++;
                                VisitaInversa(V[i]);
                        }

                memset(S, 0, sizeof(S));
                Imprime();
                
        }       
        printf("\n");
}