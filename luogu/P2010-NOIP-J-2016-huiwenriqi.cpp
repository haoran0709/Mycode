#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int D[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isR(int y){
	return y%4==0 && y%100!=0 || y%400==0;
}
bool check(int x){
	int y=x/10000;
	int m=x/100%100;
	int d=x%100;
	if (m==0 || m>12 || d==0) return false;
	if (isR(y) && m==2) return d<=29;
	return d<=D[m];
}
int main(){
	int d1,d2,ans=0;
	cin>>d1>>d2;
	for (int i=d1/10000;i<=d2/10000;i++){
		int x=i,y=i;
		do{
			x=x*10+y%10;
			y/=10;
		}while(y);
		if (check(x) && x>=d1 && x<=d2) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
1.日期真实存在->判断合法日期->O(1)
2.判断回文->正序=逆序->O(8)(O(8*10^8)危险)->构造回文(根据前4位年份)
*/
