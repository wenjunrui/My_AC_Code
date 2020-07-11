#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,mu[61],ban[1010],qzh[1010],sum,ok=0,ans=0;
void dfs(int l,int r,int hao,int lim)
{
	if(r==0)
	{
		ok=1;
		return;
	}
	if(hao>lim)
		return;
	for(int i=l; i<=m; i++)
		if(mu[i]>=ban[r])
		{
			mu[i]-=ban[r];
			if(mu[i]<ban[1])
				hao+=mu[i];
			l=(ban[r]==ban[r-1]?i:1);
			dfs(l,r-1,hao,lim);
			if(ok)
			{
				mu[i]+=ban[r];
				return;
			}
			mu[i]+=ban[r];
		}
}
signed main()
{
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>mu[i];
		sum+=mu[i];
	}
	sort(mu+1,mu+m+1,greater<int>());
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>ban[i];
	sort(ban+1,ban+n+1);
	for(int i=1; i<=n; i++)
		qzh[i]=qzh[i-1]+ban[i];
	int r=n,l=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		ok=0;
		dfs(1,mid,0,sum-qzh[mid]);
		if(ok)
		{
			if(ans<mid)
				ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}
