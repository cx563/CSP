#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   gg pre = -1,res = -1,t;
   while(n--){
       cin>>t;
       if(pre != -1) res = max(res,abs(pre - t));
       pre = t;
   }
   cout<<res;
   return 0;
}
