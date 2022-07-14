#include <iostream>
using namespace std;
int main()
{
    int t,u,a,w,s,r,max=0,w2=0,a2=0;
    cin>>t;
    int ar[t];
    for(u=0; u<t;u++)
	{
      cin>>ar[u];
	 }
    for(a=0;a<t;a++)
	{
      for(w=a;w<t+1;w++)
	  {
        s=0;
        for(r=a;r<w;r++) 
		{
          s+=ar[r];
		}
          if(max<s)
		  {
            max=s;
            a2=a;
            w2=w;
           }
       }
    }
     cout<<ar[a2];
     for(u=a2+1;u<w2;u++)
	 {
      cout<<" "<<ar[u];
	 }
     cout<<endl;
  return 0;
  }
