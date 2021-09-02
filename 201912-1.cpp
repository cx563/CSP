#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,num = 1;
   cin>>n;
   vector<gg>res(4,0);
   while(n){
       auto s = to_string(num);
       if(num % 7 == 0 or find(s.begin(),s.end(),'7') != s.end()){
           res[(num - 1) % 4]++;
       }else n--;
       num++;
   }
   for(auto i : res) cout<<i<<"\n";
   return 0;
}
