两次 DFS 
先从任意一点P出发，找离它最远的点Q，
再从点Q出发，找离它最远的点W，W到Q的距离就是是的直径
————————————————————————————
树形dp求树的直径

#include <iostream>
#include <vector>
using namespace std;

const int N = int(1e4) + 9;
vector<int> adj[N];
int n, d;
int dfs(int u = 1, int p = -1) {
  int d1 = 0, d2 = 0;
  for (auto v : adj[u]) {
    if (v == p) continue;
    int d = dfs(v, u) + 1;
    if (d > d1)
      d2 = d1, d1 = d;
    else if (d > d2)
      d2 = d;
  }
  d = max(d, d1 + d2);
  return d1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  cout << d << endl;
}