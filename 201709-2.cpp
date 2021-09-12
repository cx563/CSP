#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    char flag ;  //  r 还 g 取
    gg num;  //  钥匙编号
    gg time;
    bool operator<(const node& b) const{
        return tie(b.time,this->flag,b.num) < tie(this->time, b.flag,this->num);
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg ni, ki, w, s, c;
   cin>>ni>>ki;
   vector<gg>ans(ni + 1);
   priority_queue<node>q;
   while(ki--){
       cin>>w>>s>>c;
       q.push({'g',w,s});
       q.push({'r',w,s + c});
   }
   iota(ans.begin(),ans.end(),0);
   while(not q.empty()){
       node t = q.top();
       q.pop();
       if(t.flag == 'g'){
           for(gg i = 1;i<=ni;i++){
               if(ans[i] == t.num) {
                   ans[i] = -1;
               }
           }
       }else{
           for(gg i =1;i<=ni;i++){
               if(ans[i] == -1){
                   ans[i] = t.num;
                   break;
               }
           }
       }
   }
   for(gg i =1;i<=ni;i++) cout<<ans[i]<<" ";
   return 0;
}
