 #include<bits/stdc++.h>
using namespace std;
const int MAX=50005;
int a[MAX],tree[MAX],n;
int lowbit(int x) { //找最低位的1 
	return x&-x;
}
void add(int i,int x){ //修改数据在i加x 
    while(i<=n){
        tree[i]+=x;
        i+=lowbit(i);
    }
}
int sum(int i){
    int res=0;
    while(i>0){
        res+=tree[i];
        i-=lowbit(i);
    }
    return res;
}
void range_add(int l, int r, int a){ //区间修改
        add(l, a);
        add(r + 1, -a);
}
ll range_sum(int l, int r){  //区间求和
        return sum(r) - sum(l - 1);
}
int kth(int fwtree[], int size, int k){
    int cnt = 0, ret = 0;
    for (int i = (int)(log(size + 0.1) / log(2)); ~i; --i){
        ret += 1 << i;
        if (ret >= size || cnt + fwtree[ret] >= k)
            ret -= 1 << i;
        else
            cnt += fwtree[ret];
    }
    return ret + 1;
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	
	
	
 } 
