#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include <assert.h>

#ifndef ONLINE_JUDGE
	#define TEST_INPUT_FILE "input"
	#ifdef DEBUG_OUTPUT
		#define TEST_OUTPUT_FILE "model.out"
	#endif
#endif

using namespace std;

const int cmdGoto		= 0;
const int cmdHalt 	 	= 100;
const int cmdSetReg  	 	= 200;
const int cmdAdd  	 	= 300;
const int cmdMultiply 	 	= 400;
const int cmdSetRegToReg 	= 500;
const int cmdAddRegToReg	= 600;
const int cmdMultiplyRegToReg	= 700;
const int cmdSetRegToRAMValue	= 800;
const int cmdSetRAMToReg	= 900;

vector <int> RAM;
vector <int> Registradores(10);

int TestCases = 0;
int NumberOfInstructions = 0;
int Instruction;
int d, s, n; // parametros receber os parametros das instrucoes

int main()
{
	#ifdef TEST_INPUT_FILE
		ifstream cin(TEST_INPUT_FILE); assert(cin);
	#endif
	
	#ifdef TEST_OUTPUT_FILE
		ofstream cout(TEST_INPUT_FILE); assert(cout);
	#endif
	
	RAM.reserve(1000);
	while (cin >> TestCases)
	{
		for (int z = 0; z < TestCases; z++)
		{
			RAM.clear(); fill(Registradores.begin(), Registradores.end(), 0);
			NumberOfInstructions = 0;

			while (cin >> Instruction)
			{
				RAM.push_back(Instruction % 1000);
				cin.get(); // tiro uma quebra de linha do buffer...
				if (cin.peek() == '\n') break; // ...se achar outra é pq temos uma linha em branco
			}
			
			int it = 0; // note que seu eu colocar aqui um valor acima de RAM.size() teremos segfault
			// while (it < RAM.size())  // Assim dá Wrong Answer!!! Como pode??
			while (true)  // Assim dá Accepted
			{
				NumberOfInstructions++;
				// while (it > RAM.size()); Essa linha sem comentário dá TLE!!! O que quer dizer que o it pode ficar maior que o RAM.size()
				// Isso só poderia acontecer porque processamos o último elemento da RAM ou porque o goto nos envia para 
				// endereços fora do espaço de instruções. Se fosse o primeiro caso não poderia dar WA para while (it < RAM.size())
				// então deve ser o segundo caso. Sendo assim, como o loop termina???? Ele deve estar encontrando 
				// uma instrução 100, mas como pode???
				
				//if (it < RAM.size())  // isso ajusta as coisas, embora o uso de RAM.reserve() parece tornar essa linha desnecessária
				if (RAM[it] >= cmdSetRAMToReg)
				{ 
					s = RAM[it] % 10; d = (RAM[it] - cmdSetRAMToReg - s) / 10;
					RAM[Registradores[s]] =  Registradores[d];
					it++; 
				}
				else if (RAM[it] >= cmdSetRegToRAMValue)
				{ 
					s = RAM[it] % 10; d = (RAM[it] - cmdSetRegToRAMValue - s) / 10;
					Registradores[d] = RAM[Registradores[s]];
					it++; 
				}
				else if (RAM[it] >= cmdMultiplyRegToReg)
				{
					s = RAM[it] % 10; d = (RAM[it] - cmdMultiplyRegToReg - s) / 10;
					Registradores[d] *= Registradores[s];
					Registradores[d] %= 1000;
					it++; 
				}
				else if (RAM[it] >=  cmdAddRegToReg)
				{
					s = RAM[it] % 10; d = (RAM[it] - cmdAddRegToReg - s) / 10;
					Registradores[d] += Registradores[s];
					Registradores[d] %= 1000;
					it++; 
				}
				else if (RAM[it] >=  cmdSetRegToReg)
				{
					s = RAM[it] % 10; d = (RAM[it] - cmdSetRegToReg - s) / 10;
					Registradores[d] =  Registradores[s];
					it++; 
				}
				else if (RAM[it]  >=  cmdMultiply)
				{ 
					n = RAM[it] % 10; d = (RAM[it] - cmdMultiply - n) / 10;
					Registradores[d] *= n;
					Registradores[d] %= 1000;
					it++; 
				}
				else if (RAM[it]  >=  cmdAdd)
				{ 
					n = RAM[it] % 10; d = (RAM[it] - cmdAdd - n) / 10;
					Registradores[d] += n;
					Registradores[d] %= 1000;
					it++; 
				}
				else if (RAM[it]  >=  cmdSetReg) 
				{ 
					n = RAM[it] % 10; d = (RAM[it] - cmdSetReg - n) / 10;
					Registradores[d] = n % 1000;
					it++; 
				}
				else if (RAM[it] == cmdHalt)
				{ 
					// while (it > RAM.size()); // Essa linha indica que há um instante em que aqui o it é maior que o RAM.size()!!!! Como isso não deu segfault no teste do if???
					break;
				}
				else if (RAM[it]  >=  cmdGoto)
				{ 
					s = RAM[it] % 10; d = (RAM[it] - s) / 10;
					if (Registradores[s] != 0) it = Registradores[d];
					else it++;
				}
				
			}
			
			cout << NumberOfInstructions << "\n";
			if (z != TestCases-1) cout << "\n";
		}
	}
	return 0;
}
