//冒泡排序(从小到大)
//稳定
//O(n^2)
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n-i;j++){
            if (a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}