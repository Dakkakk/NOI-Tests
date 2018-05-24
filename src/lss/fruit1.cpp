#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int>que;
int main()
{
    freopen("fruit.in","r",stdin);
    freopen("fruit.ans","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
      int x;
      scanf("%d",&x);
      que.push(-x);
    }
    int ans=0;
    for(int i=1;i<n;++i)
      {
       int temp=que.top();
       ans-=que.top();
       que.pop();
       temp+=que.top();
       ans-=que.top();
       que.pop();
       que.push(temp);
     }
    printf("%d",ans);
    return 0;      
}
