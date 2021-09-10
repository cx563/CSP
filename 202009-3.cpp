#include <bits/stdc++.h>
using namespace std;
using gg = long long;
struct node {
    vector<gg>in;  //  入度序列
    vector<gg>out;  //  邻接表
    string op;
};
gg compute(string op, vector<gg>&parm) {
    if (op == "NOT") return !parm[0];
    if (op == "AND") {
        gg res = parm[0] & parm[1];
        for (gg i = 2; i < parm.size(); i++) res &= parm[i];
        return res;
    }
    if (op == "OR") {
        gg res = parm[0] | parm[1];
        for (gg i = 2; i < parm.size(); i++) res |= parm[i];
        return res;
    }
    if (op == "XOR") {
        gg res = parm[0] ^ parm[1];
        for (gg i = 2; i < parm.size(); i++) res ^= parm[i];
        return res;
    }
    if (op == "NAND") return !compute("AND",parm);
    if (op == "NOR") return !compute("OR",parm);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg q, m, n, k, s, num, res;
    string str;
    cin >> q;
    while (q--) {
        cin >> m >> n;  //  m 是电路输入的个数 n 是电路器件的数量
        vector<node>adj(n + m + 1);
        for (gg i = 1; i <= n; i++) {
            cin >> adj[i].op >> k;
            while (k--) {
                cin >> str;
                adj[i].in.push_back(stoll(str.substr(1)) + (str[0] == 'I' ? n : 0));
                adj[stoll(str.substr(1)) + (str[0] == 'I' ? n : 0)].out.push_back(i);
            }
        }
        cin >> s;
        vector<vector<gg>>parameter(s, vector<gg>(m));
        for (auto& i : parameter) {
            for (auto& j : i) cin >> j;
        }
        for (gg i = 0; i < s; i++) {
            unordered_map<gg, gg>um, indrgee;  //  维护每个节点的计算结果, 入度值
            for (gg j = n + 1, jj = 0; j < n + m + 1; j++, jj++) um[j] = parameter[i][jj];
            cin >> num;
            vector<gg>quary(num);
            for (auto& j : quary) cin >> j;
            queue<gg>q;  //  节点下标入队
            for (gg j = 1; j <= m + n; j++) {
                if (adj[j].in.size() == 0) q.push(j);
                indrgee[j] = adj[j].in.size();
            }
            while (not q.empty()) {
                gg top = q.front();
                q.pop();
                if (top <= n) {  //  进行计算
                    vector<gg>parm;
                    for (auto& j : adj[top].in) parm.push_back(um[j]);
                    um[top] = compute(adj[top].op, parm);
                }
                for (auto& j : adj[top].out) {
                    --indrgee[j];
                    if (indrgee[j] == 0) q.push(j);
                }
            }
            if (um.size() != m + n) {
                cout << "LOOP\n";
                goto loop;
            }
            for (auto& j : quary) cout << um[j] << " ";
            cout << "\n";
        }
    loop:;
    }
    return 0;
}