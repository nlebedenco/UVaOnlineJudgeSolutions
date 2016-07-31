#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char T[76][2];
bool V[5][5];

int z, ball; 

bool Verifica(int a, int b)
{
	bool correto;

	correto = true;
	for (int i = a, j = 0; j < 5 && correto; j++) correto = V[i][j];
	if (correto) return true;

	correto = true;
	for (int i = 0, j = b; i < 5 && correto; i++) correto = V[i][j];
	if (correto) return true;
		
	correto = true;
	for (int i = 0, j = 0; j < 5 && i < 5 && correto; i++, j++) correto = V[i][j];
	if (correto) return true;


	correto = true;
	for (int i = 0, j = 4; j > -1 && i < 5 && correto; i++, j--) correto = V[i][j];
	if (correto) return true;

	return false;
}

int main()
{
	cin >> z; while (cin.get() != '\n');
	while (z--)
	{
		memset(T, -1, sizeof(T));
		memset(V, 0, sizeof(V));

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (i != 2 || j != 2)
				{
					int a;
					cin >> a;
					T[a][0] = i;
					T[a][1] = j;
				}
		
		V[2][2] = true;
		bool ganhou =  false; int rodadas = 0;
		for (int i = 0; i < 75; i++)
		{	
			cin >> ball;
			if (not ganhou)
			{
				int a = T[ball][0], b = T[ball][1];
				if (a != -1 && b != -1)
				{
					V[a][b] = true;
					if (Verifica(a, b))
					{
						ganhou = true;
						rodadas = i+1;
					}
				}
			}
		}
		
		printf("BINGO after %d numbers announced\n", rodadas);
	}	
	
}

