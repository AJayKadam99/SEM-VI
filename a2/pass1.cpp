#include <bits/stdc++.h>
using namespace std;

vector<string> MOT = {"STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM", "COMP", "BC", "DIV", "READ", "PRINT", "STORE", "LOAD"};
vector<string> AD = {"START", "END", "ORIGIN", "EQU", "LTORG"};
vector<string> DL = {"DC", "DS"};
vector<string> REG = {"AREG", "BREG", "CREG"};

struct keyword
{
    int word_type, index;
};

struct literal
{
    char lit_name[10];
    int address;
};

vector<struct literal> lit_table = {};

struct keyword checkKeyWord(char word[])
{
    struct keyword key = {-1, -1};
    vector<vector<string>> tab = {MOT, AD, DL, REG};
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < tab[j].size(); i++)
        {
            if (strcmp(tab[j][i].c_str(), word) == 0)
            {
                key.word_type = tab[j] == MOT ? j : j + 1;
                key.index = i;
                return key;
            }
        }
    return key;
}

int checkNum(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (!isdigit(word[i]))
            return 0;
    }
    return 1;
}

int checkSymbolLiteral(char word[])
{
    if (word[0] == '=' && word[1] == '\'')
    {
        struct literal lit;
        strcpy(lit.lit_name, word);
        lit_table.push_back(lit);
        return 1;
    }
    else if (checkNum(word))
    {
        cout << word << "\n";
        return 2;
    }
    else
    {
        cout << "symbol\n";
        return 3;
    }
}

int main()
{
    fstream fp;
    string line;
    char line1[20];
    char delim[10] = " ,\t\n";
    struct keyword key = {-1, -1};
    fp.open("asm.txt");
    while (fp)
    {
        getline(fp, line);
        strcpy(line1, line.c_str());
        char *token = strtok(line1, delim);
        while (token)
        {
            key = checkKeyWord(token);
            if (key.word_type == -1)
                cout << checkSymbolLiteral(token) << "\n";
            cout << token << "\t";
            cout << " " << key.word_type << " " << key.index << "\n";
            token = strtok(NULL, delim);
        }
    }
    for (int i = 0; i < lit_table.size(); i++)
    {
        cout << lit_table[i].lit_name << "\n";
    }
    return 0;
}