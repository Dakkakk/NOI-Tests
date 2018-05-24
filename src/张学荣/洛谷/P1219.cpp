#include<stdio.h>
#include<math.h>
int n,func[200],functions=0,outLast=3;
int f1[200],f2[200];
void dfs(int index){
	if(index==n){
		functions++;
		if(outLast>0){
			for(int i=0;i<n;i++)
				printf("%d ",func[i]+1);
			printf("\n");
			outLast--;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(f1[i]==0&&f2[abs(i+index)]==0){
			f1[i]=1;
			f2[abs(i+index)]=1;
			func[index]=i;
			dfs(index+1);
			f1[i]=0;
			f2[abs(i+index)]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(0);
	printf("%d",functions);
	return 0;
}
