#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[26];
int main(){
	freopen("a.txt","r",stdin);
    for(int k=0;k<4;k++){
    	char tmp[100];
    	gets(tmp);
    	for(int i=0;i<strlen(tmp);i++)
    		if('A'<=tmp[i]&&tmp[i]<='Z')
    			sum[tmp[i]-'A']++;
    }
    int Max=0;
    for(int i=1;i<26;i++)
    	Max=max(Max,sum[i]);
    for(int i=Max;i>0;i--){
    	printf("%02d",i);
    	for(int j=0;j<26;j++){
    		if(sum[j]>=i)
    			printf(" * ");
    		else
    			printf("   ");
    		
    	}
    	printf("\n");
    }
    printf("   ");
    for(int i=0;i<26;i++)
    	printf("%02d ",sum[i]);
    cout<<endl;
    for(int i=0;i<26;i++)
    	printf(" %c ",'A'+i);
    return 0;
}
