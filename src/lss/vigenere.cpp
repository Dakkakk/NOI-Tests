#include<iostream>
#include<cstdio>       //freopen���������ͷ�ļ� 
#include<cstring>      //ʹ����strlen()���� 
#include<cctype>      //������ʹ����toupper()���� 
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
    for(int i=0;i<lenk;i++)    //������˵����strupr���Ǳ�׼C�⺯����ֻ
      k[i]=toupper(k[i]);     //����VC��ʹ�á���linux gcc��������Ҫ���ж������������
    for(int i=0;i<lenm;i++)  
    {
     int j=i%lenk;
     s=m[i]-(k[j]-65);   //k[j]-65���Ǳ���ʱӦ�ñ仯������λ�ƣ�
     //����m[i]�Ǵ�д��������s���Ǵ�дʱ��������m[i]��Сд��������s����Сдʱ����Ҫ+26��
     if((m[i]>='A'&&m[i]<='Z'&&s<'A')||(m[i]>='a'&&m[i]<='z'&&s<'a'))
       s=s+26;
     printf("%c",s);
     }
  return 0;      
}
