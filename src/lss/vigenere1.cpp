#include<cstdio>
#include<cstring>
#include<cctype>
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
    for(int i=0;i<lenk;i++)
      k[i]=toupper(k[i]);   //密钥全部转换为大写
    for(int i=0;i<lenm;i++)  
    {
     int j=i%lenk;
     if(m[i]>='A'&&m[i]<='Z')
         s='A'+(m[i]-k[j]+26)%26;         
     else
         s='a'+(m[i]-(k[j]+32)+26)%26;
      printf("%c",s);
     }
  return 0;      
}
