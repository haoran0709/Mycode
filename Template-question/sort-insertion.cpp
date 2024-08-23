//插入排序（从小到大）
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
    for (int i=2;i<=n;i++){//从第2个数开始插入
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){//查找插入位置
            a[j+1]=a[j];//把大于temp的数向后移动一位
            j--;
        }
        a[j+1]=temp;//讲temp填入比它小的数后面
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}