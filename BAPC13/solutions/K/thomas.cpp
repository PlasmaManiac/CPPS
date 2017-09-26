// Solution to Keys
// Author: Thomas Beuman

// Time complexity: O(26*h*w)
// Memory: O(h*w)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: Breadth-first search
//   Whenever a new key is found, go back outside and start over


#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;


char Map[100][101];
bool GotKey[26];

queue<pair<int,int> > BFSqueue;
bool Visited[100][100];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};


void initialize_queue (int h, int w)
{ int x, y;
  // Add all outside locations adjacent to the map to the queue
  BFSqueue = queue<pair<int,int> >();
  for (x = 0; x < w; x++)
  { BFSqueue.push(make_pair(x,-1));
    BFSqueue.push(make_pair(x,h));
  }
  for (y = 0; y < h; y++)
  { BFSqueue.push(make_pair(-1,y));
    BFSqueue.push(make_pair(w,y));
  }
}


int main()
{ int cases, casenr, h, w, x, y, x2, y2, i, docs;
  pair<int,int> P;
  char keys[27], c;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &h, &w);
    for (y = 0; y < h; y++)
      scanf("%s\n", Map[y]);
    scanf("%s\n", keys);

    // Determine keys in possession
    memset(GotKey, false, sizeof(GotKey));
    if (keys[0] != '0')
      for (i = 0; keys[i] != '\0'; i++)
        GotKey[keys[i]-'a'] = true;

    // Initialize
    initialize_queue(h, w);
    memset(Visited, false, sizeof(Visited));
    docs = 0;

    while (!BFSqueue.empty())
    { P = BFSqueue.front();
      BFSqueue.pop();
      x = P.first;
      y = P.second;
      
      // Try all directions
      for (i = 0; i < 4; i++)
      { x2 = x + dx[i];
        y2 = y + dy[i];

        // Check if the new location is on the map and unseen
        if (x2 >= 0 && x2 < w && y2 >= 0 && y2 < h && !Visited[y2][x2])
        { Visited[y2][x2] = true;
          c = Map[y2][x2];

          // If it's a new key: forget everything, start again from outside,
          // pretend that you had the key all along
          if (c >= 'a' && c <= 'z' && !GotKey[c-'a'])
          { GotKey[c-'a'] = true;
            // Reinitialize
            memset(Visited, false, sizeof(Visited));
            initialize_queue(h, w);
            docs = 0;
            break;
          }

          if (c == '$')
            docs++;

          // If not a wall or an unopenable door, add to BFS queue
          if (c != '*' && !(c >= 'A' && c <= 'Z' && !GotKey[c-'A']))
            BFSqueue.push(make_pair(x2,y2));
        }
      }
    }
    printf("%d\n", docs);
  }
  return 0;
}

