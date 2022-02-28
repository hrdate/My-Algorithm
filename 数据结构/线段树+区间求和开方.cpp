#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e5+5;
struct node{
	ll sum,l,r;//总和、
}d[MAX<<2];
ll n,m,a[MAX];
void push_up(int p){
	d[p].sum=d[2*p].sum+d[2*p+1].sum;
}
void build(int l,int r,int p){
	d[p].l=l;  d[p].r=r;
	if(l==r){
		cin>>d[p].sum;  //输入 
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,2*p);
	build(mid+1,r,2*p+1);
	push_up(p);
}
void update(int l,int r,int p)  //区间修改
{
	if(l==r){
		d[p].sum=sqrt(d[p].sum);
		return ;
	}
	int mid=(l+r)/2;
	if(d[2*p].sum!=(mid-d[2*p].l+1))  update(l,mid,2*p);
	if(d[2*p+1].sum!=(d[2*p+1].r-mid))  update(mid+1,r,2*p+1);
	push_up(p);
}
void modify(int l,int r,int p){
	if(d[p].l==l&&d[p].r==r){
		if(d[p].sum!=(r-l+1))update(l,r,p);
		return ;
	}
	int mid=(d[p].l+d[p].r)/2;
	if(mid>=r) modify(l,r,2*p);  //左 
	else if(mid<l) modify(l,r,2*p+1); //右 
	else  {
		modify(l,mid,2*p);modify(mid+1,r,2*p+1);
	}
	push_up(p);
}
ll getsum(int l,int r,int p)  //区间查询（区间求和）：
{
	if(l<=d[p].l&&r>=d[p].r){
       return d[p].sum;
	}
	int mid=(d[p].l+d[p].r)/2;
	if(mid>=r)return getsum(l,r,2*p);  //左 
	else if(mid<l)return getsum(l,r,2*p+1); //右 
	else	return getsum(l,mid,2*p)+getsum(mid+1,r,2*p+1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int _=0;
	while(cin>>n){
		_++;
		cout<<"Case #"<<_<<":"<<endl;
		build(1,n,1);
		cin>>m;
		while(m--){
			int k,x,y;cin>>k>>x>>y;
			if(x>y)swap(x,y);
			if(k==0)modify(x,y,1);
			else if(k==1)cout<<getsum(x,y,1)<<endl;
		}
		cout<<endl;
	}
   return 0;
} 