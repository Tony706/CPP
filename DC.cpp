#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 20001
using namespace std;
string s1,s2;
int map[maxn];
void input()
{
while(cin>>s1>>s2)
{
memset(map,0,sizeof(map));
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
int len1=s1.length();
int len2=s2.length();
for(int i=0;i<len1;i++)
{
for(int j=0;j<len2;j++)
{
map[i+j]+=(s1[i]-'0')*(s2[j]-'0');
}
}
for(int i=0;i<maxn-1;i++)
{
map[i+1]+=map[i]/10;
map[i]%=10;
}
int i;
for(i=maxn-1;i>=0;i--)
{
if(map[i]!=0)break;
}
if(i==-1)cout<<"0";
else
for(int j=i;j>=0;j--)
cout<<map[j];
cout<<endl;
}
}
int main()
{
input();
return 0;
}
