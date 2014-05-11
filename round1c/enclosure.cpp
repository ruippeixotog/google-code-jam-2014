#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 20
#define MAXM 20
#define INF 1e8

using namespace std;

int n, m, k;

bool selected[MAXN][MAXM];
bool visited[MAXN][MAXM];

int ffill(int i, int j) {
  if(i < 0 || j < 0 || i >= n || j >= m ||
    visited[i][j] || selected[i][j]) return 0;

  visited[i][j] = true;

  return 1 + ffill(i + 1, j) + ffill(i - 1, j) +
    ffill(i, j + 1) + ffill(i, j - 1);
}

int numEnclosed() {
  memset(visited, false, sizeof(visited));

  int count = 0;
  for(int i = 0; i < n; i++) {
    count += ffill(i, 0);
    count += ffill(i, m - 1);
  }
  for(int j = 0; j < m; j++) {
    count += ffill(0, j);
    count += ffill(n - 1, j);
  }
  return n * m - count;
}

int dfs(int i, int j) {
  if(j >= m) { j = 0; i++; }
  if(i >= n) {
    return numEnclosed() >= k ? 0 : INF;
  }

  int res = dfs(i, j + 1);
  selected[i][j] = true;
  res = min(res, dfs(i, j + 1) + 1);
  selected[i][j] = false;

  return res;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> m >> k;

    memset(selected, false, sizeof(selected));
    int res = dfs(0, 0);

    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
