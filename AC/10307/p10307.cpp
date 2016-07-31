#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

const char PAREDE = '#';
const char ALIEN = 'A';
const char START = 'S';
const char MARCADOR = '*';

struct node
{
	int passo, x, y;
	node (int a = 0, int b = 0, int c = 0): passo(a), x(b), y(c) {}
};

int z, n, m, w, resposta;
string B[50], C[50];

int V[50][50], T[101][101];

struct _whatever {
	int x, y; 
} P[101];

bool S[101];

void Verifica(int A, int passo, int i, int j)
{
	if (C[i][j] == ALIEN || C[i][j] == START)
	{
		int B = V[i][j];
		T[A][B] = passo;
	}
}

void BFS(int k)
{
	queue<node> Q;
	
	Q.push(node(0, P[k].x, P[k].y));
	C[P[k].x][P[k].y] = MARCADOR;
	int encontrados = 1;
	T[k][k] = 0;
	while (not Q.empty() && encontrados < w)
	{
		node p = Q.front(); Q.pop();
		
		if (p.x-1 > -1 && C[p.x-1][p.y] != MARCADOR && C[p.x-1][p.y] != PAREDE)
		{
			Verifica(k, p.passo+1, p.x-1, p.y);
			C[p.x-1][p.y] = MARCADOR;
			Q.push(node(p.passo+1, p.x-1, p.y));
		}
		if (p.x+1 < m && C[p.x+1][p.y] != MARCADOR && C[p.x+1][p.y] != PAREDE)
		{
			Verifica(k, p.passo+1, p.x+1, p.y);
			C[p.x+1][p.y] = MARCADOR;
			Q.push(node(p.passo+1, p.x+1, p.y));
		}
		if (p.y-1 > -1 && C[p.x][p.y-1] != MARCADOR && C[p.x][p.y-1] != PAREDE)
		{
			Verifica(k, p.passo+1, p.x, p.y-1);
			C[p.x][p.y-1] = MARCADOR;
			Q.push(node(p.passo+1, p.x, p.y-1));
		}
		if (p.y+1 < n && C[p.x][p.y+1] != MARCADOR && C[p.x][p.y+1] != PAREDE)
		{
			Verifica(k, p.passo+1, p.x, p.y+1);
			C[p.x][p.y+1] = MARCADOR;
			Q.push(node(p.passo+1, p.x, p.y+1));
		}
	}
}

void Boruvka(int k)
{
	if (k < w)
	{
		int a = -1, b = -1;
		for (int i = 0; i < w; i++)
			if (S[i])
			{
				for (int j = 0; j < w; j++)
					if (not S[j])
						if ( (a == -1 && b == -1) || T[i][j] < T[a][b])
						{
							a = i;
							b = j;
						}
			}
		if (a > -1 && b > -1) 
		{
			resposta += T[a][b];
			S[b] = true;
		}
		Boruvka(k+1);
	}
	
}

int main()
{

	cin >> z;
	while (z--)
	{
		cin >> n >> m; cin.ignore();
		w = 0;
		memset(V, 0, sizeof(V));
		memset(T, 0, sizeof(T));

		for (int i = 0; i < m; i++) 
		{
			getline(cin, B[i]);	
			for (int j = 0; j < n; j++)
				if (B[i][j] == ALIEN || B[i][j] == START) 
				{
					P[w].x = i;
					P[w].y = j;
					V[i][j] = w++;
				}
		}
		
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < m; j++) C[j] = B[j];
			BFS(i);
		}
		
		/*
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < w; j++)
			       printf("%2d", T[i][j]);	
			printf("\n");
		}
		*/
		
		resposta = 0;
		memset(S, 0, w*sizeof(S[0]));
		S[0] = true;
		Boruvka(0);
		printf("%d\n", resposta);
	}
}

