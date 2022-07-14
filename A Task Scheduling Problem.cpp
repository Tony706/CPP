#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct node
{
	int date;
	int cost;
};
bool cmp(node aa, node bb)
	{
	if (aa.cost != bb.cost)
		return aa.cost > bb.cost;
	else
		return aa.date < bb.date;
	}
int main()
{
	int n;
	node s[10000];
	while (cin >> n)
		{
		for (int u = 0; u < n; u++)
			cin >> s[u].date;
		
		for (int u = 0; u < n; u++)
			{
			cin >> s[u].cost;
			}
			
		sort(s, s + n, cmp);
		int cnt = 0;
		int vis[1000] = { 0 };
		
		for (int u = 0; u < n; u++)
			{
			if (vis[s[u].date] == 0)
				{
				vis[s[u].date] = 1;
				}
			else
				{
				int flag = 0;
				for (int k = s[u].date; k >= 1; k--)
					{
					if (vis[k] == 0)
						{
						vis[k] = 1;
						flag = 1;
						break;
						}
					}
				if (flag == 0)
					{
					cnt += s[u].cost;
					}
				}
			}
		cout << cnt << endl;
		}
	return 0;
}

