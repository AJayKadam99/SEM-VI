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

// vector<string> checkOprAndTrm(vector<string> words)
// {
// 	string word, opr, trm;
// 	for (auto i = words.begin(); i != words.end(); i++)
// 		for (auto j = OPR.begin(); j != OPR.end(); j++)
// 		{
// 			word = *i;
// 			opr = *j;
// 			if (strcmp(word.c_str(), opr.c_str()) == 0)
// 				words.erase(i);
// 		}
// 	for (auto i = words.begin(); i != words.end(); i++)
// 		for (auto k = TRM.begin(); k != TRM.end(); k++)
// 		{
// 			word = *i;
// 			trm = *k;
// 			if (strcmp(word.c_str(), trm.c_str()) == 0)
// 				words.erase(i);
// 		}
// 	return words;
// }

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
			return 1;
	}
	return 0;
}
vector<string> checkTrm(vector<string> words)
{
	string word, opr, opr1;
	for (int i = 0; i < words.size(); i++)
	{
		word = words[i];
		// for (auto j = OPR.begin(); j != OPR.end(); j++)
		// {
		// 	opr = *j;
		// 	if (strcmp(word.c_str(), opr.c_str()) == 0)
		// 	{
		// 		cout << word << " is a Operator\n";
		// 		words.erase(i);
		// 		k = 1;
		// 		break;
		// 	}
		// }
		for (int j = 0; j < word.length(); j++)
		{
			// cout << word[j] << "\n";
			if (checkSym(word[j]))
			{
				opr = word[j] + word[j + 1];
				if (checkOpr(opr))
				{
					words[i].erase(j, 2);
					words.insert(words.begin() + i, opr);
				}
				else
				{
					string str(1, word[j]);
					words.insert(words.begin() + i, str);
					words[i].erase(j, 1);
				}
			}
		}
	}
	return words;
}
int main()
{
	fstream fp1, fp2;
	fp1.open("TRM.txt");
	vector<string> words;
	string file1;
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
	fp2.open("temp.cpp", ios::out);
	while (fp1)
	{
		getline(fp1, line);
		//		cout << " " << line;
		fp2 << line << "\n";
	}
	fp1.close();
	fp2.close();
	fp2.open("temp.cpp");
	while (fp2)
	{
		fp2 >> line;
		//cout << line << "\n";
		words.push_back(line);
	}
	// words = checkOprAndTrm(words);
	// for (int i = 0; i < words.size(); i++)
	// {
	// 	cout << words[i] << "\n";
	// }
	words = checkTrm(words);
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << "\n";
	}
	/*fp2.clear();
	fp2.seekg(0, ios::beg);
	while (fp2)
	{
		fp2 >> c;
		cout << c << " " << checkTrm(c) << " trm\n";
	}*/
	return 0;
}
