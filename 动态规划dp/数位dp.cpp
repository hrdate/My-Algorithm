/*
数位dp
https://loj.ac/p/10165 Windy 数
Windy 定义了一种 Windy 数：不含前导零且相邻两个数字之差至少为 2 的正整数被称为 Windy 数。

Windy 想知道，在 A 和 B 之间，包括 A 和 B，总共有多少个 Windy 数？
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int N = 12;
int f[N][N];
void init(){
    for(int i = 0;i <= 9;i++)   f[1][i] = 1;
    for(int i = 2;i < N;i++){
        for(int j = 0;j <= 9;j++){
            for(int k = 0;k <= 9;k++){
                if(abs(j - k) >= 2) f[i][j] += f[i - 1][k];
            }
        }
    }
}
int get(int n){
    if(!n)  return 0;
    vector<int> num;
    while(n)    num.push_back(n % 10),n /= 10;
    int res = 0,last = -2;
    for(int i = num.size() - 1;i >= 0;i--){
        int x = num[i];
        if(x){
            for(int j = 1;j < x;j++){
                if(abs(j - last) >= 2)  res += f[i + 1][j];
            }
            if(last >= 2)  res += f[i+1][0];//不是最高位时，加上0开头的windy数
        }
        if(abs(x - last) < 2)   break;
        last = x;
        if(!i)  res++;
    }
    for(int i = 1;i < num.size();i++){//加上最高位是0的windy数
        for(int j = 1;j <= 9;j++){
            res += f[i][j];
        }
    }
    return res;
}
int main(){
    int A,B;
    cin>>A>>B;
    init();
    cout<<get(B) - get(A - 1)<<endl;
    return 0;
}