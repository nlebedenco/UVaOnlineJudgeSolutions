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
		// se a raiz � exata, o n�mero de divisores � �mpar!!
		a = sqrt(n);
		b = int(sqrt(n));
		
		printf("%s\n", a==b?"yes":"no");
		
		
	}	
	return 0;
}

