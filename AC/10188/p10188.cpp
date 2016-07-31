#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int m, n, Caso = 0;
string s, r, a, answer;

string Numbers (const string& s)
{
	string res = "";
	for (int i = 0; i < s.size(); i++) if (isdigit(s[i])) res += s[i]; 
	return res;
}

int main()
{ 
	while (getline(cin, a))
	{
		n = atoi(a.c_str());
		if (n == 0) return 0;
		
		s = "";
		while (n--)
		{
			getline(cin, a);
			s += a + "\n";
		}
		getline(cin, a);
		m = atoi(a.c_str());
		r = "";
		while (m--)
		{
			getline(cin, a);
			r += a + "\n";
		}
		
		if (s == r) answer = "Accepted";
		else if (Numbers(s) == Numbers(r)) answer = "Presentation Error";
		else answer = "Wrong Answer";
		printf("Run #%d: %s\n", ++Caso, answer.c_str());
	}
	return 0;
}

