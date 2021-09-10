#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node {
    gg type;  //  -1 空行 0 段落 1 项目
    string message;
    node(gg t, string m) { type = t, message = m; }
};
array<node, 2>mess{ node(0,""), node(1,"") };
vector<node>res;
gg w, pre = -1, j, st, ans = 0;
void compute(gg type, gg i){
    gg index = (type ? 4 : 1);
    for(auto& s : res[i].message){
        if(s == ' ' and index == (type ? 4 : 1)) continue;
        if(++index > w){
            ans++;
            index = (type? 4 : 1);
        }
    }
    if(index != (type? 4 : 1)) ans++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> w;
    cin.get();
    while (getline(cin, str)) {
        auto i = find_if(str.begin(), str.end(), [](char s) {return s != ' ';});
        if (i == str.end()) {
            if (pre != -1) res.push_back(mess[pre]);
            if (pre != -1) res.push_back(node(-1, "\n"));
            pre = -1;
        }
        else {
            st = i - str.begin();   //   非空格的起点
            for (j = str.size() - 1; j >= 0; j--) if (str[j] != ' ') break;
            if (pre == 1 and str.size() >= 2 and str[0] == ' ' and str[1] == ' ') {  //  项目信息传递
                str = str.substr(0, j + 1);  //   去掉末尾空格
                if (mess[pre].message == "*") mess[pre].message = str.substr(st);
                else mess[pre].message += (" " + str.substr(st));
            }
            else if (pre == 0 and (str.size() < 2 or str[0] != '*' or str[1] != ' ')) {  // 段落信息传递
                str = str.substr(0, j + 1);  //   去掉末尾空格
                mess[pre].message += (" " + str.substr(st));
            }
            else {  //  新加内容
                if (pre != -1 and mess[pre].message != "") {
                    res.push_back(mess[pre]);
                    mess[pre].message = "";
                }
                if (str.size() >= 2 and str[0] == '*' and str[1] == ' ') {   //  新建一个项目
                    str = str.substr(0, j + 1);  //   去掉末尾空格
                    j = find_if(str.begin() + min(j,(gg)2), str.end(), [](char s) {return s != ' '; }) - str.begin();
                    mess[1].message = str.substr(j);
                    pre = 1;
                }
                else {
                    str = str.substr(0, j + 1);  //   去掉末尾空格
                    mess[0].message = str.substr(st);
                    pre = 0;
                }
            }
        }
    }
    if (pre != -1) res.push_back(mess[pre]);
    for (gg i = 0; i < res.size(); i++) {
        if (res[i].type == -1){
            if (i != res.size() - 1) ans++;
        }
        else {
            if (i and res[i - 1].type != -1 and res[i - 1].type != res[i].type) ans ++;
            if (res[i].type == 0) compute(0,i);
            else compute(1,i);
        }
    }
    cout << ans;
    return 0;
}