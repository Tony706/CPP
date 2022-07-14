#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000
#define INFTY (1<<29)
using namespace std;
class DisjointSet
	{
	public:
		vector<int> rank, p;
		
		DisjointSet() {}
		
		DisjointSet(int size)
			{
			rank.resize(size, 0);
			p.resize(size, 0);
			for(int g = 0; g < size; g++) makeSet(g);
			} 
		
		void makeSet(int x)
			{
			p[x] = x;
			rank[x] = 0;
			}
		
		bool same(int x, int y)
			{
			return findSet(x) == findSet(y);
			}
		
		void unite(int x, int y)
			{
			link(findSet(x), findSet(y));
			}
		
		void link(int x, int y)
			{
			if(rank[x] > rank[y])
				{
				p[y] = x;
				}
			else
				{
				p[x] = y;
				if(rank[x] == rank[y])
					{
					rank[y]++;
					}
				}
			}
		
		int findSet(int x)
			{
			if(x != p[x])
				{
				p[x] = findSet(p[x]);
				}
			return p[x];
			}
	}; 
class Edge
	{
	public:
		int source, target, cost;
		Edge(int source = 0, int target = 0, int cost = 0):
			source(source), target(target), cost(cost) {}
			bool operator < (const Edge &e) const{
				return cost < e.cost; 
			}
	};
int kruskal(int Q, vector<Edge> edges)
{
	int totalCost = 0;
	sort(edges.begin(), edges.end());
	DisjointSet dset = DisjointSet(Q + 1);
	for(int g = 0; g < Q; g++) dset.makeSet(g);
	
	for(int g = 0; g < edges.size(); g++)
		{
		Edge e = edges[g];
		if(!dset.same(e.source, e.target))
			{
			totalCost += e.cost;
			dset.unite(e.source, e.target); 
			}
		}
	return totalCost;
}
int main()
{
	int Q, M, cost;
	int source, target;
	scanf("%d%d", &Q, &M);
	vector<Edge> edges;
	
	if(Q > M)
		{
		cout << "impossible" << endl;
		}
	else
		{
		for(int g = 0; g < M; g++)
			{
			scanf("%d%d%d", &source, &target, &cost);
			edges.push_back(Edge(source, target, cost));
			}
			cout<<kruskal(Q, edges)<<endl;
		}
	return 0;
}

