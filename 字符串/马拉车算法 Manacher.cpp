//�������㷨 Manacher
https://www.cnblogs.com/cain-/p/7977368.html

ģ��
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 32000005;
int manacher(string s)
{
	string str=""; 
	int len=s.size(),mx=0,id=0,ans=0;
	for(int i=0;i<len;i++){
		str+="#";
		str+=s[i];
	}
	str+="#";
	len=str.size();
	vector<int>p(len,0);
	for(int i=0;i<len;i++){
		if(i<mx) p[i]=min(mx-i,p[2*id-i]);
		else p[i]=1;
		while (i-p[i]>=0&&i+p[i]<len&&str[i-p[i]]==str[i+p[i]])
				p[i]++;
		if (p[i]+i-1>mx){
			mx=p[i]+i-1;
			id=i;
		}
		ans=max(ans,p[i]);
	}
	return ans-1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;cin>>s;
	cout<<manacher(s);
}



����������������������������������������������������
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 32000005;
string s,str="";
string manacher(string s)
{
	string t = "$#";
	for (int i = 0; i < s.size(); ++i)
	{
		t += s[i];
		t += "#";
	}
	vector<int> p(t.size(), 0);
	int mx = 0, id = 0, r = 0, Center = 0;
	for (int i = 1; i < t.size(); ++i)
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

		while (t[i + p[i]] == t[i - p[i]])
		{
			++p[i];
		}
		if (mx < i + p[i])
		{
			mx = i + p[i]; //mx�������µ�ǰ����Ĵ������쵽�����ұߵ�λ��
			id = i; //id�������浱ǰ����Ĵ�������λ��
		}
		if (r < p[i])
		{
			r = p[i]; //r�������°뾶�ĳ���
			Center = i; //center������¼����Ĵ�����λ��
		}
	}
	//��Ӵ��ĳ����ǰ뾶��һ����ʼλ�����м�λ�ü�ȥ�뾶�ٳ���2
	return s.substr((Center - r) / 2, r - 1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>s;str="";
	cout<<manacher(s);
}

������������������������������������������������������������
ţ����ϰ��������
https://ac.nowcoder.com/acm/problem/14517

#pragma GCC optimize(2)
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
string s;
int manacher(string s)
{
   string str="$";
   int len=s.size(),mx=0,id=0,ans=0;
   for(int i=0;i<len;i++)str+='#',str+=s[i];
   str+='#';
   len=str.size();
   vector<int>p(len+1,0);
   for(int i=1;i<=len;i++){
      p[i]=i<mx?min(mx-i,p[2*id-i]):1;
      while(i-p[i]>=1&&i+p[i]<=len&&str[i-p[i]]==str[i+p[i]])p[i]++;
      if(p[i]+i>mx)mx=p[i]+i,id=i;
      ans=max(ans,p[i]);
   }
   return ans-1;
}
int main()
{
   ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
   while(cin>>s){
      cout<<manacher(s)<<endl;
   }
}