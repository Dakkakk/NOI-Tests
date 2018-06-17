#include<iostream>
 using namespace std;
 int a[101];int n;
 int main()
 { 
 cin>>n;
    for(int i=0;i<=n;++i)a[i]=0; 
    while(a[0]!=1)
//     {
//     	for(int k=1;k<=n;k++)
//     	{
//     		t=t+t[k]*a[k];
//     		p=p+p[k]*a[k];
//     		if (t<=time)&&(p>ans)
//     		ans=p;
//     	}
//	 for(int k=1;k<=n;++k)cout<<a[k];
//     cout<<endl; 
     int j=n;
     while(a[j]==1)j--;
      a[j]=1;
     for(int i=j+1;i<=n;++i) a[i]=0; 
     }
 return 0;
}

