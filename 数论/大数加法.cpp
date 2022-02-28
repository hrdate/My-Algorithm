c++解决大整数加法
含负数
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;
#define ll long long
struct Node
{
	ll d[10005];
	ll len;
	bool f;

	Node() { memset(d, 0, sizeof(d)); }
	Node(char* s)
	{
		memset(d, 0, sizeof(d));
		if (s[0] == '-')
			f = 1, s++;
		else
			f = 0;
		int i = 0;
		while (s[i] != '\0')
		{
			d[i] = s[i] - '0';
			++i;
		}
		len = i;
		for (int i = 0, j = len - 1; i < j; i++, j--)
			swap(d[i], d[j]);
	}

	bool operator < (const Node& t) const
	{
		if (this->len == t.len)
		{
			for (int i = t.len - 1; i >= 0; i--)
			{
				if (this->d[i] < t.d[i])
					return true;
				else if (this->d[i] > t.d[i])
					return false;
			}
		}
		return this->len <= t.len;
	}

	Node operator + (const Node& t) const
	{
		Node ans;
		if (t.f == this->f)
		{
			ans.f = this->f;
			int len = max(t.len, this->len);
			ans.len = len;
			for (int i = 0; i < len; i++)
			{
				ans.d[i] += this->d[i] + t.d[i];
				ans.d[i + 1] += ans.d[i] / 10;
				ans.d[i] %= 10;
			}
			if (ans.d[len] != 0)
				ans.len++;
			while (ans.len > 1 && ans.d[ans.len - 1] == 0)
				ans.len--;
		}
		else
		{
			if (t < (*this))
				ans = (*this) - t;
			else
				ans = t - (*this);
		}
		return ans;
	}

	Node operator - (const Node& t) const
	{
		Node ans;
		ans.f = this->f;
		int len = this->len;
		ans.len = len;
		for (int i = 0; i < len; i++)
		{
			ans.d[i] += this->d[i] - t.d[i];
			if (ans.d[i] < 0)
			{
				ans.d[i] += 10;
				ans.d[i + 1]--;
			}
		}
		while (ans.len > 1 && ans.d[ans.len - 1] == 0)
			ans.len--;
		return ans;
	}
};

char str[10005];

int main()
{
	cin >> str;
	Node a(str);
	cin >> str;
	Node b(str);
	Node ans = a + b;
	if (ans.f)
		cout << "-";
	for (int i = ans.len - 1; i >= 0; i--)
		cout << ans.d[i];
}
