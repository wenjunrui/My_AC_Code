#include<bits/stdc++.h>
using namespace std;
int n,k,que[2000000],bian[2000000],sum[2000000],head=1,tail=0;
int main() {
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>sum[i];
	for(int i=1; i<=n; i++) {
		while(head<=tail&&que[tail]>=sum[i])
			tail--;
		que[++tail]=sum[i];
		bian[tail]=i;
		while(bian[head]<=i-k)
			head++;
		if(i>=k) {
			printf("%d",que[head]);
			if (i==n)
				cout<<"\n";
			else cout<<" ";
		}
	}
	head=1;
	tail=0;
	for(int i=1; i<=n; i++) {
		while(head<=tail&&que[tail]<=sum[i])
			tail--;
		que[++tail]=sum[i];
		bian[tail]=i;
		while(bian[head]<=i-k)
			head++;
		if(i>=k) {
			printf("%d",que[head]);
			if (i==n)
				cout<<"\n";
			else cout<<" ";
		}
	}
}
