#include <bits/stdc++.h>
using namespace std;

struct UST
{
	int index;
	string classname;
	string symbol;
};

vector<string> TRM = {"include", "stdio.h", "void", "int", "for", "if", "printf", "getch"};
vector<char> SYM = {
	'#',
	'<',
	'>',
	'(',
	')',
	'{',
	',',
	'=',
	';',
	'+',
	'*',
	'-',
	'\'',
	'}',
	' '};
vector<string> OPR = {
	"<=",
	"++",
	"=="};

vector<string> LITERALS = {};
vector<string> SYMBOLS = {};
vector<string> TERMINALS = {};
vector<string> KEYWORDS = {};
vector<struct UST> Universal = {};

int checkSym(char c)
{
	for (int i = 0; i < SYM.size(); i++)
	{
		if (c == SYM[i])
			return 1;
	}
	return 0;
}
int checkOpr(string s)
{
	for (int i = 0; i < OPR.size(); i++)
	{
		if (s.compare(OPR[i]) == 0)
			return 2;
	}
	return 0;
}
int checkKey(string s)
{
	for (int i = 0; i < TRM.size(); i++)
	{
		if (s.compare(TRM[i]) == 0)
			return 3;
	}
	return 0;
}
int checkDigits(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) != 0)
			return 1;
	}
	return 0;
}
int checkTerminals(string s)
{
	for (int i = 0; i < TERMINALS.size(); i++)
	{
		if (s.compare(TERMINALS[i]) == 0)
			return i;
	}
	return -1;
}
int checkKeywords(string s)
{
	for (int i = 0; i < KEYWORDS.size(); i++)
	{
		if (s.compare(KEYWORDS[i]) == 0)
			return i;
	}
	return -1;
}
int checkLiterals(string s)
{
	for (int i = 0; i < LITERALS.size(); i++)
	{
		if (s.compare(LITERALS[i]) == 0)
			return i;
	}
	return -1;
}
int checkSymbols(string s)
{
	for (int i = 0; i < SYMBOLS.size(); i++)
	{
		if (s.compare(SYMBOLS[i]) == 0)
			return i;
	}
	return -1;
}
int main()
{
	fstream fp1, fp2;
	fp1.open("TRM.txt");
	vector<string> words;
	struct UST ustsymbol;
	string file1;
	string line;
	string word;
	char str[20];
	char c;
	char *token;

	fp1.close();
	fp1.open("input.cpp");

	while (fp1)
	{
		getline(fp1, line);
		file1.append(line);
	}

	fp1.close();
	fp2.close();

	for (int i = 0; i < file1.length(); i++)
	{
		if (file1[i] == '\n' || file1[i] == '\t')
			file1.erase(i, 1);
	}
	for (int i = 0; i < file1.length(); i++)
	{
		int k = 0, j = 0;
		k = checkSym(file1[i]);
		if (k == 1)
		{

			line.erase();
			line.append(file1, i, 2);
			j = checkOpr(line);
			words.push_back(word);
			word.erase();
			if (j == 2)
			{
				words.push_back(line);
				word.erase();
				i++;
			}
			if (j == 0)
			{
				word.append(file1, i, 1);
				words.push_back(word);
				word.erase();
			}
		}
		else
		{
			word.append(file1, i, 1);
		}
	}
	words.push_back(word);
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i].compare("\n") == 0 || words[i].compare("\t") == 0 || words[i].compare(" ") == 0 || words[i].compare("") == 0)
			words.erase(words.begin() + i);
	}
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i].compare("\n") == 0 || words[i].compare("\t") == 0 || words[i].compare(" ") == 0 || words[i].compare("") == 0)
			words.erase(words.begin() + i);
	}
	for (int i = 0; i < words.size(); i++)
	{
		words[i].erase(0, words[i].find_first_not_of("\t\n\v\f\r "));
	}

	for (int i = 0; i < words.size(); i++)
	{
		int k = checkSym(words[i][0]);
		int j = checkOpr(words[i]);
		int z = checkKey(words[i]);
		k = max(k, j);
		k = max(k, z);

		switch (k)
		{
		case 0:
		{
			if (checkDigits(words[i]) != 0)
			{
				z = checkLiterals(words[i]);
				if (z == -1)
				{
					LITERALS.push_back(words[i]);
					z = LITERALS.size() - 1;
				}
				ustsymbol.index = z;
				ustsymbol.symbol = words[i];
				ustsymbol.classname = "LIT";
			}
			else
			{
				z = checkSymbols(words[i]);
				if (z == -1)
				{
					SYMBOLS.push_back(words[i]);
					z = SYMBOLS.size() - 1;
				}
				ustsymbol.index = z;
				ustsymbol.symbol = words[i];
				ustsymbol.classname = "SYM";
			}
			Universal.push_back(ustsymbol);
			break;
		}
		case 1:
		{
			z = checkTerminals(words[i]);
			if (z == -1)
			{
				TERMINALS.push_back(words[i]);
				z = TERMINALS.size() - 1;
			}
			ustsymbol.index = z;
			ustsymbol.symbol = words[i];
			ustsymbol.classname = "TRM";
			Universal.push_back(ustsymbol);
			break;
		}
		case 2:
		{
			z = checkTerminals(words[i]);
			if (z == -1)
			{
				TERMINALS.push_back(words[i]);
				z = TERMINALS.size() - 1;
			}
			ustsymbol.index = z;
			ustsymbol.symbol = words[i];
			ustsymbol.classname = "TRM";
			Universal.push_back(ustsymbol);
			break;
		}
		case 3:
		{
			z = checkTerminals(words[i]);
			if (z == -1)
			{
				TERMINALS.push_back(words[i]);
				z = TERMINALS.size() - 1;
			}
			ustsymbol.index = z;
			ustsymbol.symbol = words[i];
			ustsymbol.classname = "TRM";
			Universal.push_back(ustsymbol);
			break;
		}
		}
	}
	cout << "SYMBOLS\n";
	for (int i = 0; i < SYMBOLS.size(); i++)
	{
		cout << i << "\t" << SYMBOLS[i] << "\n";
	}
	cout << "\nLITERALS\n";
	for (int i = 0; i < LITERALS.size(); i++)
	{
		cout << i << "\t" << LITERALS[i] << "\n";
	}
	cout << "\nTERMINALS\n";
	for (int i = 0; i < TERMINALS.size(); i++)
	{
		cout << i << "\t" << TERMINALS[i] << "\n";
	}

	cout << "\nUNIVERSAL SYMBOL TABLE\n";
	for (int i = 0; i < Universal.size(); i++)
	{
		cout << i << "\t" << Universal[i].index << "\t" << Universal[i].classname << "\t" << Universal[i].symbol << "\n";
	}
	return 0;
}
