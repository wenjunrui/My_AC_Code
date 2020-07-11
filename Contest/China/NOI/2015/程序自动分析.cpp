#include<bits/stdc++.h>
using namespace std;
struct zuo{
	int a,b,e;
}cao[1000000];
int n,a,b,c,t,myd[2*1000010],fa[2000010],tot=0;
bool flag=0;
int get(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y)
{
	fa[get(x)]=get(y);
}
bool pan(int x,int y)
{
	return get(x)==get(y);
}
void discrete()
{
	sort(myd,myd+tot);
	tot=unique(myd,myd+tot)-myd;
}
int query(int x)
{
	return lower_bound(myd,myd+tot,x)-myd;
}
bool cmp(zuo a,zuo b)
{
	return a.e>b.e;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		memset(cao,0,sizeof(cao));
		memset(fa,0,sizeof(fa));
		memset(myd,0,sizeof(myd));
		tot=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&cao[i].a,&cao[i].b,&cao[i].e);
			myd[++tot]=cao[i].a;
			myd[++tot]=cao[i].b;
		}
		discrete();
		for(int i=1;i<=n;i++)
		{
			cao[i].a=query(cao[i].a);
			cao[i].b=query(cao[i].b);
		}
		sort(cao+1,cao+n+1,cmp);
		for(int i=1;i<=tot;i++)
		fa[i]=i;
		for(int i=1;i<=n;i++)
		{
			if(cao[i].e==1)
			merge(cao[i].a,cao[i].b);
			else
			if(pan(cao[i].a,cao[i].b))
			{flag=1;break;}
		}
		if(flag)
		printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
