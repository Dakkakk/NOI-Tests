#include<stdio.h>  
#include<queue>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
struct node  
{  
    int m;  
    bool operator<(const node &a) const//优先队列，重量小的在前  
    {  
        return a.m<m;  
    }  
};  
int main()  
{  
    freopen("fruit.in","r",stdin);
    freopen("fruit.ans","w",stdout);
    int i,j,n,sum;  
    priority_queue<node>Q;  
    node p,q;  
    while(~scanf("%d",&n))  
    {  
        for(i=0; i<n; i++)  
        {  
            scanf("%d",&p.m);  
            Q.push(p);  
        }  
        sum=0;  
       for(i=0;i<n-1;i++)//n个果子只需要n-1次合并  
        {  
            p=Q.top(),Q.pop();  
            q=Q.top(),Q.pop();  
            sum+=p.m+q.m;  
            p.m=p.m+q.m;  
            Q.push(p);  
        }  
        while(!Q.empty())  
            Q.pop();  
        printf("%d\n",sum);  
    }  
    return 0;  
} 
