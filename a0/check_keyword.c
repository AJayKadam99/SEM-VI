#include<stdio.h>
#include<string.h>

int main(){
char keyWords[50][6]={"START","READ", "MOVER", "PRINT", "STOP", "END"};
char currentLine[50];
int i=0, k=0, count = 0;
FILE *fp;
fp = fopen("./a.txt", "r+");

int l = strlen(*keyWords);


while(fgets(currentLine,50, fp)){
    count++;
    char *currentKeyWord = strtok(currentLine, " \t\n");
    i = 0;
    k = 0;
    for(i=0;i<=l;i++){
	if(strcmp(currentKeyWord, keyWords[i])==0){
	    k=1;
	    break;
	}
    }
    if(!k)
	printf("%s does not match any keyword at line number %d \n", currentKeyWord, count);
}
   return 0;
}

