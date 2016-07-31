#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int a;

int main()
{
	while (cin >> a, a != 0)
	{
		if (a <= 100) printf ("f91(%d) = %d\n", a, 91);
		else printf ("f91(%d) = %d\n", a, a-10);
	}	
	return 0;
}
