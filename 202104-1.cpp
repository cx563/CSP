#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, mi, li, t;
   cin >> ni >> mi >> li;
   map<gg,gg>res;
   for (gg i = 0; i < ni;i++){
       for (gg j = 0; j < mi;j++){
           cin >> t;
           res[t]++;
       }
   }
   for (auto i = 0;i<li;i++){
       if(i)
           cout << " ";
       cout << res[i];
   }
       return 0;
}
