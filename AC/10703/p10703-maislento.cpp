#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int W, H, N, a, b, c, d;

struct rect
{
	int x1, y1, x2, y2;
	rect(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {}
	rect() { rect(0, 0, 0, 0); }
};

vector <rect> V;

int Area(int a, int b, int c, int d)
{
	return (abs(a-c)+1) * (abs(b-d)+1);
}

bool PontoInterno(int a, int b, const rect& r)
{
	return (a >= min(r.x1, r.x2) && a <= max(r.x1, r.x2) && b >= min(r.y1, r.y2) && b <= max(r.y1, r.y2) );
}

int main()
{
	while (cin >> W >> H >> N, W || H || N)
	{
		V.clear(); V.reserve(N);
		int max_x = 0, max_y = 0, min_x = 1000, min_y = 1000;
		while (N--)
		{
			cin >> a >> b >> c >> d;
			max_x = max(max_x, max(a, c));
			max_y = max(max_y, max(b, d));
			min_x = min(min_x, min(a, c));
			min_y = min(min_y, min(b, d));
			
			V.push_back(rect(a, b, c, d));
		}
		int AreaParcial = Area(max_x, max_y, min_x, min_y);
		int AreaTotal = W * H - AreaParcial;
		for (int i = min_x; i <= max_x; i++)
			for (int j = min_y; j <= max_y; j++)
				for (int k = 0; k < V.size(); k++)
					if ( PontoInterno(i, j, V[k]))
					{
						AreaParcial--;
						break;
					}

		AreaTotal += AreaParcial;
		if (AreaTotal == 0) printf("There is no empty spots.\n");
		else if (AreaTotal == 1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n", AreaTotal);	
			
	}
	return 0;	
}
