#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int m,n;
vector<int> V;
int main()
{
	while (cin >> n >> m)
	{
		//if (n == 1 && m == 1) printf("1\n"); // AHHHHHHH! MALDITO PROBLEMA!!! pq diabos 1 1 é Boring??????
		if (n == 0 || m == 0 || m == 1 || n == 1) printf("Boring!\n");
		else 
		{
			V.clear();
			V.push_back(n);
			bool correto = true;
			while (n > 1 && correto)
			{
				if (n % m) correto = false;
				n /= m;
				V.push_back(n);
			}	
			if (not correto) printf("Boring!");
			else for (int i = 0; i < V.size(); i++)
			{
				printf("%d", V[i]);
				if (i < V.size()-1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}

