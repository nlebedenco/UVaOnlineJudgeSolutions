#ifdef ONLINE_JUDGE
        #define show(A)
        #define NDEBUG
#else
        #define show(A) cout << #A " = " << (A) << "\n"
#endif
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

char * const INPUT_FILE = "input.10370";
using namespace std;

vector<int> Alunos;
int numAlunos;

int main()
{
        #ifndef ONLINE_JUDGE
                assert(freopen(INPUT_FILE, "rb", stdin));
        #endif
        int TestCases;
        while (cin >> TestCases)
        {
                for(int Caso = 0; Caso < TestCases; Caso++)
                {       
                        cin >> numAlunos; Alunos.clear(); Alunos.reserve(numAlunos);
                        int Total = 0; int Nota;
                        for (int i = 0; i < numAlunos; i++)
                        {
                                cin >> Nota; Total += Nota;
                                Alunos.push_back(Nota);
                        }
                        sort(Alunos.begin(), Alunos.end());
                        double Media = (double)Total / Alunos.size();
                        int Acima = 0;
                        for (int i = 0; i < Alunos.size(); i++) if (Alunos[i] > Media) Acima++;
                        cout.setf(ios::fixed);
                        cout.precision(3);
                        cout << ((double)Acima/numAlunos * 100) << "%\n";
                }
        }
                
        return 0;
}