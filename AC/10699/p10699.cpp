#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

int a;

int Fatores(const int k)
{
	int n = k;
	int Topo = 0, D = 2, ultimoPrimo = 0;
	while (n > 1)
	{
		while (n % D > 0) D++;
		while (n % D == 0 && n > 1)
		{
			if (ultimoPrimo != D)
			{
				Topo++;
				ultimoPrimo = D;
			}
			n /= D;
		}
	}
	return Topo;
}

int main()
{
	while (cin >> a, a != 0)
		cout << a << " : " << Fatores(a) << "\n";

	return 0;
}
