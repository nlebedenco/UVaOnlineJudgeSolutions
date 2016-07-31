#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

int guess;
string response;

bool V[11];

int main()
{
	memset(V, 0, sizeof(V));
	while (cin >> guess, guess != 0)
	{
		cin >> response; cin >> response;
		
		if (response == "high") 
			for (int i = guess; i <= 10; i++) V[i] = true;
		else if (response == "low")
			for (int i = guess; i > -1; i--) V[i] = true;
		else
		{
			if (guess > 10) cout << "Stan is dishonest\n";
			else if (V[guess]) cout << "Stan is dishonest\n";
			else cout << "Stan may be honest\n";
			memset(V, 0, sizeof(V));
		}
	}
	return 0;
}
