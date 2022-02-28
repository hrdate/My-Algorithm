//初始化
void init_rmq(int n){  
    for(int i=0;i<n;i++)d[i][0]=a[i];  
    for(int j=1;(1<<j)<=n;j++){  
        for(int i=0;i+(1<<j)-1<n;i++)  
        d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);  
    }  
}   
 
//查询
int query_rmq(int L,int R){  
    int k=0;  
    while(1<<(k+1)<=R-L+1)k++;  
    return max(d[L][k],d[R-(1<<k)+1][k]);  
}  


————————————————————————————
P3865 【模板】ST表   解决RMQ问题（区间最值问题） 
ST表：O(nlogn)预处理，O(1)查询区间最值
https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using namespace std;
const int logn = 21;
const int maxn = 2000001;
int f[maxn][logn], Logn[maxn];
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
void pre() {
  Logn[1] = 0;
  Logn[2] = 1;
  for (int i = 3; i < maxn; i++) {
    Logn[i] = Logn[i / 2] + 1;
  }
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) f[i][0] = read();
  pre();
  for (int j = 1; j <= logn; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    int s = Logn[y - x + 1];
    printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
  }
  return 0;
}

