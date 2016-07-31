#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

unsigned long long a;
int main()
{
        while (cin >> a, a)
        {
				bool first = true;
                unsigned long long m, n = (10 * a)/9;
                if (n < 10) m = 0;
                else m = n-10;
                for (unsigned long long i = m; i <= (n + 10); i++)
				{
                        if ((i - i/10) == a) 
						{
							if (not first) printf(" ");
							first = false;
							printf("%llu", i);
						}
				}
                printf("\n");
        }
}
