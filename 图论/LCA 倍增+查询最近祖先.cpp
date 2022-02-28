
———————————————————————————————
https://blog.csdn.net/qq_43093454/article/details/95024457
链式前向星存图

#include<bits/stdc++.h>
using namespace std;

const int nn=500010;

int n,m,s,t;
int d[nn],f[nn][20];/*d数组是记录每个点的深度，f[i][j]记录的是从i节点开始，向上走2^j步的节点编号*/

struct edge
{
	int to,nex;
}e[nn*2];
int num=0;
int last[nn];

void add(int x,int y)
{
	e[++num].to=y; e[num].nex=last[x];
	last[x]=num;
}

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

queue<int>	q;

void bfs()//预处理f数组和d数组
{
	q.push(s); d[s]=1;/*s在这里是根节点*/
	while(q.size())
	{
		int x=q.front(); q.pop();
		for(int i=last[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			if(d[y])	continue;
			d[y]=d[x]+1;
			f[y][0]=x;
			for(int j=1;j<=t;++j)
				f[y][j]=f[f[y][j-1]][j-1];/*倍增预处理出来f数组*/
			q.push(y);/*加入队列，更新其他节点*/
		}
	}
}

int lca(int x,int y)
{
	if(d[x]>d[y])	swap(x,y);/*命定y是深度较大的一个点，让y向上跳*/
	for(int i=t;i>=0;--i)
		if(d[f[y][i]]>=d[x])
			y=f[y][i];
	if(y==x)	return x;/*此时的y节点的深度和x节点相同，若x==y，则x节点本身就是x，y的lca*/
	for(int i=t;i>=0;--i)/*若不是，则一起向上跳*/
		if(f[y][i]!=f[x][i])
			y=f[y][i],x=f[x][i];
	return f[x][0];
}

int main()
{
	n=read(), m=read(), s=read();
	t=(int)(log(n)/log(2))+1;/*需要跳的步数*/
	for(int i=1;i<n;++i)
	{
		int a=read(),b=read();
		add(a,b), add(b,a);
	}
	bfs();
	for(int i=1;i<=m;++i)
	{
		int a=read();
		int b=read();
		printf("%d\n",lca(a,b));
	}
	return 0;
}