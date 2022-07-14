#include <iostream>
using namespace std;

int p[1010];
int m[1010][1010];
int s[1010][1010];
int n;
void Traceback(int i, int j)
	{
    
	if(i == j)
    {
    cout << "A" << i;
    return;
    }
    else
    {
    cout << "(";
    Traceback(i, s[i][j]);
    Traceback(s[i][j] + 1, j);
    cout << ")";
    }
	}
void MatrixChain()
	{
    for(int i = 1; i <= n; ++i)
    m[i][i] = 0;
    for(int r = 2; r <= n; ++r)
    
	for(int i = 1; i <= n - r + 1; ++i)
    {
    int j = i + r - 1;
    m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
    s[i][j] = i;
    
	for(int k = i + 1; k < j; ++k)
    {
    int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
    if(m[i][j] > t)
    {
    m[i][j] = t;
    s[i][j] = k;
    }
    }
    }
	}
void Input()
	{
    scanf("%d", &n);
    
    for(int i = 0; i <= n; ++i)
    scanf("%d", &p[i]);
	}
int main()
	{
    Input();
    MatrixChain();
    
    if(n==1)
    {
    cout << "0" << endl;
    cout << "(A1)" << endl;
    }
    else
    {     
	cout<<m[1][n];
    cout << endl;
    Traceback(1, n);cout << endl;
    }
	}
