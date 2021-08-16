#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg x,y;
    char type;
    bool operator<(const node& a)const {
        return this->x < a.x;
    }
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n,m,a,b,c;
   cin>>n>>m;
   vector<node>v(n);
   for(auto& i : v) cin>>i.x>>i.y>>i.type;  //  直接避免了循环
   while(m--){
       set<node>up,down;
       cin>>a>>b>>c;
       for(auto i : v){
           if(a +b * i.x + c * i.y >0) up.insert(i);
           else down.insert(i);
       }
        char type = up.begin()->type;
        for(auto i : up) if(i.type != type){
            cout<<"No\n";
            goto loop;
        }
        type = down.begin()->type;
        for(auto i : down) if(i.type != type){
            cout<<"No\n";
            goto loop;
        }
        cout<<"Yes\n";
        loop:;    //  程序遇到loop 标签 还是会执行
   }
   return 0;
}
