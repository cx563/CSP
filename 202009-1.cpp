#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg id;
    gg x,y;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni,xi,yi,a,b;
   cin>>ni>>xi>>yi;
   vector<node> v;
   for(gg i=1;i<=ni;i++){
       cin>>a>>b;
       v.push_back({i,a,b});
   } 
   sort(v.begin(),v.end(),[xi,yi] (node& a,node& b){
       double r1 = pow(xi-a.x,2)+pow(yi-a.y,2);
       double r2 = pow(xi-b.x,2)+pow(yi-b.y,2);
       return tie(r1,a.id) < tie(r2,b.id);    //  tie内部必须是变量
   });
   for(gg i=0;i<3;i++) cout<<v[i].id<<"\n";
   return 0;
}
