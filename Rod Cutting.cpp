#include <iostream>  
#include <algorithm>  
  
using namespace std;  
int Rodcount;  
int extendedBottomUpCutRod(int p[], int rods[], int n)  
{  
    int value[n+1],PRod[n+1];  
    int i,j;  
    value[0] = 0;  
    for (i = 1; i<=n; i++)  
        {  
        int max = -10000;  
        int best_rod = -1;  
        for (j = 0; j < i; j++)  
          {  
            if(max < p[j] + value[i-j-1])  
              {  
                max = p[j] + value[i-j-1];  
                best_rod = j;  
  
                }  
        }  
        value[i] = max;  
        PRod[i] = best_rod + 1;  
    }  
    for (i = n, j = 0; i>0; i -= PRod[i])  
      {  
        rods[j++] = PRod[i];  
        }  
    Rodcount = j;  
    return value[n];  
        }  
  
int main()  
  {  
    int p[50],k,n,rods[n+1];  
    int i,l =0,result[l];  
  
    cin>>n;  
    for(k=0;k<n;k++)  
    {  
      cin>>p[k];  
    }  
      
  
    cout<<extendedBottomUpCutRod(p, rods, n)<<endl;  
    result[l++]=(rods[0]);  
    for(i = 1; i < Rodcount; i++)  
    {  
      result[l++]=(rods[i]);  
    }  
    sort(result,result+l,greater<int>());  
    cout<<result[0];  
  
    for(i =1;i<l;i++)  
    {  
      cout<<" "<<result[i];  
    }  
    cout<<endl;  
  
    return 0;  
  }
