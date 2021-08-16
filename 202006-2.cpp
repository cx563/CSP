#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>a1,a2;    //  感觉用数组映射会导致运行错误 array vector 也一样 只能用哈希图  map 不会受到空间的限制
   gg n,a,b,index,value;       //用数组映射导致运行错误的原因很简单  比如 有index值为1e8 把1e8做下标 那数组会直接开辟1e8的空间 但 1e8 做map下标 只会增加一个键值对
                            //  因此 如果映射的键是连续的 如何 1 2 3 4 5 6 可以考虑数组 但如果是不连续的 数组便会造成空间浪费 大部分情况下 两者均可 但像 1e8 这种 数组显然就不合适了
                            //  map 也是存储关键的信息 如果真1e8 个键值对 map 估计也会导致运行错误    故 存储关键的信息 会产生答案的信息
   cin>>n>>a>>b;   //  array 的长度必须是一个常量
   while(a--){
       cin>>index>>value;
       a1[index] = value;
   } 
   while(b--){
       cin>>index>>value;
       a2[index] = value; 
   }
   gg res=0;
   for(auto i : a1) res += i.second * a2[i.first];    //   关键在这里 map中只包含了 第一个向量中确定为非零的元素 大幅缩小了枚举规模
   cout<<res;
   return 0;
}
