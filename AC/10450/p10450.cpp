#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long V[52];

long long Fib(int p)
{
	if (V[p] == -1) V[p] = Fib(p-1) + Fib(p-2);	
	return V[p];
}

int n, k;
int main()
{
	memset(V, -1, sizeof(V));
	V[0] = 1;
	V[1] = 2;
	Fib(51);
	//for (int i = 0; i < 52; i++) cout << V[i] << "\n";
	cin >> n;
	for (int caso = 1; caso <= n; caso++)
	{
		printf("Scenario #%d:\n", caso);
		cin >> k;
		cout << Fib(k) << "\n\n";
	}
	return 0;
}
