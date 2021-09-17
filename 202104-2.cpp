#include<bits/stdc++.h>    //   可以借鉴一维前缀和的思想  前缀和矩阵均是固定起点 考虑递推
using namespace std;       //   但是在求一端具体的区间元素之和时，区间的起点是很重要的
using gg = long long;      //   求二维前缀和矩阵时是根据矩阵右下角(x2,y2) - 1进行划分的 而求子矩阵的和时是根据左上角
int main(void){            //   坐标(x1,y1)-1 进行划分的 始终记住定义 v[x][y] 表示以(1,1)为左上角 (x,y)为右下角
    ios::sync_with_stdio(false);   //  的矩阵和 那划分过后，要求多余矩阵的和，显然也要根据这个定义 两个角的坐标都要参与
    cin.tie(0);
    gg ni, li, ri, ti, res = 0;
    cin>>ni>>li>>ri>>ti;
    vector<vector<gg>>v(ni+1,vector<gg>(ni+1,0));
    for(gg i =1;i<=ni;i++){
        for(gg j = 1;j <= ni;j++){
            cin>>v[i][j];
        }
    }
    //   构建二维前缀和数组
    for(gg i =1;i<=ni;i++){
        for(gg j =1;j<=ni;j++){
            v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + v[i][j];
        }
    }
    //   求子矩阵元素和
    for(gg i =1;i<=ni;i++){
        for(gg j =1;j<=ni;j++){
            gg x1 = i - ri < 1 ? 1 : i - ri;
            gg y1 = j - ri < 1 ? 1 : j - ri;
            gg x2 = i + ri > ni ? ni : i + ri;
            gg y2 = j + ri > ni ? ni : j + ri;
            gg ans = v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1];
            gg num = (x2-x1+1) * (y2 - y1 + 1);
            if(ans <= ti * num) res++;
        }
    }
    cout<<res;
    return 0;
}
