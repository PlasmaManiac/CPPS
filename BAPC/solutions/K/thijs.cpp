// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

string map[105];
bool visited[105][105];
bool key[26];
vector<pair<int, int> > doors[26];
queue<pair<int,int> >  q;
int ndocs;
int h, w;

void check(int x, int y)
{
	if (visited[x][y] || map[x][y]=='*')
		return;
	if (map[x][y]>='a'&&map[x][y]<='z')
	{
		int k=map[x][y]-'a';
		key[k]=true;
		map[x][y]='.';
		for (int i=0; i<doors[k].size(); i++)
			q.push(doors[k][i]);
	}
	if (map[x][y]>='A'&&map[x][y]<='Z')
	{
		if (key[map[x][y]-'A'])
			map[x][y]='.';
		else
			doors[map[x][y]-'A'].push_back(make_pair(x,y));
	}
	if (map[x][y]=='$')
	{
		ndocs++;
		map[x][y]='.';
	}
	if (map[x][y]=='.')
	{
		visited[x][y]=true;
		if (x>0 && !visited[x-1][y] && map[x-1][y]!='*')
			q.push(make_pair(x-1,y));
		if (x<h-1 && !visited[x+1][y] && map[x+1][y]!='*')
			q.push(make_pair(x+1,y));
		if (y>0 && !visited[x][y-1] && map[x][y-1]!='*')
			q.push(make_pair(x,y-1));
		if (y<w-1 && !visited[x][y+1] && map[x][y+1]!='*')
			q.push(make_pair(x,y+1));
	}
}

void doStep()
{
	memset(visited, 0, sizeof(visited));
	for(int i=0; i<26; i++)
	{
		key[i]=false;
		doors[i].clear();
	}
	ndocs=0;
	
	cin>>h>>w;
	for (int i=0; i<h; i++)
		cin>>map[i];
	string keys;
	cin>>keys;
	if (keys!="0")
	{
		for (int i=0; i<(int)keys.size(); i++)
			key[keys[i]-'a']=true;
	}
	for (int i=0; i<h; i++)
	{
		check(i, 0);
		check(i, w-1);
	}
	for (int i=0; i<w; i++)
	{
		check(0, i);
		check(h-1, i);
	}
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		check(p.first, p.second);
	}
	cout<<ndocs<<endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
