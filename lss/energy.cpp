#include <iostream>
#include <cstdio>    
using namespace std;  
int n, e=0;  
int a[111*2];  
int dp[111*2][111*2];  
int main()  
{   
    freopen("energy.in","r",stdin);
    freopen("energy.ans","w",stdout);
    cin >> n;  
    for(int i=1; i<=n; i++)  
    {  
      cin >> a[i];  
      a[i+n] = a[i];    //������ģ�⻷������һ��ѭ��
    }  
    for(int i=n+n-1;i>=1; i--)      //��� ���ǵ��ý���
    {  
      for(int j=i+1;j<=n+n&&j-i<n;j++)    //�յ� 
      {  
        int maxV = 0;  
        for(int k=i; k<j; k++)  //����
        {  
          if(maxV<dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1])  
            maxV=dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];  
        }  
        dp[i][j] = maxV;  
        if(e < dp[i][j]) e = dp[i][j];  
      }  
    }   
    cout << e;  
    return 0;  
 }
