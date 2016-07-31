#ifdef ONLINE_JUDGE
	#define show(A)
	#define NDEBUG
#else
	#define show(A)  cout << #A " = " << (A) << "\n"
#endif
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

char* const INPUT_FILE = "input";
using namespace std;

string a, b;
string resultado;

int main()
{
	#ifndef ONLINE_JUDGE
		ifstream cin(INPUT_FILE); assert(cin);
	#endif
	// string may have blank spaces so must use getline!
	while (getline(cin, a), getline(cin, b))
	{
		resultado = ""; //strangelly using resultado.clear(); give a Compile Error!
		sort( a.begin(), a.end() );
		sort( b.begin(), b.end() );
		
		insert_iterator<string> res_ins(resultado, resultado.begin());
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), res_ins);
		sort(resultado.begin(), resultado.end());
		cout << resultado << "\n";
	}
	
	return 0;
}
