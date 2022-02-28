#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ll long long
#define _for(i,a,b) for(int i = (a);i<(b);i++)
#define endl  '\n'
#define inf 0x3f3f3f3f
#define ull unsigned long long  
using namespace std;
const int mod=1e9+7;
const int MAX=1e4+7;
using namespace std;
int a[105],b[105];
int main()
{
     int i,j,len;
    char x;string s1="",s3="",s2,s4;
    while(cin>>x,x!='.')
    {
        s1=x+s1;
    }
    cin>>s2;
    while(cin>>x,x!='.')
    {
        s3=x+s3;
    }
    cin>>s4;

    if(s1.size()<s3.size()) 
	swap(s1,s3);
    for(i=0;i<s3.size();i++)
    {
        a[i]+=s1[i]-'0'+s3[i]-'0';
        if(a[i]>=10) 
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    for(;i<s1.size();i++)
    {
        a[i]+=s1[i]-'0';
        if(a[i]>=10) 
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    if(a[i]) len=i;
	else len=i-1;
    if(s2.size()<s4.size()) 
	swap(s2,s4);
    for(i=0;i<s4.size();i++) 
	b[i]=s2[i]-'0'+s4[i]-'0';
    for(;i<s2.size();i++) 
	b[i]=s2[i]-'0';
    for(i=s2.size()-1;i>=0;i--)
    {
        if(i==0&&b[i]>=10)
        {
            a[0]++;
            b[0]-=10;
        }
        else
        if(b[i]>=10)
        {
            b[i-1]++;
            b[i]-=10;
        }
    }
    i=0;
    while(a[i]>=10)
    {
        a[i+1]++;
        a[i]-=10;
        i++;
    }
    len=max(len,i);
    for(j=len;j>=0;j--) 
	cout<<a[j];
    cout<<'.';
    for( j=s2.size()-1;j>=0;j--) 
	if(b[j]) break; 
    for(i=0;i<=j;i++) 
	cout<<b[i];
}