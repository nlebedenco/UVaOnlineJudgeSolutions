#include <iostream>
#include <fstream>
#include <iomanip>

#ifdef VALLADOLID 
	#define ONLINE_JUDGE
#endif

#ifdef ONLINE_JUDGE 
	#define NDEBUG
#endif

#include <assert.h>

#ifndef ONLINE_JUDGE
	#define TEST_INPUT_FILE "input"
	#ifdef DEBUG_OUTPUT
		#define TEST_OUTPUT_FILE "model.out"
	#endif
#endif

using namespace std;

long MaiorCiclo(long a, long b)
{
	long n, Contador, Resultado = 0;
	for (long i = a; i <= b; i++)
	{
		n = i; Contador = 1;
		while (n != 1)
		{
			Contador++;
			if (n % 2 == 0) n = n/2;
			else n = 3*n + 1;
		
		} 
		Resultado = (Resultado > Contador)? Resultado: Contador;
	}
	return Resultado;
}
	
int main()
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
     
	long x, y, z;
	while (cin >> x >> y)
	{
		if (x == 0 && y == 0) return 0; // se encontrou a linha 0 0 sai!
		
		cout << x << " " << y << " " << ((x < y)? MaiorCiclo(x, y): MaiorCiclo(y, x)) << "\n";
	}
    
	return 0;
}
