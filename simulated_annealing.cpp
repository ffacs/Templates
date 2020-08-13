#include <bits/stdc++.h>
using namespace std;
inline double cal(double x) {
	double ans=0;
	return ans;
}
inline void SA() {
	double t=2000;//初始温度
	double delta=0.993;//降温系数
	double ans=cal(0),ansx=0;
	while(t>1e-14) {
		double newx=ansx+(rand()*2-RAND_MAX)*t;
		double newans=cal(newx);
		double DE=newans-ans;
		if(DE<0)  //如果新ans更小
			ans=newans,ansx=newx;
		else if(exp(-DE/t)*RAND_MAX>rand()) //否则以概率移动到新位置
			ansx=newx;
		t=t*delta;
	}
}
int main() {    
    return 0;
}