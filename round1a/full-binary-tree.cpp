#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 1000
#define INF 1e8

using namespace std;

int n;
vector<int> adjs[MAXN];

bool visited[MAXN];

int dfs(int k) {
  visited[k] = true;

  vector<int> counts;
  for(int i = 0; i < adjs[k].size(); i++) {
    if(!visited[adjs[k][i]])
      counts.push_back(dfs(adjs[k][i]));
  }

  int children = counts.size();
  if(counts.size() <= 1) return 1;

  sort(counts.begin(), counts.end());
  return 1 + counts[children - 1] + counts[children - 2];
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n;

    for(int i = 0; i < n; i++)
      adjs[i].clear();

    for(int i = 0; i < n - 1; i++) {
      int a, b; cin >> a >> b;
      adjs[--a].push_back(--b);
      adjs[b].push_back(a);
    }

    int best = n - 1;
    for(int i = 0; i < n; i++) {
      memset(visited, false, sizeof(visited));
      best = min(best, n - dfs(i));
    }
    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
