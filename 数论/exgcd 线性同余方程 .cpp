ŷ������㷨(gcd)������չ(exgcd)

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
������������������������������������������������

���ڽ���������⣺
��֪a��b�����һ��x��y��ʹ������ ax + by = gcd(a, b) ���õ�ʽ�Ʊ����ʽ��

���н��ۣ�
��a, b, cΪ����������g = gcd(a, b), ����ax + by = g��һ���Ϊ(x0, y0)

��c��g�ı���ʱ������ax + by = c��һ���Ϊ(x0 * c / g, y0 * c / g)��

��c����g�ı���ʱ��������

��a, b, cΪ����������g = gcd(a, b), ����ax + by = c��һ���Ϊ(x0, y0)
����������ⶼ����д��(x0 + kb',y0-ka'), ����a' = a / gcd(a,b) , b' = b / gcd(a, b)
����������������������������������������������������

//��������Ϊa��b�����Լ������õĽ�����x��y��
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


������������������������������������������������������������������������������������������������������������
����ͬ�෽�� ��չŷ������㷨exgcd

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


��������������������������������������������������������

pll exgcd(const long long x, const long long y) {
  if (!y) return {1, 0};
  pll cur = exgcd(y, x % y);
  return {cur.second, cur.first - (x / y) * cur.second};
}



