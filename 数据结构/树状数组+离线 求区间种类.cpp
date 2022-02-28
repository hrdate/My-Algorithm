#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e6+7;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
struct node{
	int l,r,id;
	bool operator<(const node a)const{
		return r<a.r;
	}
}p[MAX];
int n,m,a[MAX],last[MAX],ans[MAX],tree[MAX];
int lowbit(int x){
	return x&-x; 
}
void add(int n,int x){
	while(n<MAX){
		tree[n]+=x;
		n+=lowbit(n); 
	}
}
int sum(int n){
	int res=0;
	while(n>0){
		res+=tree[n];
		n-=lowbit(n); 
	}
	return res; 
}
int range_sum(int l,int r){
	return sum(r)-sum(l-1);
} 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>p[i].l>>p[i].r,p[i].id=i;
	sort(p+1,p+1+m);
	int next=1;
	for(int i=1;i<=m;i++){
		for(int j=next;j<=p[i].r;j++){
			if(last[a[j]]!=0)add(last[a[j]],-1);
			add(j,1);  last[a[j]]=j;
		}
		next=p[i].r+1; ans[p[i].id]=range_sum(p[i].l,p[i].r);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
   return 0;
}  