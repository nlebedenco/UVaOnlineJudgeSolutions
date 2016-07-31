#include <iostream>
#include <cstdio>

using namespace std;

int a, b;


// T(n, q, p) = n + q div p + T( [n + q/p + q mod p] div p, [n + q/p + q mod p] % p, p)
// onde n é o número de cigarros que se vai fumar, q as guimbas disponíveis, e p as guimbas
// necessárias pra se fazer um cigarro
// assim T(n, q, p) = no. de cigarros + quantos cigarros se pode fazer com as guimbas disponíveis +
// a recorrência com [n + q/p + q mod p]/p = cigarros que se pode fabricar (somando todas as guimbas e
// dividindo por p) e [n + q/p + q mod p] % q = guimbas que sobram (o resto de todas as guimbas divididas 
// pelo número de guimbas necessárias pra se fazer um cigarro
// No board vi que há uma fórmula pra esse problema então essa recorrência deve poder ser
// simplificada, a fórmula é T(n, p) = n + ((n-1) / (p-1)) 

int T(int n, int q, int p)
{
	if (n <= 0 && q < p) return 0;
	else if (n <= 0  && q >= p) return q / p;
	else return n + q/p + T( (n+q/p+q%p)/p, (n+q/p+q%p)%p, p);
}
	
int main()
{
	while (cin >> a >> b) 
	{	
			printf("%d\n", T(a, 0, b));
	}
	return 0;
}

