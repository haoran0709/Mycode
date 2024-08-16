#include <cstdio>
#include <iostream>
using namespace std;
const int N=40+5;
int f[N][N];
//f[i][j]:操作队列剩余i个元素，栈中有j个元素
//记忆化搜索
int F(int a,int b){
    if (f[a][b]) return f[a][b];
    if (a==0) return 1;
    if (b<0) return 0;
    return f[a][b]=F(a-1,b+1)+F(a,b-1);
    //要想好两种操作，一种是入栈，相当于操作队列会少1个元素，而栈中多一个元素。还有一种是出栈，栈中元素减少一个。
}
int main(){
    int n;
    cin>>n;
    cout<<F(n,0)<<endl;
    return 0;
}