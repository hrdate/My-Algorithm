#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define _for(i,a,b) for(int i = (a);i<(b);i++)
#define endl  '\n'
#define inf 0x3f3f3f3f  
using namespace std;
const int mod=1e9+7;
const int MAX=1005;
int a[MAX][MAX];
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)a[i][j]=0;
			else a[i][j]=inf;	
		}	
	} 
}
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
}

int main()
{
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
	 	init(); 
		int u,v,w;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			if(a[u][v]>w)
			{
				a[u][v]=w;   //无向图 
				a[v][u]=w;	
			} 
		}
		floyd();  
		cout<<a[1][n]<<endl;
	}
		
}