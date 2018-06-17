#include<iostream>
#include<algorithm>
using namespace std;
int a[10];
void qs(int l,int r)
{
	int i,j,mid,temp;
	i=l;j=r;
	mid=a[(i+j)/2];
	do
	  {
	  	while(a[i]<mid) i++;
	  	while(a[j]>mid) j--;
	  	if(i<j)
	  	  {
	  	  	temp=a[i];
	  	  	a[i]=a[j];
	  	  	a[j]=temp;
	  	  	i++;j--;
	  	  }  
	  }while(i<j);
	if(i<r) qs(i,r);
	if(j>l) qs(l,j);  
}
int main()
{
	for(int i=1;i<9;++i)
	  cin>>a[i];
//	sort(a+1,a+9);
    qs(1,8);
	for(int i=1;i<9;++i)
	  cout<<a[i]<<" ";
	return 0;    
}
