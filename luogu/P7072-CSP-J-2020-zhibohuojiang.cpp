#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=6e2+5;
int a[N],cnt[M];
int main(){
    int n,w;
    cin>>n>>w;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        int x=max(1,(int)(1.0*i*w/100));
        int res=0;
        for (int j=600;j>=0;j--){
            res+=cnt[j];
            if (res>=x){
                cout<<j<<" ";
                break;
            }
        }
    }
    return 0;
}

//从小数据入手，抓住每个选手成绩不超过600这一条件
//注意下标不要混淆