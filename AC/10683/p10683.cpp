 
#include <iostream>
#include <iomanip>
#include <fstream>

/* vários problemas de arredondamento em todo o código comentado 
   o melhor mesmo era fazer so operaçoes com inteiros e usar a razao 125 / 108 que eh
   aprox 1,157407407407407... deixando a operação exclusivamente entre inteiros...
*/

using namespace std;

const int MAX_CENTESIMOS_60  = 8639999;
const int MAX_CENTESIMOS_100 = 9999999;

const double RAZAO = 1.15740742;

const int HORA_100      = 1000000;
const int MINUTO_100    = 10000;
const int SEGUNDO_100   = 100;
const int CENTESIMO_100 = 1;

char h1, h2, m1, m2, s1, s2, c1, c2;

int hora, minuto, segundo, centesimo;
int TotalCentesimos_100, TotalCentesimos_60;

int main()
{
        while (cin >> h1 >> h2 >> m1 >> m2 >> s1 >> s2 >> c1 >> c2)
        {       
                hora      = (h1 - '0') * 10 + (h2 - '0');
                minuto    = (m1 - '0') * 10 + (m2 - '0');
                segundo   = (s1 - '0') * 10 + (s2 - '0');
                centesimo = (c1 - '0') * 10 + (c2 - '0');

                TotalCentesimos_60 = (hora * 60 * 60 * 100) + (minuto * 60 * 100) + (segundo * 100) + (centesimo);
                
                // TotalCentesimos_100 = (double) TotalCentesimos_60 * ((double) MAX_CENTESIMOS_100 / MAX_CENTESIMOS_60);
                
                TotalCentesimos_100 = TotalCentesimos_60 * 125 / 108;
                
                /* hora = 0; minuto = 0; segundo = 0; centesimo = 0;
                while (TotalCentesimos_100 >= HORA_100) 
                {
                        hora++;
                        TotalCentesimos_100 -= HORA_100;
                } 
                while (TotalCentesimos_100 >= MINUTO_100) 
                {
                        minuto++;
                        TotalCentesimos_100 -= MINUTO_100;
                } 
                while (TotalCentesimos_100 >= SEGUNDO_100) 
                {
                        segundo++;
                        TotalCentesimos_100 -= SEGUNDO_100;
                }
                centesimo = TotalCentesimos_100;
                
                cout << hora;
                cout << setw(2) << setfill('0') << minuto << segundo << centesimo << "\n";
                */

                cout << setw(7) << setfill('0') << TotalCentesimos_100 << "\n";
        }
        return 0;
}