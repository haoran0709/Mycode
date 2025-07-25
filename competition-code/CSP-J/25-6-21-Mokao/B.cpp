#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
    string s;
    int x,cnt;
}a[N],b[N];
bool cmp1(Node A,Node B){
    return A.s < B.s;
}
bool cmp2(Node A,Node B){
    if (A.x != B.x) return A.x > B.x;
    if (A.cnt != B.cnt) return A.cnt > B.cnt;
    return A.s < B.s;
}
int main(){
    int n,k,c=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].x;
    }
    sort(a+1,a+n+1,cmp1);
    /*
    cout<<"here\n";
    for (int i=1;i<=n;i++){
        cout<<a[i].s<<" "<<a[i].x<<endl;
    }
    */
    for (int i=1;i<=n;i++){
        int nx=i;
        int cnt=0,res=0;
        while(nx<=n && a[i].s==a[nx].s){
            cnt++;
            res+=a[nx].x;
            nx++;
        }
        b[++c].s=a[i].s;
        b[c].x=1.0*res/cnt;
        b[c].cnt=cnt;
        i=nx-1;
    }
    sort(b+1,b+c+1,cmp2);
    /*
    cout<<"here\n";
    cout<<c<<endl;
    for (int i=1;i<=c;i++){
        cout<<b[i].s<<" "<<b[i].x<<" "<<b[i].cnt<<endl;
    }
    */
    for (int i=1;i<=k;i++){
        cout<<b[i].s<<endl;
    }
    return 0;
}
/*
10 3
A 9
B 10+4=14/2=7
C 5+8=13/2=6.5
D 8+6=14/2=7
Q 8
K 7 
Q 9
*/