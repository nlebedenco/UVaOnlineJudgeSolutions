#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, z;

int T(int n)
{
        int menor;
        if (n ==1 ) return 6;
        else if (n == 2) return 10;
        else
        {
                menor = 2000000000;
                for (int i = 1; i*i <= n; i++)
                        for (int j = 1; j*j <= n; j++)
                                if (n%(i*j) == 0)
                                { 
                                        int k = n/(i*j);
                                        if (2*(i*j+i*k+j*k) < menor) menor = 2*(i*j+i*k+j*k);
                                }
        }
        return menor;
}

int main()
{
        cin >> z;
        while (z--)
        {
                cin >> n;
                printf("%d\n", T(n));
        }
}