#include<iostream>
#include<cstdio>
using namespace std;
const int MAX_N=10001;
const int INF=1000001;
int N,ML,MD;
int AL[MAX_N],BL[MAX_N],DL[MAX_N];
int AD[MAX_N], BD[MAX_N],DD[MAX_N];
int d[MAX_N];
void solve()
	{
		fill(d,d+N,INF);
		d[0]=0;
		for(int k=0;k<N;++k){
			for(int i=0;i+1<N;++i){
				if(d[i+1]<INF)
				{
					d[i]=min(d[i],d[i+1]);
				}
			}
		for(int i=0;i<ML;++i){
			if(d[AL[i]-1]<INF)
			{
				d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
				
			}
		}
		for(int i=0;i<MD;++i){
			if(d[BD[i]-1]<INF){
				d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
				
			}
		}
		}
		int res=d[N-1];
		if(d[0]<0){
			res=-1;
		} else if(res==INF){
			res = -2;
		}
		cout<<res<<"\n";
		
	}
int main()
{
	while(scanf("%d%d%d",&N,&ML,&MD) != EOF){
		for(int i=0;i<ML;++i){
			scanf("%d%d%d",&AD[i],&BD[i],&DD[i]);
		}
		solve();
	} 
	return 0;
}
