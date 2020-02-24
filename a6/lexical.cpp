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
			return 2;
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
			/*if (checkSym(word[j]))
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
			}*/
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
	
	for (int i = 0; i <file1.length(); i++){
		if(file1[i]=='\n' || file1[i]=='\t' || file1[i]==' ')
			file1.erase(i,1);
	}
	for (int i = 0; i <file1.length(); i++){
		if(file1[i]=='\n' || file1[i]=='\t' || file1[i]==' ')
			file1.erase(i,1);
	}
	for (int i = 0; i <file1.length(); i++)
	{
		int k=0, j=0;
		k = checkSym(file1[i]);
		if(k==1){
			
			line.erase();
			line.append(file1, i, 2);
			//cout<<line<<"\n";
			j = checkOpr(line);
			words.push_back(word);
			word.erase();
			if(j==2){
				words.push_back(line);
				word.erase();
			}
			if(j==0){
				word.append(file1, i,1);
				words.push_back(word);
				word.erase();
			}
		}
		else{
			word.append(file1, i, 1);
		}
		cout << file1[i] <<" "<<k<< " "<<j<<"\n";
		
	}
	words.push_back(word);
	for (int i = 0; i < words.size(); i++){
		int k = checkSym(words[i][0]);
		int j = checkOpr(words[i]);
		if(j==2)
			cout<<words[i]<<" is a terminal symbol\n";
		else if(k==1)
			cout<<words[i]<<" is a operator symbol\n";
		else{
		cout<<words[i]<<" is a terminal\n";
		}
		
	}
	
	
	return 0;
}
