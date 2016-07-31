#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int V[1001];

int Sort()
{
        int res = 0;
        bool correto = false;
        while (not correto)
        {
                correto = true;
                for (int i = 1; i < n; i++)
                {
                        if (V[i-1] > V[i])
                        {
                                correto = false;
                                res++;
                                swap(V[i-1], V[i]);
                        }
                }
        }       
        return res;
}

int main()
{
        while(cin >> n)
        {
                memset(V, 0, sizeof(V));
                for (int i = 0; i < n; i++) cin >> V[i];

                printf("Minimum exchange operations : %d\n", Sort());

        }
}