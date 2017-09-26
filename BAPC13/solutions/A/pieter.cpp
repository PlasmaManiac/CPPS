// Solution to Satellite Coverage
// Author: Pieter Bootsma

// Time complexity: O(n^2 log n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: sweeping line

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct rect
{
	int x1,y1,x2,y2;
	
	rect() {}
	rect(int X1, int Y1, int X2, int Y2) : x1(X1), y1(Y1), x2(X2), y2(Y2) {}
	
	bool operator<(const rect &r) const
	{
#define CMP(a) if (a != r.a) { return a < r.a; }
		CMP(y1);
		CMP(y2);
		CMP(x1);
		CMP(x2);
		
		return false;
	}
};

int nrects;
rect rects[1005];

struct event
{
	rect r;
	bool start;
	
	event(rect R, bool S) : r(R), start(S) {}
	
	int x() const
	{
		return (start ? r.x1 : r.x2);
	}
	
	bool operator<(const event &e) const
	{
		if (x() == e.x())
		{
			return start > e.start;
		}
		return x() > e.x();
	}
};

priority_queue<event> pq;
set<rect> state;

void dostep()
{
	cin >> nrects;
	for (int i = 0; i < nrects; i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		rects[i] = rect(a,b,c,d);
		pq.push(event(rects[i], true));
		pq.push(event(rects[i], false));
	}
	
	// Handle events
	long long cur_height = 0;
	long long last_x = 0;
	long long area = 0;
	while (!pq.empty())
	{
		event e = pq.top();
		pq.pop();
		long long x = e.x();
		
		// Add size since previous event
		area += cur_height * (x - last_x);
		last_x = x;
		
		if (e.start)
		{
			state.insert(e.r);
		}
		else
		{
			state.erase(e.r);
		}
		
		// Walk through state and determine height
		cur_height = 0;
		int start = 0;
		int end = 0;
		for (set<rect>::iterator it = state.begin(); it != state.end(); it++)
		{
			if (it->y1 > end)
			{
				cur_height += (end - start);
				start = it->y1;
			}
			
			end = max(end, it->y2);
		}
		cur_height += (end - start);
	}
	
	cout << area << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
