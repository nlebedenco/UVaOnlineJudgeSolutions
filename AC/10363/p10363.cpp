#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

set<string> conjunto;
const char qual[] = {'X', 'O'};

void gera(char *str, bool vez)
{
    char temp[10], aux;
    memcpy(temp, str, 9);
    temp[9] = '\0';
    string s(temp);
    conjunto.insert(s);
    //printf("%c: %s\n", (vez) ? 'O' : 'X', temp);

    if(temp[0] != '.')
    {
        if(((temp[0] == temp[1]) && (temp[1] == temp[2])) || ((temp[0] == temp[3]) && (temp[3] == temp[6])) || ((temp[0] == temp[4]) && (temp[4] == temp[8])))
            return;
    }
    if((temp[3] != '.') && (temp[3] == temp[4]) && (temp[4] == temp[5]))
        return;
    if((temp[6] != '.') && (temp[6] == temp[7]) && (temp[7] == temp[8]))
        return;
    if((temp[1] != '.') && (temp[1] == temp[4]) && (temp[4] == temp[7]))
        return;
    if(temp[2] != '.')
    {
        if(((temp[2] == temp[5]) && (temp[5] == temp[8])) || ((temp[2] == temp[4]) && (temp[4] == temp[6])))
            return;
    }

    for(int i = 0; i < 9; i++)
        if(temp[i] == '.')
        {
            aux = temp[i];
            temp[i] = (vez) ? 'O' : 'X';
            gera(temp, !vez);
            temp[i] = aux;
        }

}

int main()
{
    int ncase;
    char linha1[5], linha2[5], linha3[5], tab[12];
    scanf("%d", &ncase);
    memset(tab, '.', sizeof(tab));
    gera(tab, false);

    while(ncase--)
    {
        scanf("%s%s%s", linha1, linha2, linha3);
        tab[0] = '\0';
        strcat(tab, linha1);
        strcat(tab, linha2);
        strcat(tab, linha3);
        string objetivo(tab);

        if(conjunto.find(objetivo) != conjunto.end())
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}



