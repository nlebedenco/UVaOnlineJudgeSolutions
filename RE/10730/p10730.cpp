#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int V[10000], n;
int Index[10000];

int main()
{
        while (cin >> n, n)     
        {
                memset(Index, -1, sizeof(Index));
                cin.ignore(1);  
                for (int i = 0; i < n; i++)
                { 
                        cin >> V[i];
                        Index[V[i]] = i;
                }
                
                bool Achou = false;
                for (int i = 0; i < n-2 && not Achou; i++)
			for (int j = i+1; j < n-1 && not Achou; j++)
			{
				int t = V[j]+V[j]-V[i];
				if (t >= 0) Achou = Index[t] != -1 && Index[t] > j;
			}
                if (Achou) printf("no\n");
                else printf("yes\n");
        }
        return 0;
}
