#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int CharToBase(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z') return 0; // o maldito coloca espaços, tabs, e +/- então temos que desconsiderar esses sem alterar a divisilidade...
	
        if (isdigit(c)) return c - '0';
        if (isupper(c)) return c - 'A' + 10;
	if (islower(c)) return c - 'a' + 36;
}

bool Divisivel(string& s, int b)
{
	int k = 0;
        for (int i = 0; i < s.size(); i++) k += CharToBase(s[i]);
	       
	return (k%b == 0);
}

string s;
int main()
{
        while (getline(cin, s))
        {
		
		int base = 0;
                for (int i = 0; i < s.size(); i++) 
                {
                        int k = CharToBase(s[i]);
                        if (base < k) base = k; // acha a menor base aceitável
                }
                
                if (base > 0) while (not Divisivel(s, base) && base < 62) base++;
                if (base < 2) base = 1;         
                if (base < 62) printf("%d\n", base+1);
                else printf("such number is impossible!\n");            
        }
        return 0;
}
