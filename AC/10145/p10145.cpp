#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n, tid, item;
char mode;

set <int> ignored;               // trids
map <int, vector<int> > shared;  // resource, trids
map <int, int> locked;           // resource, locker

int main()
{
        cin >> n;
        while (n--)
        {
                ignored.clear();
                locked.clear();
                shared.clear();
                while (cin >> mode, mode != '#')
                {
                   cin >> tid >> item;
                   if (ignored.find(tid) != ignored.end())
                   {
                           printf("IGNORED\n");
                           continue;
                   }       

                   if (locked.find(item) != locked.end())
                           if (locked[item] != tid)
                           {
                                printf("DENIED\n");
                                ignored.insert(tid);
                                continue;
                           }
                   
                   if (mode == 'X' and shared.find(item) != shared.end())
                   {
                        bool achou = false;   
                        for (int i = 0; i < shared[item].size() && not achou; i++)
                                achou = (shared[item][i] != tid);
                        if (achou)
                        {
                                printf("DENIED\n");
                                ignored.insert(tid);
                                continue;
                        }
                   }

                   if (mode == 'X') locked[item] = tid;
                   else if (mode == 'S') shared[item].push_back(tid);
                      
                   printf("GRANTED\n");
                }
                if (n) printf ("\n");
        }
}
