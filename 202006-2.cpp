#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   unordered_map<gg,gg>a1,a2;    //  感觉用数组映射会导致运行错误 array vector 也一样 只能用哈希图  map 不会受到空间的限制
   gg n,a,b,index,value;
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
