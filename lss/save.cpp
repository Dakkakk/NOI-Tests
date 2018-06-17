#include<cstdio>  
using namespace std;  
int main()  
{  
 freopen("save.in","r",stdin);
 freopen("save.out","w",stdout);
  int i,j,k,x=0,y=0;  
   for(i=1;i<=12;i++)  
    {  
      scanf("%d",&j);  //读入12个月的预算，注意：此题并没有用数组
      x+=300;  
      if(x<j){printf("-%d\n",i);return 0;}  //return 0是结束程序
      x-=j;
      k=x%100;
      y+=x-k;
      x=k;  
    }  
  printf("%d\n",x+y*120/100);    
  return 0;  
} 
