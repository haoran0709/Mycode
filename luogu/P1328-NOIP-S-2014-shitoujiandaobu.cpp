#include <bits/stdc++.h>
using namespace std;
const int N=200+5;
int a[N],b[N];
const int f[5][5]={
	{2,3,1,1,3},
	{1,2,3,1,3},
	{3,1,2,3,1},
	{3,3,1,2,1},
	{1,1,3,3,2}
};
int main(){
	int n,la,lb,ans_a=0,ans_b=0;
	cin>>n;
	cin>>la>>lb;
	for (int i=0;i<la;i++) cin>>a[i];
	for (int i=0;i<lb;i++) cin>>b[i];
	int nowa=0,nowb=0;
	for (int i=1;i<=n;i++){
		int x=f[a[nowa]][b[nowb]];
		if (x==1) ans_a++;
		else if (x==3) ans_b++;
		nowa=(nowa+1)%la;
		nowb=(nowb+1)%lb;
	}
	cout<<ans_a<<" "<<ans_b<<endl;
	return 0;
}
/*
模拟
1.周期性
数组下标从0开始，每次+1，求模即可。
2.胜1分，平局/输0分
使用二维数组优化判断过程（使用打表，将所有情况的输赢情况记录到二维数组中）
*/