#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{
    int x,t;
};
queue<Node> q;
int f[N];
int main(){
	int n;
	cin>>n;
    int ans=0;
	for (int i=1;i<=n;i++){
		int t,k;
		cin>>t>>k;
        while(!q.empty()){
            if (t-86400>=q.front().t){
                f[q.front().x]--;
                if (!f[q.front().x]) ans--;
                q.pop();
            }
            else break;
        }
		for (int j=1;j<=k;j++){
			int x;
			cin>>x;
			q.push({x,t});//注意顺序！！！！(因为顺序把自己坑了30分钟检查)
            //printf("f[%d]:%d  !f:%d\n",x,f[x],!f[x]);
            if (!f[x]) ans++;
            f[x]++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 