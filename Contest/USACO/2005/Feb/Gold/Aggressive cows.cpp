#include<bits/stdc++.h>
using namespace std;
const int ioi=1e5+10;
int x[ioi],n,m,l=0,r;
bool pan(int d)
{
	int cow=1;
	int rgt=x[1]+d;
	for(int i=1;i<=n;i++)
	{
		if(x[i]<rgt)
		continue;
		++cow;
		rgt=x[i]+d;
	}
	return cow>=m;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	sort(x+1,x+n+1);
	r=x[n]-x[1];
	while(l<=r)
	{
		int mid=l+r>>1;
		if(pan(mid))
		l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}
