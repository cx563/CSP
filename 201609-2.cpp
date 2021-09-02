#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<gg>train(20,5);  //  20排 每一排均剩余 5 个座位
   gg n,ins;
   cin>>n;
   while(n--){
       cin>>ins;
       auto j = find_if(train.begin(),train.end(),[&train,ins](gg a){
           return a >= ins;
       });
       if(j == train.end()){
           for(gg i = 0;i < 20;i++){
               if(train[i] >= ins){
                   for(gg j = i * 5 + 1 + 5 - train[i], cont = ins;cont > 0;j++,cont--) cout<<j<<" ";
                   cout<<"\n";
                   train[i] -= ins;
                   break;
               }else{
                   for(gg j = i * 5 + 1 + 5 - train[i];j <= (i + 1) * 5;j++) cout<<j<<" ";
                   ins -= train[i];
                   train[i] = 0;
               }
           }
       }else{
           gg pos = j - train.begin();  //  排号
           for(gg i = pos * 5 + 1 + 5 - train[pos], cont = ins;cont > 0;i++,cont--) cout<<i<<" ";
           cout<<"\n";
           train[pos] -= ins;
       }
   }
   return 0;
}
