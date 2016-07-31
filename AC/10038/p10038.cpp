#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

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
	
int main()
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
	
	int a,b,count,posicao;
	bool jolly;
	vector<bool> v(3000);
	
	while(cin >> count)
	{
		fill(v.begin(), v.end(), false);
		jolly = true;	  
		cin >> a;
		for(int i = 2; i <= count; i++)
		{
			cin >> b;
			posicao = abs(a - b);
			v[posicao] = true;    
			a = b;
		}    
		vector<bool>::iterator Fim = v.begin()+count;
		jolly = (find(v.begin()+1, Fim, false) == Fim);
		
		if (jolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	
	return 0;
}
