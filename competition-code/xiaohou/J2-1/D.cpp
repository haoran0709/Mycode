#include <bits/stdc++.h>
using namespace std;
const int N=2000+5;
const int M=40;
bool f[N][N];//i~j的区间是否为回文
char c[M];
int v[M];
bool check(string s,int n){
	memset(f,false,sizeof f);
	for (int i=1;i<=n;i++) f[i][i]=true;
	for (int i=1;i<n;i++) if (s[i]==s[i+1]) f[i][i+1]=true;
	for (int l=3;l<=n;l++){
		for (int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			f[i][j]=(s[i]==s[j]) && (f[i+1][j-1]);
		}
	}
}
int main() {
	int n,m;
	cin>>m;
	string s;
	cin>>s;
	n=s.length();
	s=' '+s;
	for (int i=1;i<=m;i++) cin>>c[i]>>v[i];
	for (int i=1;i<=m;i++){
		
	}
    return 0;
}