#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, li, ri, ti;
    cin >> ni >> li >> ri >> ti;
    vector<vector<gg>> v(ni, vector<gg>(ni + 1));
    for (auto &i : v)
    {
        for (gg j = 1; j <= ni; j++)
        {
            cin >> i[j];
        }
   }
    for(auto& i : v){
        for (gg j = 1; j <= ni;j++){    //  前缀和
            i[j] = i[j - 1] + i[j];
        }
    }
    gg tmp = 0;
    gg res = 0;
    for (gg i = 0; i < ni;i++){
        for (gg j = 1; j <= ni;j++){
            tmp = 0;
            gg leftup = (j - ri < 1 ? 1 : j - ri);
            gg rightup = (j + ri > ni ? ni : j + ri);
            gg leftdown = (i - ri < 0 ? 0 : i - ri);
            gg rightdown = (i + ri > ni - 1 ? ni - 1 : i + ri);
            gg num = (rightdown - leftdown + 1) * (rightup - leftup + 1);
            while(leftdown <= rightdown){
                tmp += (v[leftdown][rightup] - v[leftdown][leftup - 1]);
                leftdown++;
            }
            if(tmp * 1.0 / num  <= ti)    //  要进行浮点比较 真服了
                res++;
        }
    }
    cout << res;
    return 0;
}
