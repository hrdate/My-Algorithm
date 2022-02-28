/*
P3372 【模板】线段树 1 https://www.luogu.com.cn/record/47095445

*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
const int MAX=4e6+7;
const ll inf=0x3f3f3f3f;
ll a[MAX],n,m;
struct node{
	ll ma,mi,sum,laz;
}tree[MAX]; 
void push_up(ll p){
	tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
	tree[p].ma=max(tree[2*p].sum,tree[2*p+1].sum);
	tree[p].mi=min(tree[2*p].sum,tree[2*p+1].sum);
}
void push_down(ll l,ll r,ll p){
	ll mid=(l+r)/2;
	if(tree[p].laz==0)return;
	//左孩子2*p 
	tree[2*p].ma+=tree[p].laz;
	tree[2*p].mi+=tree[p].laz;
	tree[2*p].laz+=tree[p].laz;
	tree[2*p].sum+=(mid-l+1)*tree[p].laz;
	//右孩子2*p+1 
	tree[2*p+1].ma+=tree[p].laz;
	tree[2*p+1].mi+=tree[p].laz;
	tree[2*p+1].laz+=tree[p].laz;
	tree[2*p+1].sum+=(r-mid)*tree[p].laz;
	//根节父节点的laz 
	tree[p].laz=0;
}
void build(ll l=1,ll r=n,ll p=1){
	tree[p].laz=0; //初始化各点的laz 
	if(l==r){
		tree[p].sum=tree[p].ma=tree[p].mi=a[l];
		return ;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*p);
	build(mid+1,r,2*p+1);
	push_up(p);     //向上调整 
}
void update(ll l,ll r,ll val,ll tl=1,ll tr=n,ll p=1){
	if(tl>=l&&tr<=r){
		tree[p].ma+=val;
		tree[p].mi+=val;
		tree[p].laz+=val;
		tree[p].sum+=(tr-tl+1)*val;	
		return ;
	}
	push_down(tl,tr,p);
	ll mid=(tl+tr)/2; 
	if(mid>=l)update(l,r,val,tl,mid,2*p);
	if(mid<r)update(l,r,val,mid+1,tr,2*p+1);
	push_up(p);
} 

ll getsum(ll l,ll r,ll tl=1,ll tr=n,ll p=1){
	if(tl>=l&&tr<=r){
		return tree[p].sum;
	}
	push_down(tl,tr,p);
	ll mid=(tl+tr)/2;
	ll sum=0;
	if(mid>=l)sum+=getsum(l,r,tl,mid,2*p);
	if(mid<r)sum+=getsum(l,r,mid+1,tr,2*p+1);
	return sum; 
}

ll getmax(ll l,ll r,ll tl=1,ll tr=n,ll p=1){
	if(tl>=l&&tr<=r){
		return tree[p].ma;
	}
	ll mid=(tl+tr)/2;
	push_down(tl,tr,p);
	ll res=-inf;
	if(mid>=l)res=max(res,getmax(l,r,tl,mid,2*p));
	if(mid<r)res=max(res,getmax(l,r,mid+1,tr,2*p+1));
	return res; 
}
ll getmin(ll l,ll r,ll tl=1,ll tr=n,ll p=1){
	if(tl>=l&&tr<=r){
		return tree[p].mi;
	}
	ll mid=(tl+tr)/2;
	push_down(tl,tr,p);
	ll res=inf;
	if(mid>=l)res=min(res,getmin(l,r,tl,mid,2*p));
	if(mid<r)res=min(res,getmin(l,r,mid+1,tr,2*p+1));
	return res; 
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n;cin>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	while(m--){
		int op;cin>>op;
		if(op==1){
			int x,y,k;cin>>x>>y>>k;
			update(x,y,k);
		}
		else if(op==2){
			int x,y;cin>>x>>y;
			cout<<getsum(x,y)<<endl;
		}
	} 
   return 0;
} 



