#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node{
    gg x, y;
    gg layer;
};
gg maxn = 1005;
gg n,m,k,d,a,b,c;
vector<vector<gg>>graph(maxn,vector<gg>(maxn));  //  BFS 图 标记哪些位置不能走
vector<vector<bool>>inq(maxn,vector<bool>(maxn));
gg dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};  //  方向数组
bool judge(gg x, gg y){
    if(x <= 0 or x > n or y <= 0 or y > n) return false;
    if(inq[x][y] or graph[x][y] == -1) return false;
    return true;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k>>d;
   queue<node>q;
   while(m--){
       cin>>a>>b;
       q.push({a,b,0});
       inq[a][b] = true;
   }
   while(k--){
       cin>>a>>b>>c;
       graph[a][b] += c;
   }
   while(d--){
       cin>>a>>b;
       graph[a][b] = -1;
   }
   gg res = 0;
   while(not q.empty()){
       node top = q.front();
       q.pop();
       if(graph[top.x][top.y] > 0) res += graph[top.x][top.y] * top.layer;
       for(gg i=0;i<4;i++){
           gg x = top.x + dir[i][0], y = top.y + dir[i][1];
           if(judge(x,y)){
               q.push({x,y,top.layer + 1});
               inq[x][y] = true;
           }
       }
   }
   cout<<res;
   return 0;
}
