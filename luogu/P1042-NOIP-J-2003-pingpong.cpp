#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    char c;
    int cnta1=0,cntb1=0,cnta2=0,cntb2=0;
    while(cin>>c){
        if (c=='E') break;
        s=s+c;
    }
    s=' '+s;
    for (int i=1;i<s.length();i++){
        if (s[i]=='W') cnta1++;
        else cntb1++;
        if ((cnta1>10 || cntb1>10) && abs(cnta1-cntb1)>=2){
            printf("%d:%d\n",cnta1,cntb1);
            cnta1=cntb1=0;
        }
    }
    printf("%d:%d\n",cnta1,cntb1);
    cout<<endl;
    for (int i=1;i<s.length();i++){
        if (s[i]=='W') cnta2++;
        else cntb2++;
        if ((cnta2>20 || cntb2>20) && abs(cnta2-cntb2)>=2){
            printf("%d:%d\n",cnta2,cntb2);
            cnta2=cntb2=0;
        }
    }
    printf("%d:%d\n",cnta2,cntb2);
    return 0;
}