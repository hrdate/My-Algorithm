欧几里得算法(gcd)及其扩展(exgcd)

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
————————————————————————

用于解决如下问题：
已知a，b，求解一组x，y，使其满足 ax + by = gcd(a, b) （该等式称贝祖等式）

另有结论：
设a, b, c为任意整数，g = gcd(a, b), 方程ax + by = g的一组解为(x0, y0)

当c是g的倍数时，方程ax + by = c的一组解为(x0 * c / g, y0 * c / g)；

当c不是g的倍数时无整数解

设a, b, c为任意整数，g = gcd(a, b), 方程ax + by = c的一组解为(x0, y0)
则它的任意解都可以写成(x0 + kb',y0-ka'), 其中a' = a / gcd(a,b) , b' = b / gcd(a, b)
——————————————————————————

//函数返回为a，b的最大公约数，求得的解存放在x，y中
int exgcd(int a, int b, int& x, int& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int g = exgcd(b, a % b, x, y);
		int x2 = x;
		int y2 = y;
		x = y2;
		y = x2 - a / b * y2;
		return g;
	}
}


——————————————————————————————————————————————————————
线性同余方程 拓展欧几里得算法exgcd

int ex_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = ex_gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
bool liEu(int a, int b, int c, int& x, int& y) {
  int d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return 1;
}


————————————————————————————

pll exgcd(const long long x, const long long y) {
  if (!y) return {1, 0};
  pll cur = exgcd(y, x % y);
  return {cur.second, cur.first - (x / y) * cur.second};
}



