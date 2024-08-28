#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=15e3+5;
int a[N],b[N];//b数组用于计算a数组中相邻两个元素之间点坐标的个数
bool cmp(int A,int B){
    return A > B;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        b[i]=a[i+1]-a[i]-1;//易错，想不清楚可画图
    }
    //画一个线段图
    //l_l_l_l_l_l
    //1 2 3 4 5 6
    //假设2号点和6号点是图中的坑
    //那么这两个点之间点坐标的个数为3
    //列式为：6-2-1=3
    //由此可知b[i]=a[i+1]-a[i]-1;
    int ans=a[n]-a[1]+1;
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=m-1;i++){
        ans-=b[i];
    }
    cout<<ans<<endl;
    return 0;
}