
https://oi-wiki.org/basic/binary-lifting/#_1
在长度为n的环中，跳k次及从第i个点跳到第(i+k)%n+1个点，一共需跳m次,求权值和

记录一个 go[i][x] 表示第 x 个点跳 2^i 步之后的终点，
而 sum[i][x] 表示第 x个点跳 2^i 步之后能获得的点权和
/*
    sum[i][x] = sum[i-1][x]+sum[i-1][go[i-1][x]] ，
    且 go[i][x] = go[i-1][go[i-1][x]] 。
*/

#include <cstdio>
using namespace std;

const int mod = 1000000007;

int modadd(int a, int b) {
  if (a + b >= mod) return a + b - mod;  // 减法代替取模，加快运算
  return a + b;
}

int vi[1000005];

int go[75][1000005];  // 将数组稍微开大以避免越界，小的一维尽量定义在前面
int sum[75][1000005];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", vi + i);
  }

  for (int i = 1; i <= n; ++i) {
    go[0][i] = (i + k) % n + 1;
    sum[0][i] = vi[i];
  }

  int logn = 31 - __builtin_clz(n);  // 一个快捷的取对数的方法
  for (int i = 1; i <= logn; ++i) {
    for (int j = 1; j <= n; ++j) {
      go[i][j] = go[i - 1][go[i - 1][j]];
      sum[i][j] = modadd(sum[i - 1][j], sum[i - 1][go[i - 1][j]]);
    }
  }

  long long m;
  scanf("%lld", &m);

  int ans = 0;
  int curx = 1;
  for (int i = 0; m; ++i) {
    if (m & (1 << i)) {  // 参见位运算的相关内容，意为 m 的第 i 位是否为 1
      ans = modadd(ans, sum[i][curx]);
      curx = go[i][curx];
      m ^= 1ll << i;  // 将第 i 位置零
    }
  }

  printf("%d\n", ans);
}