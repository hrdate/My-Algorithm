快速乘法
快速乘法：快速计算a* b% mod的结果，对于大数直接乘可能会爆long long，用快速乘法每一步都取余不会爆掉。

实现原理是：

对于乘数b来说，势必可以拆成2进制，比如110101。有一些位为0，有一些位为1。根据乘法分配律：a* b = a * （b1 + b2 + b3 + ……）
那么对于a * 53 = a * 110101（二进制） = a * （100000 + 10000 + 100 + 1） = a * （100000 * 1 + 10000 * 1 + 1000 * 0 + 100 * 1 + 10 * 0 + 1 * 1）。
那么设立一个ans = 0用于保存答案，每一位让a *= 2，在根据b的对应为1看是不是加上此时的a，即可完成快速运算。



快速幂：快速计算a ^ b % mod的结果。

实现原理是：

把b转换成二进制数。

该二进制数第i位的权为

例如


11的二进制是1011

11 = 2 ? ×1 + 2 ? ×0 + 2 ? ×1 + 2 ? ×1

因此，我们将a ? ? 转化为算



代码如下：
————————————————
版权声明：本文为CSDN博主「vlinz」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https ://blog.csdn.net/Aerry_ale/article/details/81037443
#include <iostream>
using namespace std;

typedef long long ll;
//快速乘法
ll q_mul(ll a, ll b, ll mod) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return ans;
}
// 快速幂
ll q_pow(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = q_mul(ans, a, mod);
		a = q_mul(a, a, mod);
		b >>= 1;
	}
	return ans;
}

int main() {
	ll a = 1005345645650000079, b = 1256465546534567898, mod = 100054604565600;
	cout << q_mul(a, b, mod) << endl;
	cout << q_pow(a, b, mod);
	return 0;
}




