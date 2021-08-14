#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, a, b, res = 0;
   cin>>ni;
   while(ni--){
       cin >> a >> b;
       res += a * b;
   }
   cout << (res < 0 ? 0 : res);
   return 0;
}
