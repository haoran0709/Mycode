//计数排序（从小到大）
//稳定
//O(n+k)  //输入n个在0~k之间的整数
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e6+5;
const int M=1e6+5;//a[i]的所有元素均不超过M
int a[N],box[M];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) box[a[i]]++;
    int cnt=0;
    for (int i=0;i<M;i++){
        for (int j=1;j<=box[i];j++){
            a[++cnt]=i;
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}