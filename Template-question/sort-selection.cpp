//选择排序(从小到大)
//不稳定
//O(n^2)
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        int ith=i;
        for (int j=i+1;j<=n;j++){
            if (a[j]<a[ith]) ith=j;
        }
        swap(a[ith],a[i]);
    }
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" \n"[i==n];
    }
    return 0;
}