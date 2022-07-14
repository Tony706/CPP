#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int n,num[310],len[310],lpre[310],npre[310];
int dp[310][310][2];
int nsum(int a,int b)
{
    int tmp=(a!=0);b=a-b;
    return npre[b]-npre[a-tmp];
}
int lsum(int a,int b)
{
    return lpre[b]-lpre[a];
}
int dfs(int a,int b,int pos)
{
    if(dp[a][b][pos]!=inf)
	{
        return dp[a][b][pos];
    }
    if(a+b>=n)
	{
        return dp[a][b][pos]=0;
    }
    if(pos==1)
	{
        dp[a][b][1]=min(dp[a][b][1],dfs(a,b+1,1)+len[n-(b+1)]*nsum(a,b+1));
        dp[a][b][1]=min(dp[a][b][1],dfs(a,b+1,0)+(lpre[a]+lsum(a-b,n))*nsum(a,b+1));
    }
    else
	{
        dp[a][b][0]=min(dp[a][b][0],dfs(a+1,b,0)+len[a]*nsum(a+1,b));
        dp[a][b][0]=min(dp[a][b][0],dfs(a+1,b,1)+(lpre[a]+lsum(n-b,n))*nsum(a+1,b));
    }
    return dp[a][b][pos];
}
int main()
{
    while(cin>>n)
	{
        if(!n)  break;
        for(int a=0;a<n;a++)
		{
            cin>>num[a]>>len[a];
        }
        lpre[0]=npre[0]=num[n]=0;
        for(int a=1;a<=n;a++)
		{
            lpre[a]=lpre[a-1]+len[a-1];
            npre[a]=npre[a-1]+num[a];
        }
        memset(dp,inf,sizeof(dp));
        int ans=min(dfs(0,0,0),dfs(0,0,1));
        printf("%d\n",ans);
    }
    return 0;
}
