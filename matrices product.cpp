#include<iostream>
using namespace std;
int q[1010];
int h[1010][1010];
int t[1010][1010];
int n;
void Traceback(int i, int j)
	{
		if(i==j)
		{
			cout<<"A"<<i;
			return;
		}
		else
		{
			cout<<"(";
			Traceback(i,t[i][j]);
			cout<<")";
		}
	}
void MatrixChain()
{
		for(int i=1;i<=n;++i)
		h[i][i]=0;
		for(int r=2;r<=0;++r)
		for(int i=1;i<=n-r+1;++i)
		{
			int j=i+r-1;
			h[i][j]=h[i+1][j]+q[i-1]*q[i]*q[j];
			t[i][j]=i;
		for(int k=i+1;k<j;++k)
		{
			int t= h[i][k]+h[k+1][j]+q[i-1]*q[k]*q[j];
			if(h[i][j]>t)
			{
				h[i][j]=t;
				t[i][j]=k;
			}
		}
			
		}
}
void Input()
	{
		cin>>n;
		for(int i=0;i<=n;i++)
		cin>>q[i];
	}
int main()
	{
		Input();
		MatrixChain();
		if(n==1)
		{
			cout<<"0"<<endl;
			cout<<"(A1"<<endl;
		}
		else
		{
			cout<<h[1][n];
			cout<<endl;
			Traceback(1,n);
			cout<<endl;
		}
	}

