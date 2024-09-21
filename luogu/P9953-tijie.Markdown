# 贪心
解决思路：  
首先由于题目不保证输入的位置是有序的，因此我们要先排序。  
接着计算传染半径r，经过分析我们不难发现传染半径r必须要小于相邻的一头健康牛和一头不健康牛之间的距离，因为如果超过那么这两头牛都应该是不健康的。  
那么我们就应该在相邻的健康牛和不健康牛之间的距离中找出最小的。这个值就是传染半斤r  
最后我们只需要考虑每一头不健康的牛，如果前一头牛也不健康，并且这两头牛的距离不超过r，则说明这头牛不健康是被前一头牛感染的。反之，这头牛就是感染源。
### 代码如下：

```cpp
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+5;
struct Cow{
    int x,f;
}a[N];
bool cmp(Cow A,Cow B){
    return A.x < B.x;
}
int main(){
    int n,ans=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].f;
    sort(a+1,a+n+1,cmp);
    int r=1e9;
    for (int i=1;i<=n;i++){//确定r
        if (i+1<=n && a[i].f==1 && a[i+1].f==0) r=min(r,a[i+1].x-a[i].x);
        if (i+1<=n && a[i].f==0 && a[i+1].f==1) r=min(r,a[i+1].x-a[i].x);
    }
    for (int i=1;i<=n;i++){//计算答案
        if (a[i].f==1 && a[i-1].f==1 && a[i-1].x+r>a[i].x) continue;
        if (a[i].f==1) ans++; 
    }
    cout<<ans<<endl;
    return 0;
}
```