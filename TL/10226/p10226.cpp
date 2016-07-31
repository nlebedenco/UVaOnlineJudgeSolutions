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
     
	typedef vector <pair <string, int> > TArvore;
	
	int TestCases;     
	TArvore v;
	string Nome;
	
	while (cin >> TestCases)
	{	cin.get(); cin.get();
		for (int i = 1; i <= TestCases; i++)
		{
			getline(cin, Nome);
			do
			{
				cout << Nome;
				getline(cin, Nome);
				
			} while (Nome != "" && !cin.eof());
			cout << "--- FINAL ---" << endl;
		}
	}
	return 0;
}
