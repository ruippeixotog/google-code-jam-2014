#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

#define MAXN 1000
#define INF 0x3f3f3f3f

using namespace std;

int a[MAXN];

int order[MAXN], dp[MAXN + 1][MAXN + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    iota(order, order + n, 0);
    sort(order, order + n, [](int i, int j) {return a[i] < a[j]; });

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int k = 0; k < n; k++) {
      int currOrder = order[k];
      for(int i = 0; i < k; i++) {
        if(order[i] < order[k]) currOrder--;
      }
      for(int i = 0; i <= k; i++) {
        int j = k - i;
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + currOrder);
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + n - k - 1 - currOrder);
      }
    }
    int best = INF;
    for(int i = 0; i <= n; i++) {
      best = min(best, dp[i][n - i]);
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
