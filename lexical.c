#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// * because you can store string like that
const char *keywords[] = {"if","else","while","return","int","float","char","void","for"};
const int keywordCount = sizeof(keywords)/sizeof(keywords[0]);

const char *operator[] = {"+","-","*","/","=","==","!=","<",">","<=",">=",};
const int operatorCount = sizeof(operator)/sizeof(operator[0]);

const char delimiter[] ={';',',','(',')','{','}'};

void analyzeTokens(const char *input);
bool isKeyword(const char *str);
bool isDelimiter(char ch);
bool isOperator(char ch);  // Change this to take string


int main(){
    char input[256];
    printf("Enter the input code: ");
    fgets(input,sizeof(input),stdin);
    analyzeTokens(input);
    return 0;
}

void analyzeTokens(const char *input){
    char buffer[100];
    int i=0,j=0;

    while(input[i] != '\0'){
        if(isalnum(input[i]) || input[i] == '_'){
            buffer[j] = input[i];
            j=j+1;
        } else{
            if(j>0){
                buffer[j]='\0';
                if(isKeyword(buffer)){
                    printf("keyword  %s\n",buffer);
                } else if(isdigit(buffer[0])){
                    printf("Number  %s\n",buffer);
                } else {
                    printf("Identifier %s\n",buffer);
                }
                j=0;
            }
            if(isDelimiter(input[i])){
                printf("Delimiter  %c\n",input[i]);
            } else if(isOperator(input[i])){
                printf("Operator  %c\n",input[i]);
            } else if (!isspace(input[i])){
                printf("Unknow Token  %c\n",input[i]);
            }
        }
        i++;
    }
}

bool isKeyword(const char *str){
    for(int i =0;i<keywordCount;i++){
        if(strcmp(str,keywords[i])==0)
            return true;
    }
    return false;
}

bool isDelimiter(char ch){
    for(int i=0;i<sizeof(delimiter)/sizeof(delimiter[0]);i++){
        if(ch == delimiter[i]){
            return true;
        }
    }
    return false;
}

bool isOperator(char ch){
    for(int i=0;i<operatorCount;i++){
        if(strchr(operator[i],ch)){
            return true;
        }
    }
    return false;
}

