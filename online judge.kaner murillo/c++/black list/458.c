#include<stdio.h>
#include<string.h>
int main()
{
int l,i;
char s[1000];
while(gets(s))
 {
 l=strlen(s);
 for(i=0;i<l;i++)
 printf("%c",s[i]-7);
 printf("\n");
 }
return 0;
}