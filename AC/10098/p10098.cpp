#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
string S;

bool compara(const char& a, const char& b)
{
	if ( toupper(a) == toupper(b) ) return int(a) < int(b);
	else return toupper(a) < toupper(b);
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> S;
		sort(S.begin(), S.end(), compara);
		cout << S << "\n";
		while (next_permutation(S.begin(), S.end(), compara) ) cout << S << "\n";
		cout << "\n";
	}
}
