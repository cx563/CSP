#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,k,t,x1,y1,x2,y2,a,b,times=0;
   cin>>ni>>k>>t>>x1>>y1>>x2>>y2;
   set<gg> res1,res2;   //   到过 逗留
   for(gg i=1;i<=ni;i++){
       times=0;  //  记前驱
       for(gg j =1;j<=t;j++){
           cin>>a>>b;
           if(a >= x1 and a <= x2 and b >= y1 and  b <= y2){
                res1.insert(i);
                times++;
                if(times >= k) res2.insert(i);
            }else
                times=0;
       }
   }
   cout<<res1.size()<<"\n"<<res2.size();
   return 0;
}
