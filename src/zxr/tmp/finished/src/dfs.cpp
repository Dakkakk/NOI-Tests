#include<cstdio>
int dfs()(int k)/*阶段*/{
	if(满足题解条件)返回解;
	
	for(int i=1;i<=该阶段出现的可能情况数;i++){
		if(满足题目限制性条件){
			保存结果;
			dfs(k+1)/*下一阶段*/
			恢复;/*防止影响下次搜索*/ 
		}
	}	
}
int main(){
	dfs();
	return 0;
}
