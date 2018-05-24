#include<iostream>
#include<cstdio>       //freopen必须包括此头文件 
#include<cstring>      //使用了strlen()函数 
#include<cctype>      //程序中使用了toupper()函数 
using namespace std;
char k[110],m[10010];
char s;
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    scanf("%s%s",k,m);
    int lenk=strlen(k);
    int lenm=strlen(m);
    for(int i=0;i<lenk;i++)    //兼容性说明：strupr不是标准C库函数，只
      k[i]=toupper(k[i]);     //能在VC中使用。在linux gcc环境下需要自行定义这个函数。
    for(int i=0;i<lenm;i++)  
    {
     int j=i%lenk;
     s=m[i]-(k[j]-65);   //k[j]-65就是编码时应该变化的量（位移）
     //密文m[i]是大写，但明文s不是大写时，或密文m[i]是小写，但明文s不是小写时，都要+26。
     if((m[i]>='A'&&m[i]<='Z'&&s<'A')||(m[i]>='a'&&m[i]<='z'&&s<'a'))
       s=s+26;
     printf("%c",s);
     }
  return 0;      
}
