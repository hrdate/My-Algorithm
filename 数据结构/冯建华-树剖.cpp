#include <bits/stdc++.h>
using namespace std;
//#define cin file
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef int64_t ll; typedef pair<ll, ll> pll; typedef pair<int, int> pii; typedef vector<vector<int>> Graph; typedef uint64_t ull;
const double PI = acos(-1), EPS = 1e-8; const int inf = 1 << 29, Mod = 1e9 + 7, P = 998244353; ll ts = 1, _ts = 1, n, M; const ll INF = 1ll << 59; 
ll qpow(ll a, ll b, ll mod = Mod, ll s = 1) { for (; b; b >>= 1, a = (a * a) % mod)if (b & 1)s = (s * a) % mod % mod; return s; };
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }; ll lcm(ll a, ll b) { return a * b / gcd(a, b); };
pll EXgcd(ll x, ll y) { if (!y) { return { 1,0 }; }pll a = EXgcd(y, (x + y) % y); return { a.second, a.first - a.second * (x / y) }; }; ll Inv(ll x, ll m) { return (EXgcd(x, m).first + m) % m; };
void yesno(bool ok, bool upper) { if (ok)cout << (upper ? "YES\n" : "Yes\n"); else cout << (upper ? "NO\n" : "No\n"); };
bool maskq(ll mk, int b) { return ((mk >> b) & 1); }; ll maskch(ll mk, int b) { return (mk ^ (1ll << b)); }; bool isdiv(ll x, ll b) { return !(x % b); };
template<class T>void Get(T& x) { x = 0; short f = 1; char c; while (!isdigit(c = getchar()))if (c == '-') f = -1; do x = x * 10 + c - '0'; while (isdigit(c = getchar())); x *= f; }
/*change vector ll but not function ll?
* distance begin, end = size;
* visit same u again?
* reset dp front / numdp cnts 0?
* exp dp try dimension = state.
* try dfs downward first.
* don't watse space, e.g. fa.
* 1s = 1e8
* subdp mk & (mk - 1); sub; sub = mk & (sub - 1).cnts sub > (mk ^ sub)
* queue rather loop n
* read title kerfly & patntly
* lr dp
* if same, while
* vector empty?
*/
struct Tree {
	int Root;
	vector<int>sz, son, fa, dep, top, dfn, rnk;
	Tree(const Graph& G, int root) :Root(root), sz(G.size(), 1), son(G.size(), -1)
		, fa(G.size(), -1), dep(G.size(), -1), top(G.size(), -1),dfn(G.size()) {
		function<void(int, int)>_dfs1 = [&](int u, int f) {
			for (const int& v : G[u]) {
				if (v == f)continue;
				fa[v] = u; dep[v] = dep[u] + 1;
				_dfs1(v, u); sz[u] += sz[v];
				if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
			}
		};
		function<void(int, int)>_dfs2 = [&](int u, int tp) {
			top[u] = tp; dfn[u] = rnk.size();rnk.emplace_back(u); 
			if (son[u] < 0)return; _dfs2(son[u], tp);
			for (const auto& v : G[u]) {
				if (v == son[u] || v == fa[u])continue;
				_dfs2(v, v);
			}
		}; dep[Root] = 0; _dfs1(Root, -1); _dfs2(Root, Root);
	}
};
struct SegTree {
#define lson (i<<1|1)
#define rson ((i<<1)+2)
#define Mid (l+r>>1)
	int segn, Z; vector<ll>tag, Tree;
	SegTree(int n_) :segn(n_), Z(n_ << 2), tag(Z, 0), Tree(Z, 0) {};
	void Pushdown(int i, int l, int r, int m) {// attention
		if (!tag[i])return;
		Tree[lson] += tag[i];
		Tree[rson] += tag[i];
		tag[lson] += tag[i]; tag[rson] += tag[i];
		tag[i] = 0;
	}
	void Pushup(int i) {
		Tree[i] = max(Tree[lson], Tree[rson]);
	}
	void RangeUpd(int ql, int qr, ll val, int l, int r, int i) {
		if (r < ql || l > qr)return;
		if (ql <= l && r <= qr) { //attention
			Tree[i] += val;
			tag[i] += val; return;
		}
		Pushdown(i, l, r, Mid);
		RangeUpd(ql, qr, val, l, Mid, lson);
		RangeUpd(ql, qr, val, Mid + 1, r, rson);
		Pushup(i);
	}
	ll Query(int ql, int qr, int l, int r, int i) {
		if (r < ql || l > qr)return 0;
		if (ql <= l && r <= qr) return Tree[i];
		Pushdown(i, l, r, Mid);
		return max(Query(ql, qr, l, Mid, lson), Query(ql, qr, Mid + 1, r, rson));
	}
#undef Mid
#undef lson
#undef rson
};

int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);   

//	fstream file("input.txt");
//	cin >> ts;
//	ts = INF;
	for (; _ts++ <= ts;) {
		cin >> n;
		Graph G(n);
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v; --u, --v;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		Tree tc(G, 0);
		SegTree seg(n);
		int q; cin >> q;
		while (q--) {
			int op; cin >> op;
			if (op == 1) {
				int u, w; cin >> u >> w; --u;
				seg.RangeUpd(tc.dfn[u], tc.dfn[u] + tc.sz[u] - 1, w, 0, n - 1, 0);
				//cout << tc.dfn[u] << ' ' << tc.dfn[u] + tc.sz[u] - 1 << '\n';
				//for (int i = 0; i < n; ++i)cout << seg.Query(i, i, 0, n - 1, 0) << ' ';
				//cout << '\n';
			}
			else {
				ll ans = -1;
				int u; cin >> u; --u;
				ans = max(ans, seg.Query(tc.dfn[u], tc.dfn[u] + tc.sz[u] - 1, 0, n - 1, 0));
				cout << ans << '\n';
			}
		}
	}
}