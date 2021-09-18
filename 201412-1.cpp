#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<gg,gg>um;
    gg ni, ai;
    cin>>ni;
    while(ni--){
        cin>>ai;
        cout<<++um[ai]<<" ";
    }
    return 0;
}