#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct ponto
{
	double x, y;
	ponto(double a = 0, double b = 0):x(a), y(b) {}
};

const int MAXN = 1000000;
const int INFINITO = 1000000000;
ponto P[MAXN];
int n;

bool compara_x(const ponto& a, const ponto& b) { return a.x < b.x; }
bool compara_y(const ponto& a, const ponto& b) { return a.y < b.y; }

double sqr(double x) { return x*x; }

double distancia(const ponto& a, const ponto& b)
{
	return (sqr(a.x-b.x) + sqr(a.y-b.y));
}

double par_mais_proximo (int E, int D)
{
	
	if (D-E < 2) return double(INFINITO);
	else if (D-E == 2) return distancia(P[E], P[D-1]);
	else if (D-E > 2)
	{
		int k = (D+E)/2;
		double d1 = par_mais_proximo (E, k);
		double d2 = par_mais_proximo (k, D);
		double dmin = min(d1, d2);

		vector <ponto> L;
		vector <ponto> R;

		for (int i = E; i < k; i++) if (fabs(P[i].x - P[k].x) <= dmin) L.push_back(P[i]);
		for (int i = k; i < D; i++) if (fabs(P[i].x - P[k].x) <= dmin) R.push_back(P[i]);
		
		sort(L.begin(), L.end(), compara_y);
		sort(R.begin(), R.end(), compara_y);
		
		int j = 0; 
	        for (int i = 0; i < L.size(); i++)
		{
			ponto p = L[i]; 
			while (j < R.size() && R[j].y < p.y-dmin) j++; // find the bottom-most candidate from R 
                                
                        for (int l = j; l < R.size() && R[l].y <= p.y + dmin; l++) // check all candidates from R starting with j
				dmin = min(dmin, distancia(p, R[l])); 
		}
		return dmin;
	}
	
}

int main()
{
	while (cin >> n, n)
	{
		for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;

		sort(P, P+n, compara_x);
		
		double d = (n==1)?INFINITO: par_mais_proximo(0, n);

		if (d < 100000000.0) printf("%.4f\n", sqrt(d));
		else printf("INFINITY\n");	
	}
}


