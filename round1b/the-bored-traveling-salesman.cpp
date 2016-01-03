#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

#define ll long long

#define MAXN 50

#define NOT_VISITED 0
#define IN_PATH 1
#define LOCKED 2

using namespace std;

int n;
int codes[MAXN];
vector<int> adjs[MAXN];
bool adjMatrix[MAXN][MAXN];

int order[MAXN];
int status[MAXN];
bool visited[MAXN];

vector<int> solution;

bool codeOrder(int a, int b) { return codes[a] < codes[b]; }

bool isReachable(int node) {
  if(status[node] == LOCKED) return false;
  if(status[node] == IN_PATH) return true;

  if(visited[node]) return false;
  visited[node] = true;

  bool reachable = false;
  for(int i = 0; i < adjs[node].size(); i++) {
    if(isReachable(adjs[node][i])) reachable = true;
  }
  return reachable;
}

void search() {
  stack<int> path;
  path.push(order[0]);
  solution.push_back(codes[order[0]]);
  status[order[0]] = IN_PATH;

  while(solution.size() < n) {
    for(int i = 1; i < n; i++) {
      int node = order[i];
      if(status[node] != NOT_VISITED) continue;

      stack<int> left;
      while(!path.empty() && !adjMatrix[path.top()][node]) {
        left.push(path.top());
        status[path.top()] = LOCKED;
        path.pop();
      }

      status[node] = IN_PATH;
      bool canLock;

      if(path.empty()) {
        canLock = false;
      } else {
        memset(visited, false, sizeof(visited));
        canLock = true;
        for(int i = 0; i < n; i++) {
          if(status[i] == NOT_VISITED && !visited[i] && !isReachable(i)) {
            canLock = false; break;
          }
        }
      }

      if(!canLock) {
        while(!left.empty()) {
          path.push(left.top());
          status[left.top()] = IN_PATH;
          left.pop();
        }
        status[node] = NOT_VISITED;
        continue;
      }

      path.push(node);
      solution.push_back(codes[node]);
      break;
    }
  }
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int m; cin >> n >> m;

    for(int i = 0; i < n; i++) {
      cin >> codes[i];
      adjs[i].clear();
      order[i] = i;
    }

    memset(adjMatrix, false, sizeof(adjMatrix));

    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--; b--;
      adjs[a].push_back(b);
      adjs[b].push_back(a);
      adjMatrix[a][b] = adjMatrix[b][a] = true;
    }

    sort(order, order + n, codeOrder);
    memset(status, 0, sizeof(status));
    solution.clear();
    search();

    cout << "Case #" << tc << ": ";
    for(int i = 0; i < solution.size(); i++)
      cout << solution[i];
    cout << endl;
  }
  return 0;
}
