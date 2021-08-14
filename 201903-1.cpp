#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{ 
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni;
   cin >> ni;
   vector<gg> v(ni);
   for(auto& i : v)
       cin >> i;
   sort(v.begin(), v.end(),greater<gg>());
   if(v.size()%2){
       cout << v[0] << " " << v[v.size() / 2] << " " << v[v.size()-1];
   }else if(v.size() %2 ==0 and (v[v.size() / 2] + v[v.size() / 2 - 1]) % 2 ==0){
       cout << v[0] << " " << (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2 << " " << v[v.size() - 1];
   }else{
       cout << v[0] << " " << fixed << setprecision(1) << (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0 << " " << setprecision(0) << v[v.size()-1];
   }
   return 0;
}
