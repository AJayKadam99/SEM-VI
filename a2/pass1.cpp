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

struct symbol
{
    char sym_name[10];
    int address;
};
vector<struct literal> lit_table = {};
vector<struct symbol> sym_table = {};

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
int checkDuplicateLiteral(char word[])
{
    for (int i = 0; i < lit_table.size(); i++)
    {
        if (strcmp(lit_table[i].lit_name, word) == 0)
            return 1;
    }

    return 0;
}
int checkDuplicateSymbol(char word[])
{
    for (int i = 0; i < sym_table.size(); i++)
    {
        if (strcmp(sym_table[i].sym_name, word) == 0)
            return 1;
    }

    return 0;
}
int checkSymbolLiteral(char word[])
{
    if (word[0] == '=' && word[1] == '\'')
    {
        struct literal lit;
        if (checkDuplicateLiteral(word))
            return 1;
        strcpy(lit.lit_name, word);
        lit_table.push_back(lit);
        return 1;
    }
    else if (checkNum(word))
    {
        // cout << word << "\n";
        return 2;
    }
    else
    {
        struct symbol sym;
        if (checkDuplicateSymbol(word))
            return 3;
        strcpy(sym.sym_name, word);
        sym_table.push_back(sym);
        // cout << "symbol\n";
        return 3;
    }
}

int main()
{
    fstream fp;
    string line;
    bool isDl = false;
    char line1[20];
    char delim[10] = " ,\t\n";
    struct keyword key = {-1, -1};
    fp.open("asm.txt");
    while (fp)
    {
        getline(fp, line);
        isDl = false;
        strcpy(line1, line.c_str());
        char *token = strtok(line1, delim);
        while (token)
        {
            key = checkKeyWord(token);
            if (key.word_type == -1)
                if (checkSymbolLiteral(token) == 2)
                {
                    //update symbol table address
                    // increment LC by this number
                }
            if (key.word_type == 3)
                isDl = true;
            cout << token << "\t";
            cout << " " << key.word_type << " " << key.index << "\n";
            token = strtok(NULL, delim);
        }
    }
    for (int i = 0; i < lit_table.size(); i++)
    {
        cout << lit_table[i].lit_name << "\n";
    }
    for (int i = 0; i < sym_table.size(); i++)
    {
        cout << sym_table[i].sym_name << "\n";
    }
    return 0;
}