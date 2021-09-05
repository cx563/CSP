#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1005;
struct Edge{
    gg u, v,cost;
};
vector<Edge>edges;
vector<gg>ufs(maxn);
gg findFather(gg x){
    return x == ufs[x] ? x : ufs[x] = findFather(ufs[x]);
}
void unionSets(gg x, gg y){
    ufs[findFather(x)] = findFather(y);
}
void init(){
    iota(ufs.begin(),ufs.end(),0);
}
gg Kruskal(){
    gg res = 0;
    sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b){
        return a.cost < b.cost;
    });
    for(auto& e : edges){
        if(findFather(e.u) != findFather(e.v)){
            res += e.cost;
            unionSets(e.u,e.v);
        }
    }
    return res;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   init();
   gg n,m,u,v,c;
   cin>>n>>m;
   while(m--){
       cin>>u>>v>>c;
       edges.push_back({u,v,c});
   }
   cout<<Kruskal();
   return 0;
}
