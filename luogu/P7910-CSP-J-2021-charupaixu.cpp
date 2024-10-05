#include <bits/stdc++.h>
using namespace std;
const int N=8e3+5;
int n,q,pos[N];
struct Node{
	int p,x;
}a[N];
bool cmp(Node A,Node B){
	if (A.x != B.x) return A.x < B.x;
	return A.p < B.p;
}
void MAIN(){
	int op,x,v;
	cin>>op;
	if (op==1){
		cin>>x>>v;
		int now=1;
		while(a[now].p!=x) now++;
		a[now].x=v;
		while(now-1>=1 && cmp(a[now],a[now-1])){
			swap(pos[a[now].p],pos[a[now-1].p]);
			swap(a[now],a[now-1]);
			now--;
		}
		while(now+1<=n && cmp(a[now+1],a[now])){
			swap(pos[a[now].p],pos[a[now+1].p]);
			swap(a[now],a[now+1]);
			now++;
		}
	}
	else{
		cin>>x;
		cout<<pos[x]<<endl;
	}
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		pos[a[i].p]=i;
	}
	while(q--) MAIN();
	return 0;
}
/*
关注小数据
操作1：O(n)
操作2：o(1)
记pos[x]表示原来在x位置，排序后在pos[x]位置
错因：
1.细节的处理，要防止数组下标越界
2.while循环判断出错，应使用cmp函数简化判断避免出错
*/