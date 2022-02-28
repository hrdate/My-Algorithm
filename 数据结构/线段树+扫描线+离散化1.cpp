/*
https://ac.nowcoder.com/acm/contest/1033/C
题意：在二维坐标系上，给出多个矩形的左下以及右上坐标，求出所有矩形构成的图形的面积
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
const int MAX=1e3+7;
int lz[MAX<<3];
double s[MAX<<3]; //离散化矩形边界按纵坐标从小到大排序 
struct node1{   //线段树 
	double l,r,sum;
}cl[MAX<<3];
struct node2{   //矩形 
	double x,y1,y2;
	int f;
	int operator<( node2 t){return x<t.x;}  //按照横坐标从小到大排序 
}p[MAX<<3];
void push_up(int rt){
	if(lz[rt]>0)cl[rt].sum=cl[rt].r-cl[rt].l;
	else cl[rt].sum=cl[rt*2].sum+cl[rt*2+1].sum;
}
void build(int l,int r,int rt){ //建树 
	if(r-l>1){
		cl[rt].l=s[l];
		cl[rt].r=s[r];
		build(l,(l+r)/2,rt*2);
		build((l+r)/2,r,rt*2+1);
		push_up(rt);
	}
	else{
		cl[rt].l=s[l];
		cl[rt].r=s[r];
		cl[rt].sum=0;   //建树时初始化个点sum为0 
	}
	return ;
}
void update(double y1,double y2,int rt,int f){  //更新 
	if(cl[rt].l==y1&&cl[rt].r==y2){
		lz[rt]+=f;
		push_up(rt);
		return ;
	}
	else {
		if(cl[rt*2].r>y1) update(y1,min(cl[rt*2].r,y2),rt*2,f);
		if(cl[rt*2+1].l<y2) update(max(cl[rt*2+1].l,y1),y2,rt*2+1,f); 
		push_up(rt);
	} 
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,cas=1;
	double x1,x2,y1,y2,ans;
	while(cin>>n&&n){
		ans=0;
		for(int i=0;i<n;i++){
			cin>>x1>>y1>>x2>>y2;
			p[i].x=x1,p[i].y1=y1,p[i].y2=y2; 
			p[i+n].x=x2,p[i+n].y1=y1,p[i+n].y2=y2; 
			p[i].f=1,p[i+n].f=-1;
			s[i+1]=y1,s[i+n+1]=y2;
		}
		sort(s+1,s+2*n+1);
		sort(p,p+2*n);
		build(1,2*n,1);
		memset(lz,0,sizeof(lz));
		update(p[0].y1,p[0].y2,1,p[0].f);
		for(int i=1;i<2*n;i++){
			ans+=(p[i].x-p[i-1].x)*cl[1].sum;
			update(p[i].y1,p[i].y2,1,p[i].f); 
		}
		cout<<"Test case #"<<cas++<<endl;
		cout<<"Total explored area: "<<fixed<<setprecision(2)<<ans<<endl<<endl;//要求多输出一行  
	}
   return 0;
} 