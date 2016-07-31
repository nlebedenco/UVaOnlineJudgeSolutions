#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

vector<string> A, B;

int z, n, m, d;

char Vencedor(int a, int b)
{
        char candidato; 
        switch(A[a][b])
        {
                case 'R': candidato = 'P'; break;
                case 'S': candidato = 'R'; break;
                case 'P': candidato = 'S'; break;
        }
        bool encontrou = false;
        if (not encontrou && a-1 > -1) encontrou = (A[a-1][b] == candidato);
        if (not encontrou && a+1 < m) encontrou = (A[a+1][b] == candidato);
        if (not encontrou && b-1 > -1) encontrou = (A[a][b-1] == candidato);
        if (not encontrou && b+1 < n) encontrou = (A[a][b+1] == candidato);

        if (encontrou) return candidato;
        else return A[a][b];
}

int main()
{
        cin >> z;
        while (z--)
        {
                cin >> m >> n >> d;
                A.clear(); B.clear();
                A.resize(m); B.resize(m);

                for (int i = 0; i < m; i++) cin >> B[i];

                while (d--)
                {
                        A = B;
                        for (int i = 0; i < m; i++)
                                for (int j = 0; j < n; j++)
                                        B[i][j] = Vencedor(i, j);
                }
                for (int i = 0; i < m; i++)
                        cout << B[i] << "\n";
                if (z > 0) cout << "\n";
        }
        return 0;
}