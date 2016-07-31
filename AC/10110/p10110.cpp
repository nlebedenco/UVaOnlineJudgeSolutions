#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double a, n;
int b;

int main()
{

	while (cin >> n, n > 0)
	{
		// se a raiz é exata, o número de divisores é ímpar!!
		a = sqrt(n);
		b = int(sqrt(n));
		
		printf("%s\n", a==b?"yes":"no");
		
		
	}	
	return 0;
}

