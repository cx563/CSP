#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<gg,vector<array<gg,2>>>um;  //   存储结构 0 先手 1 后手 对应 first - 英雄血量 second - 随从 攻击0 + 血量1
void init(){
    um[0].push_back({0,30});  //   开始 英雄的信息
    um[1].push_back({0,30});
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   init();
   gg n,pos,att,heal,attacker,defender,player = 0;
   cin>>n;
   string s;
   while(n--){
       cin>>s;
       if(s == "summon"){   //  召唤
            cin>>pos>>att>>heal;
            um[player].insert(um[player].begin() + pos,{att,heal});
       }else if(s == "attack"){
           cin>>attacker>>defender;
           um[1 - player][defender][1] -= um[player][attacker][0];
           um[player][attacker][1] -= um[1 - player][defender][0];
           if(defender and um[1 - player][defender][1] <= 0) um[1 - player].erase(um[1 - player].begin() + defender);
           if(um[player][attacker][1] <= 0) um[player].erase(um[player].begin() + attacker);
       }else if(s == "end"){
           player = 1 - player;   //  更替角色
       }
   }
   cout<<(um[0][0][1] > 0  and um[1][0][1] > 0 ? 0 : um[0][0][1] <= 0 ? -1 : 1)<<"\n";
   for(gg i = 0;i<=1;i++){
       cout<<um[i][0][1]<<"\n";
       cout<<um[i].size() - 1;
       gg j = 1;
       while(j < um[i].size()){
           cout<<" "<<um[i][j][1];
           j++;
       }
       cout<<"\n";
   }
   return 0;
}
