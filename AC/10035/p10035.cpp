#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int res;

int CarrySoma(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int i = 0, carry = 0, carrycount = 0;
	while (i < a.size() && i < b.size())
	{
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		carry = temp / 10;
		if (carry) carrycount++;
		i++;	
	}
	while (i < a.size())
	{
		int temp = (a[i] - '0') + carry;
		carry = temp / 10;
		if (carry) carrycount++;
		i++;
	}
	while (i < b.size())
	{
		int temp = (b[i] - '0') + carry;
		carry = temp / 10;
		if (carry) carrycount++;
		i++;
	}
	return carrycount;
}


int main()
{
	
	while (cin >> a >> b, a != "0" || b != "0")
	{
		res = CarrySoma(a, b);
		
		if (res) cout << res;
		else cout << "No";
		cout << " carry operation";
		if (res > 1) cout << "s.\n";
		else cout << ".\n";
	}
	
	return 0;
}

