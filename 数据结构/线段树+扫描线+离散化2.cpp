/*
POJ 2482 Stars in Your Window（线段树扫描线-zui浪漫的题意)
https://ac.nowcoder.com/acm/contest/1033/D
题意：在一个平面内有N个星星，每个星星都在一个亮度值，用一个W*H的矩形去围这些星星
(边上的不算)求能得到的最大亮度值。

*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
#define int long long
#define lc 2*p
#define rc 2*p+1
const int MAX=1e6+7;
const int mod=998244353;
const ll inf=0x3f3f3f3f;
const double pi=acos(-1);
struct segt{
	int l,r,laz,c;
}tree[MAX<<2];
int xx[MAX],n,w,h;
void push_up(int p){
	tree[p].c=max(tree[lc].c,tree[rc].c);
}
void push_down(int p){
	if(tree[p].laz==0)return ;
	tree[lc].c+=tree[p].laz;
	tree[lc].laz+=tree[p].laz;
	tree[rc].c+=tree[p].laz;
	tree[rc].laz+=tree[p].laz;
	tree[p].laz=0;
}
void build(int p=1,int l=1,int r=n){
	tree[p].l=l; tree[p].r=r; tree[p].laz=tree[p].c=0;
	if(l==r) return ;
	int mid=(l+r)/2;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void update(int p,int l,int r,int val){
	if(tree[p].l==l&&tree[p].r==r){
		tree[p].c+=val;
		tree[p].laz+=val;
		return ;
	}
	push_down(p);
	int mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) update(lc,l,r,val);      //注意 
	else if(l>mid) update(rc,l,r,val);
	else {
		update(lc,l,mid,val);
		update(rc,mid+1,r,val);	 
	} 
	push_up(p);
}
struct edge{
	int l,r,h,v;
	bool operator<(const edge&tmp)const{
		return h==tmp.h?v<tmp.v:h<tmp.h;
	}
}a[MAX];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    
    while(cin>>n>>w>>h){
    	int tot=0;
    	for(int i=0;i<n;i++){
    		cin>>a[tot].l>>a[tot].h>>a[tot].v;
    		a[tot+1].l=a[tot].l;
    		a[tot].r=a[tot+1].r=a[tot].l+w;
    		a[tot+1].h=a[tot].h+h;
    		a[tot+1].v=-a[tot].v;
    		xx[tot]=a[tot].l;
    		xx[tot+1]=a[tot].r;
    		tot+=2; 
		}
		sort(xx,xx+tot);
		int cnt=unique(xx,xx+tot)-xx;  //去重 
    	sort(a,a+tot);
    	build(1,0,cnt);
    	int ans=0;
    	for(int i=0;i<tot;i++){
    		int l=lower_bound(xx,xx+cnt,a[i].l)-xx;
    		int r=lower_bound(xx,xx+cnt,a[i].r)-xx;
    		update(1,l,r-1,a[i].v);
    		ans=max(ans,tree[1].c);
		}
    	cout<<ans<<endl;
	}
   return 0;
} 
