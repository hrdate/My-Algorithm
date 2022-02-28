/*
https://www.luogu.com.cn/problem/P1833
有 n 种樱花树和长度为 ti的时间，有的樱花树只能看一遍，有的樱花树最多看 pi遍，
有的樱花树可以看无数遍。每棵樱花树都有一个美学值 ci，求在 n的时间内看哪些樱花树能使美学值最高。
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define endl "\n" 
#define ll long long
const int MAX=2e6+7;
int t[MAX],c[MAX],p[MAX];
int dp[MAX],cc[MAX],tt[MAX],ind=0;
void solve(){
	int h1,m1,h2,m2,n,T=0;scanf("%d:%d%d:%d%d",&h1,&m1,&h2,&m2,&n);
    T=h2*60+m2-h1*60-m1;
    for(int i=1;i<=n;i++){
    	scanf("%d%d%d",&t[i],&c[i],&p[i]) ;
    	if(p[i]==0)p[i]=999999;
	}
    for(int i=1;i<=n;i++){
    	int cnt=1;
    	while(p[i]){
    		p[i]-=cnt;
    		tt[++ind]=cnt*t[i];
    		cc[ind]=cnt*c[i];
    		cnt*=2;
    		if(	p[i]<cnt){
    			tt[++ind]=p[i]*t[i];
    			cc[ind]=p[i]*c[i];
    			break;
			}
		}
	}
    for(int i=1;i<=ind;i++)
    	for(int j=T;j>=tt[i];j--)
    		dp[j]=max(dp[j],dp[j-tt[i]]+cc[i]);
    printf("%d",dp[T]);   // printf输出不需要引用 
}
signed main(){
    solve();
   return 0;
} 