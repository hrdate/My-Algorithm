并查集
make创建单位
find查寻
union和并 利用find合并root根节点
————————————————————————————
不带路径压缩的查找函数
int find(int x) {
    if (f[x] != x) {
        return find(f[x]);
    }
    return f[x];
}

带路径压缩的查找函数
int find(int x) {
    if (f[x] != x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

合并两个元素所在的集合
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        f[x] = y;
    }
}
————————————————————————
洛谷 P3367 【模板】并查集
https ://www.luogu.com.cn/problem/P3367
#include<bits/stdc++.h>
using namespace std;
int pre[100005];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		pre[i] = i;
}int find(int x)
{
 return pre[x] == x ? x : pre[x] = find(pre[x]); //带路径压缩的查找函数 
}
void mix(int a, int b)
{
	int fa = finds(a);
	int fb = finds(b);
	if (fa != fb)
		pre[fa] = fb;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	init(n);
	int z, x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> z >> x >> y;
		if (z == 1)
			mix(x, y);
		else if (z == 2)
		{
			if (finds(x) == finds(y))
				cout << "Y" << '\n';
			else cout << "N" << '\n';
		}
	}
}



——————————————————————————
AtCoder Beginner Contest 157 D Friend Suggestions 容斥原理 + 并查集
https ://blog.csdn.net/mrcrack/article/details/104454762

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int father[N], sum[N], ans[N];
int n, m, k, x, y;

int Findfather(int x) {
	return father[x] == x ? x : father[x] = Findfather(father[x]);
}

void Union(int a, int b) {
	a = Findfather(a), b = Findfather(b);
	if (a != b) father[b] = a, sum[a] += sum[b];
}

void init() {
	for (int i = 0; i <= n; i++)
		father[i] = i, sum[i] = 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	init();
	while (m--) {
		scanf("%d%d", &x, &y);
		ans[x]++, ans[y]++;
		Union(x, y);
	}
	while (k--) {
		scanf("%d%d", &x, &y);
		if (Findfather(x) == Findfather(y)) ans[x]++, ans[y]++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", sum[Findfather(i)] - ans[i] - 1);
	}
	return 0;
}

