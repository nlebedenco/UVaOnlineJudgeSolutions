#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

unsigned long long z, p;

unsigned long long Reverse(unsigned long long a)
{
	stringstream ws;
	string s; 
	ws << a;
	ws >> s;
	reverse(s.begin(), s.end());
	return strtoul(s.c_str(), NULL, 10);
}

int main()
{

	cin >> z;
	while (z--)
	{
		cin >> p;
		int i = 0;

		while (not (p == Reverse(p)))
		{
			p += Reverse(p);
			i++;
		}
		cout << i << " " << p << "\n";
	}
	return 0;
}
