#include <bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e5 + 10;
struct Edge{
    gg u, v, len;
};
vector<Edge>edges;
vector<gg>ufs(maxn);
void init(){iota(ufs.begin(),ufs.end(),0);}
gg findFather(gg x){return x == ufs[x] ? x : ufs[x] = findFather(ufs[x]);}
void unionSets(gg x, gg y) {ufs[findFather(x)] = findFather(y);} //  父节点相连
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
   sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b){
       return a.len < b.len;
   });
   gg res = -1;
   for(gg i =0;i<edges.size() and findFather(1) != findFather(n);i++){
       if(findFather(edges[i].u) != findFather(edges[i].v)){
           res = max(res,edges[i].len);
           unionSets(edges[i].u,edges[i].v);
       }
   }
   cout<<res;
   return 0;
}
