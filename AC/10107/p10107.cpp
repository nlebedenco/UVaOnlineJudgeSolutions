#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int V[10002], a, n;

void insert (const int k)
{
	n++;
	int i = n;
	while (V[i-1] > k)
	{
		V[i] = V[i-1];
		i--;
	}
	V[i] = k;
}

int main()
{
	memset(V, 0, sizeof(V));
	V[0] = (1 << 31);
	
	n = 0;
	while (cin >> a)
	{
		insert(a);
			
		int m = n / 2;

		if (n % 2 == 0) cout << (V[m] + V[m+1]) / 2 << "\n";
		else cout << V[m+1] << "\n";
	}
	return 0;
}

