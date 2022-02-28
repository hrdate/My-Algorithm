#include <math.h>
#include <vector>
/*
HDU4630-No Pain No Game
http://acm.hdu.edu.cn/showproblem.php?pid=4630
题意：给一串数字序列，然后问你L到R中的两个数的最大公约数最大，若相等的两个数则是0
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int maxn=50010;
int num[maxn<<2];
vector<int>G[maxn];
void update(int pos,int add,int le,int ri,int node){
    if(le==ri){
        num[node]=max(add,num[node]);
        return ;
    }
    int t=(le+ri)>>1;
    if(pos<=t) update(pos,add,le,t,node<<1);
    else update(pos,add,t+1,ri,node<<1|1);
    num[node]=max(num[node<<1],num[node<<1|1]);
}
int query(int l,int r,int le,int ri,int node){
    if(l<=le&&ri<=r) return num[node];
    int t=(le+ri)>>1,ans=0;
    if(l<=t) ans=max(ans,query(l,r,le,t,node<<1));
    if(r>t) ans=max(ans,query(l,r,t+1,ri,node<<1|1));
    return ans;
}
int A[maxn],ans[maxn],pre[maxn],vis[maxn];
struct edge{
    int num1,num2,pos;
}id[maxn];
bool cmp(const edge &a,const edge &b){
    return a.num2<b.num2;
}
void init(){
    for(int i=0;i<maxn;i++) G[i].clear();
    for(int i=1;i<=50000;i++){
        for(int j=1;j<=(int)sqrt(i);j++){
            if(i%j==0){
                G[i].push_back(j);
                if(j!=i/j) G[i].push_back(i/j);
            }
        }
        sort(G[i].begin(),G[i].end());
    }
}
int main(){
    int T,n,m;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&id[i].num1,&id[i].num2);
            id[i].pos=i;
        }
        sort(id,id+m,cmp);
        for(int i=0,j=0;i<n;i++){
            for(unsigned int l=0;l<G[A[i]].size();l++){
                int t=G[A[i]][l];
                if(vis[t]){
                    update(pre[t],t,1,n,1);
                    pre[t]=i+1;
                }else{
                    vis[t]=1;
                    pre[t]=i+1;
                }
            }
            for(;j<m;j++){
                if(i+1!=id[j].num2) break;
                if(id[j].num1==id[j].num2) ans[id[j].pos]=0;
                else ans[id[j].pos]=query(id[j].num1,id[j].num2,1,n,1);
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}