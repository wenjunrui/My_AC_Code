#include<bits/stdc++.h>
#define ull unsigned long long
ull po1[2000010],ha1[2000010],x,y,kk;
char st[2000010];
int n,ans,ss,lo;
void init() {
 po1[0]=1;
 for(int i=1;i<=n;i++) {
  po1[i]=po1[i-1]*131;
  ha1[i]=ha1[i-1]*131+st[i];
 }
}
int main() {
 scanf("%d%s",&n,st+1);
 if(n%2==0) {
  puts("NOT POSSIBLE");
  return 0;   	
 }
 init();
 for(int i=1;i<=n;i++) {//ABXCABC
  if(i<=n/2) x=ha1[n/2+1]-ha1[i]*po1[n/2-i+1]+ha1[i-1]*po1[n/2-i+1];
  else x=ha1[n/2];
  if(i<=n/2+1) y=ha1[n]-ha1[n-n/2]*po1[n/2];
  else y=(ha1[i-1]-ha1[n/2]*po1[i-n/2-1])*po1[n-i]+ha1[n]-ha1[i]*po1[n-i];
  if(x==y) {
   if(ans&&kk!=x) {
    puts("NOT UNIQUE");
	return 0;	 
   }
   ans=1,kk=x,ss=i;
  }
 }
 if(!ans)
  puts("NOT POSSIBLE");
 else {
  for(int i=1;lo<n/2;i++)
   if(i!=ss)
    printf("%c",st[i]),lo++;
 }
}
