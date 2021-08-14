#include <bits/stdc++.h>
using namespace std;
using gg = long long;
unordered_map<string, gg> mp;//  全局图
gg computenum(const string& s,gg& start){  // start是数字的开头 显然 计算过后的start 指向的不再是数字
    gg res = 0;   //  初值为0
    while(start<s.size() and isdigit(s[start])){
        res = res * 10 + (s[start] - '0');
        start++;
    }
    return (res == 0 ? 1 : res);   //  总系数不能是0啊！
}

void deal(const string& s,gg e){  // 开始考虑单个字符的计算  e 是这个表达式的总系数  快慢指针处理字符串
    gg i = 0, j;  // i是处理字符的起点
    e *= computenum(s, i);   // 计算总系数
    while(i < s.size()){
        if(isupper(s[i])){  // 确定是一个元素了
            if(i+1 < s.size() and islower(s[i+1])){     // 双原子元素
                gg k = i;
                i += 2;  // 指向元素后面的数字
                mp[s.substr(k, 2)] += e * computenum(s,i);   // 此时 i以及指向了下一个判断位了
            }else{   // 单原子元素
                gg k = i;
                i += 1;
                mp[s.substr(k, 1)] += e * computenum(s, i);
            }
        }else{    // 不是元素 开始考虑括号    其实 括号的内部 就是一个结果相同的表达式
            gg left = i, right = i + 1, num = 1; // 开始寻找括号的右边界   处理区间即为[left+1,right-1]
            while(num!=0 and right < s.size()){
                if(s[right] == '(')
                    num++;
                else if(s[right] == ')')
                    num--;
                right++;
            }
            deal(s.substr(left + 1, right - left - 2), e * computenum(s, right));
            i = right;
        }
    }
}

void compute(const string& s,gg exp){   // 把整个表达式进行了分割
    gg i, j;
    for (i = 0; i < s.size();){
        j = s.find('+', i);
        if(j == string::npos){
            deal(s.substr(i),exp);
            i = s.size();
        }else{
            deal(s.substr(i, j - i),exp); // 第二参数是子串的长度
            i = j + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    string s;
    while (ni--){
        cin >> s; //   要处理的化学方程式
        auto j = s.find('=');
        compute(s.substr(0, j), 1); // 计算左边
        compute(s.substr(j + 1),-1);   //  计算右边  右边要减去 参数是 -1 
        for(auto i : mp){
           if(i.second !=0){
               cout << "N\n";
               goto loop;
           }
        }
        cout << "Y\n";
        loop:;
        mp.clear();   // 图一定要清空！
   }
   return 0;
}
