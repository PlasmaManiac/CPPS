// Solution to Keys
// Author: Pieter Bootsma

// Time complexity: O(h*w)
// Memory: O(h*w)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: BFS with separate queues for doors without keys

#include <iostream>
#include <queue>

using namespace std;

int h,w;
char map[105][105]; //[y][x]
bool keys[26];
bool visited[105][105];

struct pos
{
	int x,y;
	
	pos(int nx, int ny) : x(nx), y(ny) {}
};

void dostep()
{
	cin >> h >> w;
	
	// Read building
	for (int y = 0; y < h; y++)
	{
		string s;
		cin >> s;
		for (int x = 0; x < w; x++)
		{
			map[y+2][x+2] = s[x];
		}
	}
	
	h += 4;
	w += 4;
	
	// Create perimeter
	for (int y = 0; y < h; y++)
	{
		map[y][0] = map[y][w-1] = '*';
		map[y][1] = map[y][w-2] = '.';
	}
	for (int x = 1; x < w-1; x++)
	{
		map[0][x] = map[h-1][x] = '*';
		map[1][x] = map[h-2][x] = '.';
	}
	
	// Read keys
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++)
		keys[i] = false;
	if (s != "0")
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			keys[s[i] - 'a'] = true;
		}
	}
	
	// Start BFS
	queue<pos> q;
	queue<pos> doorqs[26];
	q.push(pos(1,1));
	int documents = 0;
	
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			visited[y][x] = false;
		}
	}
	
	int ds[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	while (!q.empty())
	{
		pos p = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int x = p.x + ds[i][0];
			int y = p.y + ds[i][1];
			int c = map[y][x];
			
			if (!visited[y][x])
			{
				visited[y][x] = true;
				if (c == '*')
				{
					continue;
				}
				
				if (c == '$')
				{
					documents++;
				}
				else if ((c >= 'a') && (c <= 'z'))
				{ // Key found
					if (!keys[c - 'a'])
					{
						keys[c - 'a'] = true;
						queue<pos> &doorq = doorqs[c - 'a'];
						while (!doorq.empty())
						{
							q.push(doorq.front());
							doorq.pop();
						}
					}
				}
				else if ((c >= 'A') && (c <= 'Z'))
				{ // Door found
					if (!keys[c - 'A'])
					{
						doorqs[c - 'A'].push(pos(x,y));
						continue;
					}
				}
				
				q.push(pos(x,y));
			}
		}
	}
	
	cout << documents << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
