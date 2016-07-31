#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

string S;
int n;

void Perm(string T ,int k)
{
        if (k < n)
        {
                for (int i = 0; i <= T.size(); i++)
                {
                        string V = T;
                        V.insert(i, S.substr(k, 1));
                        Perm(V, k+1);
                }
        }
        else
        {
                cout << T << "\n";
        }
}

int main()
{
        int caso = 0;
        while (cin >> S)
        {
                if (caso++) printf("\n");
                n = S.size();
                Perm(S.substr(0, 1), 1);
                //cout << "\n";
        }       
        return 0;       
}
