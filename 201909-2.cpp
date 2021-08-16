#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,res=0,num=0,tmp,left;
   unordered_map<gg,bool>um;   //  好思路 直接打表 避免记标志
   cin>>n;
   for(gg i=0;i<n;i++){
       cin>>m;
       for(gg j=0;j<m;j++){
           cin>>tmp;
           if(tmp >0){
               if(j and tmp < left) um[i] = true;
               left = tmp; 
           }else left += tmp;
       }
       res+=left;
   }
   num = um.size();
   left =0;
   for(gg i=0;i<n;i++){
       if(um[i] and um[(i-1+n)%n] and um[(i+1)%n]) left++;
   }
   cout<<res<<" "<<num<<" "<<left;
   return 0;
}
