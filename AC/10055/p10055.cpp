#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long a, b;
int main()
{
    while (cin >> a >> b)
    {
        if (a < b) swap(a, b);
        printf("%lld\n", a-b);
    }   
}