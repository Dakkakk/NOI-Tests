#include<iostream>
#include<cstdio>
using namespace std;
int a[1000];
int n;
int main()
{	
		scanf("%d",&n);
        int sum=0,l=0,left=0;
        for(int i=2;i<=n;i++)
        {	
        	l++;
            a[l]=i;
            sum+=i;
            if(sum>n)
            {
                sum-=i,l--,left=n-sum;//Ê£ÓàµÄ 
                break;
            }
        }
        for(int i=1;left>0;left--)
        {
            a[i]+=1;
            i++;
            if(i>l) i=1;
        }
       long long  ans=1;
       if(n!=0)
        for(int i=1;i<=l;i++)
    		ans*=a[i];
    	else
    	ans=0;
  		cout<<ans;
    return 0;
}
