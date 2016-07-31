#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
T(0, m) = S(m)
T(n, m) = T(0, n+m)+n;
*/
int T(int n, int m)
{
        int a = m+n;
        return a*(a+1) / 2 + n;
}

int a, b, c, d, z;
int main()
{
        cin >> z;
        for (int caso = 1; caso <= z; caso++)
        {
                cin >> a >> b >> c >> d;
                printf("Case %d: %d\n", caso, T(c, d) - T(a, b));
        }
        return 0;
}