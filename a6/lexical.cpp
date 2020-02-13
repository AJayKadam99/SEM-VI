#include <bits/stdc++.h>
using namespace std;

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
	'\''};
vector<string> OPR = {
	"<=",
	"++",
	"=="};
int checkTrm(char c)
{

	for (auto i = SYM.begin(); i != SYM.end(); i++)
	{
		if (c == (*i))
			return i - SYM.begin();
	}
	return -1;
}
int main()
{
	fstream fp1;
	fp1.open("TRM.txt");
	string line;
	char str[20];
	char c;
	char *token;
	while (fp1)
	{
		getline(fp1, line);
		TRM.push_back(line);
	}
	// for (int i = 0; i < TRM.size(); i++)
	// 	cout << TRM[i] << " " << strlen(TRM[i].c_str()) << "\n";
	fp1.close();
	fp1.open("input.cpp");
	while (fp1)
	{
		fp1 >> c;
		cout << c << " " << checkTrm(c) << " trm\n";
	}
	return 0;
}
