/*
SPOJ - GSS1&&GSS3
https://www.cnblogs.com/shenben/p/6361623.html

牛客 
https://ac.nowcoder.com/acm/contest/1033/A
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
#define lc 2*p
#define rc 2*p+1
const int MAX=2e6+7;
const int mod=998244353;
const ll inf=0x3f3f3f3f;
const double pi=acos(-1);
struct sgtment{
    int sum,gss,lgss,rgss;
}tree[MAX];
int a[MAX],n,m;
void push_up(int p){
    tree[p].sum=tree[lc].sum+tree[rc].sum;
    tree[p].lgss=max(tree[lc].lgss,tree[lc].sum+tree[rc].lgss);
    tree[p].rgss=max(tree[rc].rgss,tree[rc].sum+tree[lc].rgss);
    tree[p].gss=max(max(tree[lc].gss,tree[rc].gss),tree[lc].rgss+tree[rc].lgss);
}
void build(int l=1,int r=n,int p=1){
    if(l==r){
        tree[p].sum=tree[p].gss=tree[p].lgss=tree[p].rgss=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,lc);
    build(mid+1,r,rc);
    push_up(p);
}
void change(int ind,int val,int l=1,int r=n,int p=1){  //单点修改 a[ind]→val 
    if(l==r){
        tree[p].sum=tree[p].gss=tree[p].lgss=tree[p].rgss=val;
        return ;
    }
    int mid=(l+r)/2;
    if(ind<=mid) change(ind,val,l,mid,lc);
    else change(ind,val,mid+1,r,rc);
    push_up(p);
}
sgtment query(int l,int r,int tl=1,int tr=n,int p=1){
    if(tl==l&&tr==r) return tree[p];
    int mid=(tl+tr)/2;
    if(r<=mid) return query(l,r,tl,mid,lc);
    else if(l>mid) return query(l,r,mid+1,tr,rc);
    else{
        sgtment left,right,res;
        left=query(l,mid,tl,mid,lc);
        right=query(mid+1,r,mid+1,tr,rc);
        res.sum=left.sum+right.sum;
        res.lgss=max(left.lgss,left.sum+right.lgss);
        res.rgss=max(right.rgss,right.sum+left.rgss);
        res.gss=max(max(left.gss,right.gss),left.rgss+right.lgss);
        return res;
    } 
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,n,1);
    for(int i=1,op,x,y;i<=m;i++){
        cin>>op>>x>>y;
        if(op==1) {
            if(x>y)swap(x,y);
            cout<<query(x,y).gss<<endl;
        }
        else change(x,y);
    }
    return 0;
}