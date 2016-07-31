#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool T[501][501];
int a, b, c, d, W, H, N, Area;
int main()
{
        while (cin >> W >> H >> N, W || H || N)
        {
                Area = W*H;
                memset(T, 0, sizeof(T));
                while (N--)
                {
                        cin >> a >> b >> c >> d;
                        for (int i = min(a, c); i <= max(a, c); i++)
                                for (int j = min(b, d); j <= max(b, d); j++)
                                        if (not T[i][j])
                                        {
                                                T[i][j] = true;
                                                Area--;
                                        }
                }
                if (Area == 0) printf("There is no empty spots.\n");
                else if (Area == 1) printf("There is one empty spot.\n");
                else printf("There are %d empty spots.\n", Area);
        }
        return 0;
}
