#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

vector <long long> V(80000);

bool Primo(int k)
{
	bool Resultado = true;
	if (k == 2) return true;
	else if (k % 2 == 0) return false;
	else
	{
		int i = 3;
		while (Resultado && i*i <= k)
		{
			if (k % i == 0) Resultado = false;
			i += 2;
		}
	}
	return Resultado;
}

void Gera(int Teto = 1000000)
{
	int i = 2;
	while (i < Teto)
	{
		if ( Primo(i) ) // computa primos
		{
			long long k = (long long) i * i;	// se i é primo computa Almost primes
			while (k < 1000000000000ULL)
			{
				V.push_back(k);	
				k *= i;
			}
		}
		if (i == 2) i++;
		else i += 2;
	}
}



int main()
{
	Gera();
	sort(V.begin(), V.end());

	int n;
        long long a, b;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		//int Total = 0;
		
		int dist = distance(lower_bound(V.begin(), V.end(), a) , lower_bound(V.begin(), V.end(), b) );
				
		cout << dist << "\n";
	}
	
	return 0;
}

