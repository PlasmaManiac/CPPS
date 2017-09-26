// Solution to Fare Dodging
// Author: Pieter Bootsma

// Time complexity: O((n + m) * log n)
// Memory: O(n + m)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: Dijkstra on two-layered graph

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cstdio>

using namespace std;

#define MAX_VER 405
#define INFINITE 9e30

struct edge
{
	int to;
	double length;
	edge(int to, double length)
		: to(to), length(length)
	{}
};

struct vertex
{
	vector<edge> edges;
	double dis;
};

vertex vertices[MAX_VER];

void reset()
{
	for (int i=0; i < MAX_VER; i++)
	{
		vertices[i].edges.clear();
		vertices[i].dis = INFINITE;
	}
}

void addedge(int from, int to, double length, bool directed)
{
	vertices[from].edges.push_back(edge(to, length));
	if (!directed)
		vertices[to].edges.push_back(edge(from, length));
}

typedef pair<double, int> pp;

void dijkstra(int source)
{
	//distance, vertex
	priority_queue<pp, vector<pp>, greater<pp> > q;
	vertices[source].dis = 0;
	q.push(make_pair(0., source));
	
	while (!q.empty())
	{
		int u = q.top().second;
		double dis = q.top().first;
		q.pop();
		
		if (dis > vertices[u].dis)
			continue;
		
		for (size_t i = 0; i < vertices[u].edges.size(); i++)
		{
			edge &e = vertices[u].edges[i];
			if (dis + e.length < vertices[e.to].dis)
			{
				vertices[e.to].dis = dis + e.length;
				q.push(make_pair(vertices[e.to].dis, e.to));
			}
		}
	}
}


void dostep()
{
	reset();
	
	int n,m,start,end,s,p,y;
	cin >> n >> m >> start >> end >> s >> p >> y;
	
	for (int i = 1; i <= n; i++)
	{
		addedge(i, i+n, s, true);
		addedge(i+n, i, 0, true);
	}
	
	for (int i = 0; i < m; i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		addedge(a, b, ((y+d*p)*c)/100., false);
		addedge(a+n, b+n, d*p, false);
	}
	
	dijkstra(start);
	
	printf("%.2f\n", vertices[end].dis);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
