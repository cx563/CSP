#include <bits/stdc++.h>
using namespace std;
using gg = long long;
gg compute(gg a, gg b,char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == 'x') return a*b;
    if(c == '/') return a/b;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   gg n;
   cin>>n;
   string s;
   unordered_map<char,gg>um{{'+',0},{'-',0},{'x',1},{'/',1}};   //优先级
   while(n--){
       cin>>s;
       stack<char>op;  //  操作符栈
       stack<gg>num;   //  操作数栈
       for(auto i : s){
           if(isdigit(i)) num.push(i - '0');
           else {
               while(not op.empty() and um[op.top()] >= um[i]){  //  进行计算
                    gg a = num.top();
                    num.pop();
                    gg b = num.top();
                    num.pop();
                    num.push(compute(b,a,op.top()));
                    op.pop();
               }
               op.push(i);
           }
       }
       while(not op.empty()){
            gg a = num.top();
            num.pop();
            gg b = num.top();
            num.pop();
            num.push(compute(b,a,op.top()));
            op.pop();
       }
       cout<< (num.top() == 24 ? "Yes\n" : "No\n");
   }
   return 0;
}
