#include <algorithm>
#include <iostream>

#define INF 1e8

#define OPEN 2
#define NORMAL 1
#define CLOSE 0

using namespace std;

int n, m, k;

int dfs(int i, int j1, int j2, int st1, int st2, int stones, int enclosed) {
  if(i == n || j1 > j2) return INF;

  if(i == 0) { stones += j2 - j1 + 1; }
  else { stones += (j1 == j2 ? 1 : 2); }

  enclosed += j2 - j1 + 1;

  int best = INF;
  if(enclosed >= k) {
    if(i == 0) { best = stones; }
    else { best = stones + max(0, j2 - j1 - 1); }
  }

  if(st1 == OPEN && j1 > 0) {
    if(st2 == OPEN && j2 < m - 1)
      best = min(best, dfs(i + 1, j1 - 1, j2 + 1, OPEN, OPEN, stones, enclosed));
    if(st2 >= NORMAL)
      best = min(best, dfs(i + 1, j1 - 1, j2, OPEN, NORMAL, stones, enclosed));
    best = min(best, dfs(i + 1, j1 - 1, j2 - 1, OPEN, CLOSE, stones, enclosed));
  }

  if(st1 >= NORMAL) {
    if(st2 == OPEN && j2 < m - 1)
      best = min(best, dfs(i + 1, j1, j2 + 1, NORMAL, OPEN, stones, enclosed));
    if(st2 >= NORMAL)
      best = min(best, dfs(i + 1, j1, j2, NORMAL, NORMAL, stones, enclosed));
    best = min(best, dfs(i + 1, j1, j2 - 1, NORMAL, CLOSE, stones, enclosed));
  }

  if(st2 == OPEN && j2 < m - 1)
    best = min(best, dfs(i + 1, j1 + 1, j2 + 1, CLOSE, OPEN, stones, enclosed));
  if(st2 >= NORMAL)
    best = min(best, dfs(i + 1, j1 + 1, j2, CLOSE, NORMAL, stones, enclosed));
  best = min(best, dfs(i + 1, j1 + 1, j2 - 1, CLOSE, CLOSE, stones, enclosed));

  return best;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> m >> k;

    int best = INF;
    for(int j1 = 0; j1 < m; j1++) {
      for(int j2 = j1; j2 < m; j2++) {
        best = min(best, dfs(0, j1, j2, OPEN, OPEN, 0, 0));
      }
    }
    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
