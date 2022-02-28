牛客 数列求值
https://ac.nowcoder.com/acm/contest/6631/C 

const int mod = 1000000007;

struct Matrix {
  int a[3][3];
  Matrix() { memset(a, 0, sizeof a); }
  Matrix operator*(const Matrix &b) const {
    Matrix res;
    for (int i = 1; i <= 2; ++i)
      for (int j = 1; j <= 2; ++j)
        for (int k = 1; k <= 2; ++k)
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
    return res;
  }
} ans, base;

void init() {
  base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
  ans.a[1][1] = ans.a[1][2] = 1;
}

void qpow(int b) {
  while (b) {
    if (b & 1) ans = ans * base;
    base = base * base;
    b >>= 1;
  }
}

int main() {
  int n = read();
  if (n <= 2) return puts("1"), 0;
  init();
  qpow(n - 2);
  println(ans.a[1][1] % mod);
}

——————————————————————————————————————
https://ac.nowcoder.com/acm/contest/10507/A  矩阵快速幂+欧拉降幂
/*
static const int N=2;
const int MOD=1000000007;
struct Matrix{
  long long m[N][N];
  Matrix(){memset(m,0,sizeof(m));}
};
Matrix mult(Matrix a,Matrix b){
  Matrix res;
  for(int i=0;i<N;++i)
  for(int j=0;j<N;++j)
  for(int r=0;r<N;++r)
    res.m[i][j]+=a.m[i][r]*b.m[r][j],res.m[i][j]%=MOD;
  return res;
}
Matrix mqpow(Matrix a,long long y){
  Matrix ans;
  for(int i=0;i<N;++i)ans.m[i][i]=1;
  while(y){
    if(y&1)ans=mult(ans,a);
    a=mult(a,a);
    y>>=1;
  }
  return ans;
}

*/