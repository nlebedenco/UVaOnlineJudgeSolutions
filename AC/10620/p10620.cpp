#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int S, x, y, dx, dy, alfa;

int mdc(int a, int b)
{
  if(a < 0) a = -a;
  if(b < 0) b = -b;

  if(b == 0) return a;
  else return mdc(b, a%b);
}

int mmc(int a, int b)
{
	return ( a * b / mdc(a, b) );
}

int Verifica()
{
	if ( (x/S)%2 != (y/S)%2 && (x%S!= 0) && (y%S != 0) ) return 0;

	int per = 2 * mmc( S/mdc(S,dx), S/mdc(S,dy));
	int c;
	for (c = 1; c <= per; c++)
		if ( (((x+c*dx)/S)%2 != ((y+c*dy)/S)%2) && // if the square is white
		     ((x+c*dx)%S != 0) && ((y+c*dy)%S != 0)) // if the point is not in a border
		       	break;
	
	if (c > per) return -1;
	else return c;
}
	
int main()
{
	while (cin >> S >> x >> y >> dx >> dy, S || x || y || dx || dy)
	{
		int alfa = Verifica();
		if (alfa == -1) printf("The flea cannot escape from black squares.\n");
		else printf("After %d jumps the flea lands at (%d, %d).\n", alfa, x+alfa*dx, y+alfa*dy);
	}
	return 0;
}
