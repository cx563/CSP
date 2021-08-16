#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   map<gg,gg>mp;
   gg n,m,a,b;
   cin>>n>>m;
   gg total =0,k=0,p=-1;
   for(gg i=1;i<=n;i++){
       cin>>a;
       for(gg j=1;j<=m;j++){
           cin>>b;
           a+=b;
           mp[i] += (-b);
       }
       total += a;
   }
   for(auto i : mp){
       if(i.second > p){
            p= i.second;
            k = i.first;
       }
   }
   cout<<total<<" "<<k<<" "<<p;
   return 0;
}
