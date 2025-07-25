#include <bits/stdc++.h>
using namespace std;
double y,w,m;
bool check(double x){
    double l=1.0*x/1000;
    double res=0;
    for (int i=1;i<=m;i++){
        res+=w-(y-res)*l;
    }
    return res<=y;
}
int main(){
    cin>>y>>w>>m;
    double l=0,r=300000;
    while(r-l>1e-6){
        double mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }
    printf("%.1lf\n",l/10.0);
    return 0;
}