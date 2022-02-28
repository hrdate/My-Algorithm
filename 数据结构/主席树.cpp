const int maxn=100001;
struct Node{
     int ls,rs;  //left(T) 的范围是 [L,mid]，right(T) 的范围是 [mid+1,R]
     int cnt;  //子节点个数
}tr[maxn*20];
int cur,rt[maxn];
void init(){
    cur=0;
}
inline void push_up(int o){
     tr[o].cnt=tr[tr[o].ls].cnt+tr[tr[o].rs].cnt;
}
int build(int l,int r){
     int k=cur++;
     if (l==r) {
         tr[k].cnt=0;
         return k;
     }
     int mid=(l+r)>>1;
     tr[k].ls=build(l,mid);
     tr[k].rs=build(mid+1,r);
     push_up(k);
     return k;
} 
int update(int o,int l,int r,int pos,int val){
     int k=cur++;
     tr[k]=tr[o];
     if (l==pos&&r==pos){
         tr[k].cnt+=val;
         return k;
     }
     int mid=(l+r)>>1;
     if (pos<=mid) tr[k].ls=update(tr[o].ls,l,mid,pos,val);
     else tr[k].rs=update(tr[o].rs,mid+1,r,pos,val);
     push_up(k);
     return k;
}
 int query(int l,int r,int o,int v,int kth){
     if (l==r) return l;
     int mid=(l+r)>>1;
     int res=tr[tr[v].ls].cnt-tr[tr[o].ls].cnt;
     if (kth<=res) return query(l,mid,tr[o].ls,tr[v].ls,kth);
     else return query(mid+1,r,tr[o].rs,tr[v].rs,kth-res);
}
