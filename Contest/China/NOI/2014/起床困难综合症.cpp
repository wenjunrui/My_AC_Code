#include<bits/stdc++.h>
using namespace std;
int wo[100100];
string wo_[100100];
int n,m,v,ans;
int work(int bit,int now)
{
	for(int i=1;i<=n;i++)
	{
		int x=wo[i]>>bit&1;
		if(wo_[i]=="AND") now&=x;
		else if(wo_[i]=="OR") now|=x;
		else if(wo_[i]=="XOR") now^=x;
		//printf("%d\n",now);
	    //for(int i=1;i<=1<<26;i++);
	}
	return now;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>wo_[i];
		scanf("%d",&wo[i]);
	}
	for(int bit=29;bit>=0;bit--)
	{
		//printf("NO.%d   ",bit);
		int t0=work(bit,0);
		int t1=work(bit,1);
		if(v+(1<<bit)<=m&&t0<t1)
		v+=1<<bit,ans+=t1<<bit;
		else ans+=t0<<bit;
	}
	printf("%d",ans);
}
