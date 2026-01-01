#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>s="YYNY";
    int n=s.size();
    int bt=0;
    int minp=0;
    int p=0;
    for(int i=0;i<n;i++){
      p+=s[i]=='Y'?-1:1;
      if(p<minp){
        bt=i+1;
        minp=p;
      }
    }
return minp;
}
