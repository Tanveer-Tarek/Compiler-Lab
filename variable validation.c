#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
   char word[20];
    gets(word);
   int var=0;
    int length=sizeof(word);
    for(int i=0;i<=length;i++){
        if( isalpha(word[0]) || word[i]=='_' ){
            printf("This is a variable");
            var=1;
            break;
            }

        else{
            printf("Not a variable");
            break;
        }
    }

     }



