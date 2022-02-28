/*
链接：https://ac.nowcoder.com/acm/contest/1033/B
来源：牛客网
给定一个长度为N的数列A，以及M条指令，每条指令可能是以下两种之一：
1、“C l r d”，表示把 A[l],A[l+1],…,A[r] 都加上 d。
2、“Q l r”，表示询问 A[l],A[l+1],…,A[r] 的最大公约数(GCD)。
对于每个询问，输出一个整数表示答案。
*/
#include<bits/stdc++.h>
using namespace std;
#define lc 2*p
#define rc 2*p+1
#define endl "\n" 
#define ll long long
#define int long long
const int MAX=5e5+7;
char s[10];
struct segt{
	int gcd;
}tree[MAX];
ll a[MAX],b[MAX],B[MAX*4],A[MAX*4],n,m;
void build(int p=1,int l=1,int r=n){
    if (l==r){
        tree[p].gcd=b[l];   //差分数组 gcd(a,b,c,d...z)=gcd(a,b-a,c-b,d-c...z-y) 
        return;
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    tree[p].gcd=__gcd(tree[lc].gcd,tree[rc].gcd);
}
void update(int p,int l,int r,int pos,ll val){    //单点修改 a[ind]→val 
    if (l==r){
        tree[p].gcd+=val;
        return;
    }
    int mid=(l+r)>>1;
    if (pos<=mid)update(lc,l,mid,pos,val);
    else update(rc,mid+1,r,pos,val);
    tree[p].gcd=__gcd(tree[lc].gcd,tree[rc].gcd);
}
ll query(int p,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[p].gcd;
    }
    int mid=(l+r)>>1;
    if (y<=mid) return query(lc,l,mid,x,y);
    else{
        if (x>mid) return query(rc,mid+1,r,x,y);
        else return __gcd(query(rc,mid+1,r,x,y),query(lc,l,mid,x,y));
    }
}
//BBT树状数组 
int lowbit(int x){
    return x&-x;
}
void add(int x,ll val){
    for (int i=x; i<=n; i+=lowbit(i)) A[i]+=val;
}
ll sum(int x){
    ll res=0;
    for (int i=x; i; i-=lowbit(i)) res+=A[i];
    return res;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];   //差分数组 gcd(a,b,c,d...z)=gcd(a,b-a,c-b,d-c...z-y) 
        add(i,b[i]);
    }
    build(1,1,n);
    while(m--){
        cin>>s;
        ll l,r,d;
        if (s[0]=='C'){   //修改 
            cin>>l>>r>>d;
            add(l,d);
            add(r+1,-d);
            update(1,1,n,l,d);
            if (r+1<=n) update(1,1,n,r+1,-d);
        }
        else{    //查询 
            cin>>l>>r;
            cout<<abs(__gcd(sum(l),query(1,1,n,l+1,r)))<<endl;
        }
    }
    return 0;
}