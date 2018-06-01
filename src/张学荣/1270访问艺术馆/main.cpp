#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
/*
他拿下一幅画需要5秒的时间
【输入】
	第1行是警察赶到的时间。
	第2行描述了艺术馆的结构，成对地出现：
	   每一对的第一个数是走过一条走廊的时间，
	  第2个数是它末端的藏画数量；如果第2个数是0，
	  那么说明这条走廊分叉为两条另外的走廊。
	  数据按照深度优先的次序给出
	一个展室最多有20幅画。
	通过每个走廊的时间不超过20s。
	艺术馆最多有100个展室。
	警察赶到的时间在10min以内。
输出偷到的画的数量

首先，题目保证数是二叉树。定义状态f(n, t)表示在结点n
所在子树上花t时间所能取到的最大分值，则状态转移方程为
	f(n, t)=max{f(left, t0)+f(right, t-t0)}
其中left和right为n的左右子结点，t0的取值范围为[0, t]。
	算法的时间复杂度为O(n3)。
*/

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	return 0;
}
