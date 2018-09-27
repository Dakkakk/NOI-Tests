#include <cstdio>
#include <algorithm>
#define min(a,b)(a<b?a:b)
double time[1010];
double t;
long S;
double check(int oil){
		if(oil>0&&10>=oil)
			return oil/100.0;
		if(oil>10&&oil<=20)
			return oil/90.0;
		if(oil>20&&oil<=30)
			return oil/80.0;
		if(oil>30&&oil<=40)
			return oil/75.0;
		if(oil>40)
			return oil/70.0;
}
int main()
{
    freopen("car.in","r",stdin);
    freopen("car.out","w",stdout);
    long T;
    scanf("%ld%ld",&S,&T);
    t = T/60.0;
    S /= 10;
 
    for (long i=1;i<=S;i++)
    {
        time[i] = 1e19;
        for (long j=0;j<i;j++)
            time[i] = min(time[i],time[j]+t+check(10*(i-j)));
	}
    printf("%.2lf",time[S]-t);
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
