# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int N, G;
double R;
int valid[151][151];
long dp[151][151];
struct node
{
	double x;
	double y;
}p[151];

struct Node
{
	double x;
	double y;
}c[151];

int check(int i, int j)
{
	int q;
	double A, B, C, D, E;

	for(q = 0; q < G; q++)
	{
		A = p[j].x-p[i].x; B = p[i].y-p[j].y; C = p[j].y*p[i].x-p[i].y*p[j].x;
		D = (A*c[q].y+B*c[q].x+C);
		E = A*A*c[q].x-B*C-A*B*c[q].y;
		if(D*D<=R*R*(A*A+B*B))
		{
			if((c[q].x-p[i].x)*(c[q].x-p[i].x)+(c[q].y-p[i].y)*(c[q].y-p[i].y)<R*R)
				return 0;
			if((c[q].x-p[j].x)*(c[q].x-p[j].x)+(c[q].y-p[j].y)*(c[q].y-p[j].y)<R*R)
				return 0;
			if(p[j].x!=p[i].x)
			{
				if((E-p[i].x*(A*A+B*B))*(E-p[j].x*(A*A+B*B))<0)	
		    		return 0;
			}
			if(p[j].x==p[i].x&&E==p[i].x*(A*A+B*B))
				return 0;
		}
	}
	return 1;
}

void init()
{
	int i, j;

	for(i = 0; i < N; i++)
		for(j = i; j < N; j++)
			if(i==j||abs(j-i)==1||abs(j-i)==N-1)
			{
				dp[i][j] = dp[j][i] = 0;
				valid[i][j] = valid[j][i] = 0;
			}
			else
				valid[i][j] = valid[j][i] = check(i,j);
}

void input()
{
	int i, j, t, k;
	long MAX = 0, max;

	scanf("%d%d%lf",&N,&G,&R);
	for(i = 0; i < N; i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(i = 0; i < G; i++)
		scanf("%lf%lf",&c[i].x,&c[i].y);
	init();
	for(t = 2; t < N; t++)
	{
		for(i = 0; i < N; i++)
		{
			j = i+t;
			max = 0;
			for(k = i+1; k < j; k++)
				if(dp[i][k%N]+dp[k%N][j%N]>max)
					max = dp[i][k%N]+dp[k%N][j%N];
			dp[i][j%N] = max;
			dp[i][j%N] += valid[i][j%N];
		}
	}
	for(i = 0; i < N; i++)
		if(dp[i][i-1<0?(N-1):(i-1)]>MAX)
			MAX = dp[i][i-1<0?(N-1):(i-1)];
	printf("%ld\n",MAX);
}

int main()
{
	input();
	return 1;
}
