/*
趣写算法系列之--匈牙利算法
https://www.luogu.com.cn/problem/P3386
https://blog.csdn.net/Dark_Scope/article/details/8880547

枚举每一个左部点 uu ，然后枚举该左部点连出的边，对于一个出点 vv，
如果它没有被先前的左部点匹配，那么直接将 uu 匹配 vv，
否则尝试让 vv 的“原配”左部点去匹配其他右部点，如果“原配”匹配到了其他点，
那么将 uu 匹配 vv，否则 uu 失配。
复杂度O(n×e+m)
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define AC 0 
#define Please return
#define endl "\n" 
#define ll long long
const int MAX=1e6+7;
const int mod=1e9+7;
const ll inf=0x3f3f3f3f;
int vis[MAX],match[MAX];
vector<int> g[MAX];   //邻接表
int n,m,e,ans;
bool Find(int u,int tag){
    if(vis[u]==tag)return 0;   //防止重新遍历
	vis[u]=tag;
	for(auto v:g[u]){
		if(match[v]==0||Find(match[v],tag)){
			match[v]=u;
			return 1;
		}
	} 
    return 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m>>e;
    for(int i=1,a,b;i<=e;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(Find(i,i))//省掉了memset
          ans++;
    }
    cout<<ans;
    return 0;
}