#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
const int maxn=1100;
int n,e[maxn][maxn],fn,mn;
int cx[maxn],cy[maxn];
int book[maxn];
struct PER
	{
    int age;
    string sex,music,sport;
  	}
  
fper[maxn],mper[maxn]; 
int ok(struct PER a, struct PER b);
int maxmatch();
int dfs(int u); 
int main()
  {
      int T,i,j;
      int x;
      char s1[100],s2[100],s3[100];
      scanf("%d",&T);
      while(T--){
          scanf("%d",&n);
          fn=mn=0;
          for(i=0;i<n;i++)
			  {
              scanf("%d%s%s%s",&x,s1,s2,s3);
              if(strcmp(s1,"F") == 0)
			  	  {
                  fper[fn].age=x;
                  fper[fn].sex=s1;
                  fper[fn].music=s2;
                  fper[fn].sport=s3;
                  fn++;
              	  }
              else
			  	  {
                  mper[mn].age=x;
                  mper[mn].sex=s1;
                  mper[mn].music=s2;
                  mper[mn].sport=s3;
                  mn++;
              	  }
          	  }
          
          memset(e,0,sizeof(int)*maxn*maxn);
          for(i=0;i<mn;i++){
              for(j=0;j<fn;j++){
                  if(ok(mper[i],fper[j])) 
                      e[i][j]=1;
              }
          }
          printf("%d\n",n-maxmatch());
      }
      return 0;
  }
int ok(struct PER a, struct PER b)
{
      if(abs(a.age - b.age) > 40)
          return 0;
      if(a.sex == b.sex)
          return 0;
      if(a.music != b.music)
          return 0;
      if(a.sport == b.sport)
          return 0;
          
      return 1;
  }
int dfs(int u)
  {
      for(int i=0;i<fn;i++){
          if(book[i] == 0 && e[u][i])
		  {
              book[i]=1;
             
             if(cy[i] == -1 || dfs(cy[i]))
			 {
                 cx[u]=i;
                 cy[i]=u;
                 return 1;
             }
         }
     }    
     return 0;
 }    
 int maxmatch()
 {
     int i;
     memset(cx,-1,sizeof(cx));
     memset(cy,-1,sizeof(cy));
     int ans=0;
     for(i=0;i<mn;i++){
         if(cx[i] == -1){
             memset(book,0,sizeof(book));
             if(dfs(i))    ans++;
         }
     }
     return ans;
 }
