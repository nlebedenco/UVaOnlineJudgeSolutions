#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;


int Alturas[10000+1], L, H, R, MaxR;
int main()
{
	
	memset(Alturas, 0, sizeof(Alturas));
	MaxR = 0;
	while (cin >> L >> H >> R)
	{
		for (int i = L; i < R; i++)
			if (Alturas[i] < H) Alturas[i] = H;
		MaxR = max(MaxR, R);
	}
	
	int lastHeight = -1;
	for (int i = 1; i <= MaxR; i++)
	{
		if (Alturas[i] != lastHeight) 
		{
			cout << i << " " << Alturas[i];
			if (i < MaxR) cout << " ";
			lastHeight = Alturas[i];
		}
	}
	cout << "\n";
	return 0;
}
