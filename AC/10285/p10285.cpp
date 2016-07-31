#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int V[100][100], T[100][100];

int z, R, C;
string local;

void Ajusta(int a ,int b, int k)
{
        if (T[a][b] < k)
        {
                T[a][b] = k;
                if (a-1 > -1)
                {
                        if (V[a-1][b] > V[a][b])
                                Ajusta(a-1, b, k+1);    
                }
                if (a+1 < R)
                {
                        if (V[a+1][b] > V[a][b])
                                Ajusta(a+1, b, k+1);    
                }
                if (b-1 > -1)
                {
                        if (V[a][b-1] > V[a][b])
                                Ajusta(a, b-1, k+1);    
                }
                if (b+1 < C)    
                {
                        if (V[a][b+1] > V[a][b])
                                Ajusta(a, b+1, k+1);            
                }
        }
}

int main()
{
        cin >> z;
        while (z--)
        {
                cin >> local >> R >> C;
                for (int i = 0; i < R; i++)
                        for (int j = 0; j < C; j++)
                        {
                                cin >> V[i][j];
                                T[i][j] = 0;
                        }
                
                for (int i = 0; i < R; i++)
                        for (int j = 0; j < C; j++)
                                if (T[i][j] == 0)
                                        Ajusta(i, j, 1);                
                int maior = 0;
                for (int i = 0; i < R; i++)
                        for (int j = 0; j < C; j++)
                                maior = max(T[i][j], maior);            
                printf("%s: %d\n", local.c_str(), maior);       
        }
}