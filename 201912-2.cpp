#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   map<pair<gg, gg>, bool> mp;
   map<pair<gg,gg>,array<gg,2>>mpi;
   gg ni;
   cin >> ni;
   gg a, b;
   while(ni--){
       cin >> a >> b;
       mp[{a, b}] = true;
       mpi[{a, b}] = {0, 0};
   }
   for(auto& i : mpi){
       if(mp[{i.first.first,i.first.second+1}] and mp[{i.first.first,i.first.second-1}] and mp[{i.first.first-1,i.first.second}] and mp[{i.first.first+1,i.first.second}]){
           i.second[0] = 1;
           if(mp[{i.first.first-1,i.first.second+1}])
               i.second[1]++;
            if(mp[{i.first.first+1,i.first.second+1}])
                i.second[1]++;
            if(mp[{i.first.first-1,i.first.second-1}])
                i.second[1]++;
            if(mp[{i.first.first+1,i.first.second-1}])
                i.second[1]++;
       }
   }
   array<gg, 5> res;
   fill(res.begin(), res.end(), 0);   //  记得初始化
   for(auto i : mpi){
       if(i.second[0]){
           res[i.second[1]]++;
       }
   }
   for(auto i : res)
       cout << i << "\n";
   return 0;
}
