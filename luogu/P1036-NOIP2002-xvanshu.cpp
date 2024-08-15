#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=25;
int a[N],cnt,n,k;
bool f[N];
bool isPrime(int x){
	if (x==1) return false;
	for (int i=2;i*i<=x;i++){
		if (x%i==0) return false;
	}
	return true;
} 
void DFS(int step,int ans,int o){
	if (step>n){
		if (o==k){
			if (isPrime(ans)) cnt++;
		}
		return ;
	}
	DFS(step+1,ans+a[step],o+1);
	DFS(step+1,ans,o);
} 
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	DFS(1,0,0);
	cout<<cnt<<endl;
	return 0;
}