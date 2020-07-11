#include<bits/stdc++.h>
using namespace std;
int n,qp[6][6],kx,ky,ans,flag;
int mu[6][6]={{0,0,0,0,0,0},
              {0,1,1,1,1,1},
              {0,0,1,1,1,1},
			  {0,0,0,2,1,1},
			  {0,0,0,0,0,1},
			  {0,0,0,0,0,0}};
string s;
int jx[9]={0,1,1,-1,-1,2,2,-2,-2},
    jy[9]={0,2,-2,2,-2,1,-1,1,-1};
bool pan()
{
	for(int i=1;i<=5;i++)
	for(int j=1;j<=5;j++)
	if(mu[i][j]!=qp[i][j])
	return 0;
	return 1;
}
bool is_ok(int dep)
{
	int sum=0;
	for(int i=1;i<=5;i++)
	for(int j=1;j<=5;j++)
	if(mu[i][j]!=qp[i][j])
	sum++;
	if(sum>ans-dep+1)
	return 0;
	return 1;
}
void dfs(int x,int y,int dep)
{
	if(dep==ans)
	{
		if(pan())
		flag=1;
		return;
	}
	if(flag)
	return;
	for(int i=1;i<=8;i++)
	{
		int xx=x+jx[i];
		int xy=y+jy[i];
		if(xx>=1&&xx<=5&&xy>=1&&xy<=5)
		{
			swap(qp[x][y],qp[xx][xy]);
			if(is_ok(dep)&&!flag)
			dfs(xx,xy,dep+1);
			swap(qp[x][y],qp[xx][xy]);
		}
	}
}
int main()
{
	cin>>n;
	while(n--)
	{
		for(int i=1;i<=5;i++)
		{
			cin>>s;
			for(int j=0;j<5;j++)
			if(s[j]=='*')
			qp[i][j+1]=2,kx=i,ky=j+1;
			else qp[i][j+1]=s[j]-'0';
		}
		for(ans=0;ans<=15;ans++)
		{
			dfs(kx,ky,0);
			if(flag)
			break;
		}
		if(!flag)
		cout<<-1<<endl;
		else cout<<ans<<endl;
		flag=0;
	}
}
