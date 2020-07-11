#include <bits/stdc++.h>
using namespace std;
int n,k,ans=INT_MAX;
int dw(int x,int y)
{
	if(y==1) return x;
	if(y==x) return x;
	return (x-y+1)*y;
}
void work()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=i;j++)
	{
		int a;
		scanf("%d",&a);
		if(a<=ans&&dw(i,j)<=k)
		ans=a;
	}
	printf("%d",ans);
}
int main() {
	work();
	return 0;
}
