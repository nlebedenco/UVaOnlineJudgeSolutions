#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

unsigned long long a;
int caso = 0;

const long KUTI = 10000000;
const long LAKH = 100000;
const long HAJAR = 1000;
const long SHATA = 100;

void Converte(unsigned long long n)
{
	if (n / KUTI > 0) 
	{
		Converte(n / KUTI);
		printf(" kuti");
		n %= KUTI;
	}
	if (n / LAKH > 0) 
	{
		Converte(n / LAKH);
		printf(" lakh");
		n %= LAKH;
	} 
	if (n / HAJAR > 0) 
	{
		Converte(n / HAJAR);
		printf(" hajar");
		n %= HAJAR;
	}
	if (n / SHATA > 0) 
	{
		Converte(n / SHATA);
		printf(" shata");
		n %= SHATA;
	}	
	if ( n > 0) printf (" %d", n);
}

int main()
{
	while (cin >> a)
	{
		printf("%4d.", ++caso);
		if (a > 0) Converte(a);
		else printf(" 0");
		printf("\n");
	}
	return 0;
}
