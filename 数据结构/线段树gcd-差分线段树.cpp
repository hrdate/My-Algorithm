/*
http://codeforces.com/contest/1459/problem/C

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson i<<1
#define rson i<<1|1
const int MAXN=5+2e5;
int maxx[(MAXN<<2)+5],minx[(MAXN<<2)+5],sum[(MAXN<<2)+5],g[(MAXN<<2)+5];
int n,m,data[MAXN];
inline int gcd(int a,int b){return!b?a:gcd(b, a % b);}
inline int get_gcd(int x,int y,int i=1,int l=1,int r=n){
    if(x>y)return 0;
    if(x<=l&&r<=y)return g[i];
    int mid=(r+l)>>1;
    int res=0;
    if(x<=mid)res=gcd(get_gcd(x,y,lson,l,mid),res);
    if(y>mid) res=gcd(get_gcd(x,y,rson,mid+1,r),res);
    return res;
}
inline int get_sum(int x,int y,int i=1,int l=1,int r=n){
    if(x>y)return 0;
    if(x<=l&&r<=y)return sum[i];
    int mid=(r+l)>>1,res=0;
    if(x<=mid)res+=get_sum(x,y,lson,l,mid);
    if(y>mid)res+=get_sum(x,y,rson,mid+1,r);
    return res;
}
inline int get_max(int x,int y,int i=1,int l=1,int r=n){
    if(x>y)return 0;
    if(x<=l&&r<=y)return maxx[i];
    int mid=(r+l)>>1,res=-0x7fffffff;
    if(x<=mid)res=max(res,get_max(x,y,lson,l,mid));
    if(y>mid)res=max(res,get_max(x,y,rson,mid+1,r));
    return res;
}
inline int get_min(int x,int y,int i=1,int l=1,int r=n){
    if(x>y)return 0;
    if(x<=l&&r<=y)return minx[i];
    int mid=(r+l)>>1,res=0x7fffffff;
    if(x<=mid)res=min(res,get_min(x,y,lson,l,mid));
    if(y>mid)res=min(res,get_min(x,y,rson,mid+1,r));
    return res;
}
 
inline void up(int i){
    g[i]=gcd(g[lson],g[rson]);
    sum[i]=sum[lson]+sum[rson];
    maxx[i]=max(maxx[lson],maxx[rson]);
    minx[i]=min(minx[lson],minx[rson]);
}
inline void build(int i=1,int l=1,int r=n){
    if(l==r){
        sum[i]=data[l]-data[l-1];   //差分数组 gcd(a,b,c,d...z)=gcd(a,b-a,c-b,d-c...z-y) 
        maxx[i]=minx[i]=sum[i];
        g[i]=sum[i];
        return;
    }
    int mid=(r+l)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    up(i);
}   
inline void change(int x,int val,int i=1,int l=1,int r=n){    //单点修改 a[ind]→val 
    if(l==r){
        sum[i]+=val;
        maxx[i]+=val;
        minx[i]+=val;
        g[i]+=val;
        return;
    }
    int mid=(r+l)>>1;
    if(x<=mid)change(x,val,lson,l,mid);
    else change(x,val,rson,mid+1,r);
    up(i);
}
void add(int x,int y,int val,int l=1,int r=n){
    if(x>y)return;
    change(x,val);
    if(y<n)change(y+1,-val);
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>data[i];
    build();
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        add(1,n,x);
        cout<<gcd(abs(get_sum(1,1)),abs(get_gcd(2,n)))<<' ';
        add(1,n,-x);
    }
}
