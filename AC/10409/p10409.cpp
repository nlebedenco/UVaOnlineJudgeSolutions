#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const string N = "north";
const string E = "east";
const string S = "south";
const string W = "west";

int n;
string a;

enum {top, north, east, south, west, bottom};

int face[6];

void Reset()
{
	face[top] = 1;
	face[north] = 2;
	face[west] = 3;
	face[east] = 4;
	face[south] = 5;
	face[bottom] = 6;
}

int main()
{
	while (cin >> n, n)
	{
		Reset();
		while (n--)
		{	
			cin >> a;
			if (a == N) 
			{
				int t = face[top];
				face[top] = face[south];
				face[south] = face[bottom];
				face[bottom] = face[north];
				face[north] = t;
			}
			else if (a == E) 
			{
				int t = face[top];
				face[top] = face[west];
				face[west] = face[bottom];
				face[bottom] = face[east];
				face[east] = t;
				
			}	
			else if (a == S) 
			{
				int t = face[top];
				face[top] = face[north];
				face[north] = face[bottom];
				face[bottom] = face[south];
				face[south] = t;
			}
			else if (a == W) 
			{
				int t = face[top];
				face[top] = face[east];
				face[east] = face[bottom];
				face[bottom] = face[west];
				face[west] = t;
			}
		}	
		printf("%d\n", face[top]);
	}	
	return 0;
}

