#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct IP{
    string owner;
    gg ed;
};
vector<IP>mp(1);   //  初始长度为1
vector<gg>flag(1);   //  下标是 ip地址
gg N, t, tmax, tmin, ni, nowtime, endtime, ip;
string hname, from, to, type; //   hname 服务器名字
bool judge(){
    if(type =="DIS" and to =="*") return true;
    if(type == "REQ" and to != "*") return true;
    return false;
}
void brush(){   // 更新状态
    for(gg i=1;i<=N;i++){
        if(mp[i].ed <= nowtime){
            mp[i].ed =0;    //   过期时间清零
            if(flag[i] ==1) {
                flag[i] = 0;   //  待分配的超时 转换为未分配
                mp[i].owner ="";
            }else if(flag[i] == 2){
                flag[i] =3;  //  占用的超时 转换为 过期
            }
        }
    }
}
gg findip(){
    for(gg i =1;i<=N;i++) if(mp[i].owner == from) return i;
    for(gg i =1;i<=N;i++) if(flag[i] == 0) return i;
    for(gg i =1;i<=N;i++) if(flag[i] == 3) return i;
    return 0;
}
gg findtime(){
    if(endtime == 0) return nowtime + t;
    if(endtime < nowtime + tmin) return nowtime + tmin;
    if(endtime > nowtime + tmax) return nowtime + tmax;
    return endtime;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> t >> tmax >> tmin >> hname;
   cin >> ni;
   for (gg i = 1; i <= N;i++){
       mp.push_back({"",0});
       flag.push_back(0);  //  均未分配
   }
    while (ni--){
       cin >> nowtime >> from >> to >> type >> ip >> endtime;
       if(not judge()) continue;
       brush();
       if(type == "DIS"){
           gg rip = findip();
           if(not rip) continue;
           gg time = findtime();
           flag[rip] = 1;   // 标志为 待分配
           mp[rip].owner = from;
           mp[rip].ed = time;
           cout<<hname<<" "<<from <<" "<<"OFR"<<" "<<rip<<" "<<time<<"\n";
       }else{
           if(to != hname) {   //  我不是目标主机
                for(gg i =1;i<=N;i++) {
                    if(mp[i].owner == from and (flag[i] == 1)) {
                        flag[i] =0;
                        mp[i].ed =0;  //  时间置0
                        mp[i].owner = "";  //  所有者为空
                    }
                }
           }else{
               if(ip >N or mp[ip].owner != from){   //   短路 确保不会越界
                   cout<<hname<<" "<<from<<" "<<"NAK"<<" "<<ip<<" "<<0<<"\n";
               }else{
                   gg time = findtime();
                   mp[ip].ed = time;
                   flag[ip] = 2;   //  占用
                   cout<<hname<<" "<<from<<" "<<"ACK"<<" "<<ip<<" "<<time<<"\n";
               }
           }
       }
    }
   return 0;
}