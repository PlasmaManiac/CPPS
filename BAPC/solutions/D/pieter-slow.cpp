// Solution to Dreaded Alternating Game
// Author: Pieter Bootsma

// Time complexity: O(V(V+E))
// Memory: O(V+E)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: decide all places, V times

#include <iostream>
#include <vector>

using namespace std;

#define MAX_VER 10005

struct vertex {
	vector<int> edges;
	bool owner_odd;
	bool visited;
	bool winner_odd; // True if odd will win from this vertex
	bool winner_fixed; // False if the winner can be influenced by earlier moves
};

vertex vertices[MAX_VER];

void determine(int idx)
{
	vertex &v = vertices[idx];
	if (v.edges.empty())
	{
		v.winner_odd = false;
		v.winner_fixed = false;
	}
	else
	{
		bool found_winner = false;
		bool found_player[2] = {false, false};
		
		for (size_t i = 0; i < v.edges.size(); i++)
		{
			vertex &w = vertices[v.edges[i]];
			// If the endpoint is won by the owner of this vertex and fixed, choose that
			if ((w.winner_odd == v.owner_odd) && w.winner_fixed)
			{
				v.winner_odd = v.owner_odd;
				v.winner_fixed = true;
				found_winner = true;
				found_player[0] = false;
				break; // Best case
			}
			else if (!w.winner_fixed)
			{
				// Prefer a vertex won by the other player, because that means we will win here
				if ((w.winner_odd != v.owner_odd) || !found_winner)
				{
					v.winner_odd = !w.winner_odd;
					v.winner_fixed = false;
					found_winner = true;
				}
				
				found_player[w.winner_odd] = true;
			}
		}
		
		if (!found_winner)
		{
			// Guaranteed lose: all endpoints fixed for other player
			v.winner_odd = !v.owner_odd;
			v.winner_fixed = true;
		}
		else if (found_player[0] && found_player[1])
		{
			// We can choose who will win, so our win is fixed
			v.winner_odd = v.owner_odd;
			v.winner_fixed = true;
		}
	}
}

void dostep()
{
	int n,c,s;
	cin >> n >> c >> s;
	
	for (int i = 1; i <= n; i++)
	{
		vertices[i].edges.clear();
		cin >> vertices[i].owner_odd;
		vertices[i].visited = false;
	}
	
	for (int i = 0; i < c; i++)
	{
		int a,b;
		cin >> a >> b;
		vertices[a].edges.push_back(b);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			determine(j);
		}
	}
	
	cout << vertices[s].winner_odd << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
