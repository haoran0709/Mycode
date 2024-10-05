#include <bits/stdc++.h>
using namespace std;
int a[15];
bool vis[15];
void DFS(int step){
    if (step>9){
        int A=0,B=0,C=0;
        A=a[1]*100+a[2]*10+a[3];
        B=a[4]*100+a[5]*10+a[6];
        C=a[7]*100+a[8]*10+a[9];
        if (2*A==B && 3*A==C){
            cout<<A<<" "<<B<<" "<<C<<endl;
        }
        return ;
    }
    for (int i=1;i<=9;i++){
        if (!vis[i]){
            vis[i]=true;
            a[step]=i;
            DFS(step+1);
            vis[i]=false;
        }
    }
}
int main(){
    DFS(1);
    return 0;
}