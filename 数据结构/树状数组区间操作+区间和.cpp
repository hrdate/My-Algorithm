
牛客 Tree Recovery
https://ac.nowcoder.com/acm/problem/15175
对原数组a进行差分预处理得到数组b，
对b[i]和b[i]*i分别维护一个树状数组tb、tc
————————————————————————
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl  '\n'
#define ll long long
using namespace std;
ll a[100005],b[100005];//a为原数组，b为a的差分数组
ll tb[100005],tc[100005]; //b[i]和b[i]*i分别维护的一个树状数组  ∑(1→r)a_i=∑(1→r)b_i*(r+1)-∑(1→r)b_i*i
int n,m; //n为树状数组大小
int lowbit(int x){
    return x&-x;
}
void add(int i,ll x){
    ll v=i*x;
    while(i<=n){
        tb[i]+=x;
        tc[i]+=v;
        i+=lowbit(i);
    }
}
void range_add(int l,int r,ll x){
    add(l,x);
    add(r+1,-x);
}
ll sum_t(ll *arr,int i){
    ll res=0;
    while(i>0){
        res+=arr[i];
        i-=lowbit(i);
    }
    return res;
}
ll sum(int i){
    return (i+1)*sum_t(tb,i)-sum_t(tc,i);
}
ll range_sum(int l,int r){
    return sum(r)-sum(l-1);
}
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
       cin>>n>>m;
       for(int i=1;i<=n;i++)
           cin>>a[i];
    for(int i=1;i<=n;i++) //预处理差分
           b[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) //以差分数组维护树状数组
        add(i,b[i]);
    while(m--){
        char c;cin>>c;
        if(c=='Q'){  //区间求和
            int x,y;cin>>x>>y;
            cout<<range_sum(x,y)<<endl;
        }
        else if(c=='C'){  //区间加上某值
            ll x,y,z;cin>>x>>y>>z;
            range_add(x,y,z);
        }
    }
    return 0;
}