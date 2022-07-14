#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans[30][30],f[30],d[30],t[30];

int main()
{
int h,n;
cin>>n;
while(true)
{
if(n==0)break;

cin>>h;
h*=12;
memset(ans,0,sizeof(ans));
memset(f,0,sizeof(f));
memset(t,0,sizeof(t));
memset(d,0,sizeof(d));

for(int i=1;i<=n;++i)
{
scanf("%d ",&f[i]);
}

for(int i=1;i<=n;++i)
{
scanf("%d ",&d[i]);
}
for(int i=1;i<n;++i)
{
scanf("%d ",&t[i]);
}

int ht,ft[30];
for(int ed=1;ed<=n;++ed)
{
memset(ft,0,sizeof(ft));
for(int i=1;i<=ed;++i)
{
ft[i]=f[i];
}
ht=h;
for(int i=1;i<ed;++i)
{
ht-=t[i];
}

int k,emp=1;
while(ht>0&&emp<=ed)
{
k=1;
for(int j=emp;j<=ed;++j)
{
if(ft[j]>ft[k])
{
k=j;
}
}

ans[ed][0]+=ft[k];
++ans[ed][k];
--ht;
ft[k]-=d[k];
ft[k]=ft[k]>0?ft[k]:0;
for(int j=emp;j<=ed;++j)
{
if(ft[j]==0)++emp;
else
break;
}
}
if(ht>0)ans[ed][1]+=ht;
}

int a=1;
for(int i=2;i<=n;++i)
{
if(ans[i][0]>ans[a][0])a=i;
}

for(int i=1;i<=n;++i)
{
cout<<ans[a][i]*5;
if(i!=n)cout<<", ";
}
cout<<endl;
cout<<"Number of fish expected: "<<ans[a][0]<<endl;

cin>>n;
if(n!=0)cout<<endl;
}
return 0;
}
