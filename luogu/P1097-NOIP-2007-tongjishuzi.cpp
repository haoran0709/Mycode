#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int,int> cnt;
int main(){
	int n,x;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		cnt[x]++;
	}
	for (auto p:cnt){
		cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}