/*#include <bits/stdc++.h>   //  对比和大佬的差距 5555
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<pair<gg, gg>> st;
   map<gg,gg> res; //  得分表
   map<gg, gg> leftm;
   map<gg, gg> rightm;
   gg ni, a, b;
   cin >> ni;
   while(ni--){
      cin >> a >> b;
      st.push_back({a, b});
   }
   sort(st.begin(), st.end());
   gg left = 0;
   gg last = -1;
   for(auto i : st){   //  统计每个元素左侧 0 的个数
      if(i.first != last)   // 一定注意这里 元素相同的 均不应在这里判定
         leftm[i.first] = left;
      if(i.second == 0){
         left++;
      }
      last = i.first;
   }
   gg right = 0;
   for (auto i = st.rbegin(); i != st.rend();i++){
      rightm[i->first] = right;
      if(i->second == 1) {
         rightm[i->first]++;
         right++;
      }
   }
   for(auto& i : leftm){
      i.second += rightm[i.first];
   }
   res = leftm;
   gg ans1 = -1;
   gg ans2 = 0;
   for(auto i : res){
      if(i.second >= ans1){
         ans1 = i.second;
         ans2 = i.first;
      }
   }
   cout << ans2;
   return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<gg, array<gg, 2>> r;
    gg mi, y, res;
    cin >> mi;
    gg ki = 0;
    for (gg i = 0; i < mi; ++i) {
        cin >> y >> res;
        r[y][res]++;
        if(res)
           ki++;
    }

    gg p0 = 0, p1 = 0, ans = 0, c = 0;
    for (auto& i : r) {
        gg t = p0 + ki - p1;
        if (t >= c) {
            c = t;
            ans = i.first;
        }
        p0 += i.second[0];
        p1 += i.second[1];
    }
    cout << ans << "\n";
    return 0;
}
