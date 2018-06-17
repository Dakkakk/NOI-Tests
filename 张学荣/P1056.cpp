#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Line{
    int x,y;
    int times;//有times对同学过这一条直线 
};
//  行，列，横向通道，纵向通道，D对同学 
int M,   N,  K,        L,         D;
vector<Line> vec;
int find(int x,int y){
	for(int i=0;i<vec.size();i++)
		if(vec[i].x==x&&vec[i].y==y)
			return i;
	Line line;
	line.x=x;
	line.y=y;
	line.times=0;
	vec.push_back(line);
	return find(x,y);
}
void process(){
	Line line;
	int x1,y1;
	int x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
		vec[find(-1,min(y1,y2))].times++;
	else
		vec[find(min(x1,x2),-1)].times++;
}

bool camp(Line a,Line b){
	return a.times>b.times;
}

void output(){
	for(int i=0;i<vec.size();i++){
    	cout<<"ID="<<i<<'\n';
    	cout<<"x="<<vec[i].x<<" y="<<vec[i].y<<'\n';
    	cout<<"times="<<vec[i].times<<'\n';
    }
}

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    cin>>M>>N>>K>>L>>D;
    for(int i=0;i<D;i++)
    	process();
    sort(vec.begin(),vec.end(),&camp);
    output();
    //纵向   横向 
    int H[L],W[K];
    int a=0,b=0;
    for(int i=0;i<vec.size();i++){
    	Line line=vec[i];
    	if(line.x==-1&&a<L){
    		W[a]=line.y;
    		a++;
    	}
		if(line.y==-1&&b<K){
    		H[b]=line.x;
    		b++;
    	}
    }
  //  for(int i=0,j=0;i<vec.size()&&j<L;i++){
  //  	if(vec[i].x==-1){
   // 		W[j]=vec[i].y;
   // 		j++;
   // 	}
    //}
	//for(int i=0,j=0;i<vec.size()&&j<K;i++){
    //	if(vec[i].y==-1){
    //		W[j]=vec[i].x;
    //		j++;
    //	}
    //}
    sort(H,H+L);
    sort(W,W+K);
    for(int i=0;i<L;i++)
    	cout<<H[i]<<' ';
    cout<<'\n';
    for(int i=0;i<K;i++)
    	cout<<W[i]<<' ';
    return 0;
}
