#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m1,m2;
int fa[15000], ma[15000];
int find_fa(int kk)
{
	if(fa[kk]==kk)
		return kk;
	return fa[kk]=find_fa(fa[kk]);
}
int find_ma(int kk)
{
	if(ma[kk]==kk)
		return kk;
	return ma[kk]=find_ma(ma[kk]);
}
void add_fa(int xx,int yy)
{
	int faxx=find_fa(xx);
	int fayy=find_fa(yy);
	fa[faxx]=fayy;
}
void add_ma(int xx,int yy)
{
	int faxx=find_ma(xx);
	int fayy=find_ma(yy);
	ma[faxx]=fayy;
}
int main()
{
	//freopen("a.in","r",stdin);
	vector<pair<int, int> > v;
	cin>>n>>m1>>m2;
	for(int i=1;i<=2*n;i++){fa[i]=i;ma[i]=i;}

	for(int i=1,xx,yy;i<=m1;i++)
	{
		cin>>xx>>yy;
		add_fa(xx,yy);
	}
	for(int i=1,xx,yy;i<=m2;i++)
	{
		cin>>xx>>yy;
		add_ma(xx,yy);
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(find_fa(i)!=find_fa(j)&&find_ma(i)!=find_ma(j))
			{
				add_fa(i,j);
				add_ma(i,j);
				v.pb({i, j});
			}
		}
	}
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++)cout<<v[i].first<<' '<<v[i].second<<endl;
	return 0;
}
