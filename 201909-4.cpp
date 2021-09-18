#include<bits/stdc++.h>
using namespace std;
using gg = long long;
const gg maxn = 1e9;
struct commodity{
    gg num, score;    //  num使用哈希的思想 将数 mn 看作 1e9 进制的数  将其统一转换为10进制数计算而来   精妙的思路
    bool operator<(const commodity& b) const{
       return tie(b.score,this->num) < tie(this->score,b.num);
    }
};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<commodity>s;   //  存储结构
    unordered_map<gg,set<commodity>::iterator>um;  //  方便删除 维护每个商品在set中的位置
    gg mi, ni, type, number, score, num, tt;   // 商品的类 每类中商品的个数
    cin>>mi>>ni;
    for(gg i =0;i<ni;i++){    //  初始化
        cin>>number>>score;
        for(gg j =0;j<mi;j++){
            auto t = s.insert({j * maxn + number,score});
            if(t.second) um[(*(t.first)).num] = t.first;
        }
    }
    cin>>num;
    while(num--){
        cin>>type;
        if(type == 1){   //  增加操作
            cin>>tt>>number>>score;
            auto t = s.insert({tt * maxn + number,score});
            if(t.second) um[(*(t.first)).num] = t.first;
        }else if(type == 2){   //  删除操作
            cin>>tt>>number;
            if(um.count(tt * maxn + number)){
                s.erase(*(um[tt * maxn + number]));
                um.erase(tt * maxn + number);
            }
        }else{
            cin>>number;  //  商品最大的数量
            vector<gg>lim(mi);  //  每个类个数的限制
            for(gg i =0;i<mi;i++) cin>>lim[i];
            map<gg,vector<gg>>res;   //  存储结构
            gg index = 0;   //  选中商品的个数
            for(auto& t : s){
                if(res[t.num / maxn].size() >= lim[t.num / maxn]) continue;
                res[t.num / maxn].push_back(t.num % maxn);
                index++;
                if(index == number) break;
            }
            for(gg i =0;i<mi;i++){
                if(res[i].empty()) cout<<-1<<"\n";
                else{
                    //sort(res[i].begin(),res[i].end());
                    for(auto& j : res[i]) cout<<j<<" ";
                    cout<<"\n";
                }
            }
        }
    }
    return 0;
}