#include<stdio.h>
int main()
{
char str[50];
int i,vowels=0;
printf("Enter the Word :");
gets(str);
for(int i=0;str[i];i++)
{
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
       str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
{
    vowels++;
    str[i]=='T';
}

}
printf("Number of vowels= %d \n",vowels);
printf("%s",str);
return 0;
}
