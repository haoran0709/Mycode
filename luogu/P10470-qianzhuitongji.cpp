#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<string,int> cnt;
int main(){
	int n,k;
	cin>>n>>k;
	string s;
	getline(cin,s);
	for (int i=1;i<=n;i++){
		getline(cin,s);
		cnt[s]++;
	}
	for (int i=1;i<=k;i++){
		getline(cin,s);
		int ans=0;
		string x;
		for (int i=0;i<s.length();i++){
			x=x+s[i];
			ans=ans+cnt[x];
		}
		cout<<ans<<endl; 
	}
	return 0;
}