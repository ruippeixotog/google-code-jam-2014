#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

#define siterator set<int>::iterator

#define MAXN 1000
#define INF 1e8

using namespace std;

int arr[MAXN], ups[MAXN], downs[MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    int maxVal = 0;
    int maxIdx = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      if(arr[i] > maxVal) { maxVal = arr[i]; maxIdx = i; }
    }

    set<int> left;
    ups[0] = 0;
    left.insert(arr[0]);
    for(int i = 1; i < n; i++) {
      ups[i] = ups[i - 1];
      if(i != maxIdx) {
        siterator pos = left.upper_bound(arr[i]);
        ups[i] += distance(pos, left.end());
        left.insert(arr[i]);
      }
    }

    set<int> right;
    downs[n - 1] = 0;
    right.insert(arr[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
      // cerr << "right idx " << i << endl;
      downs[i] = downs[i + 1];
      if(i != maxIdx) {
        siterator pos = right.upper_bound(arr[i]);
        // cerr << "right pos of " << arr[i] << endl;
        // cerr << "dist is " << distance(pos, right.end()) << endl;

        downs[i] += distance(pos, right.end());
        right.insert(arr[i]);
      }
    }

    int best = INF;
    for(int i = 0; i < n; i++) {
      int pivotDist = abs(i - maxIdx);
      int upMoves = (i == 0 ? 0 : ups[i < maxIdx ? i - 1 : i]);
      int downMoves = (i == 0 ? 0 : downs[i > maxIdx ? i + 1 : i]);

      // cerr << "pivot in i " << pivotDist << " " << upMoves << " " <<
      //   downMoves << endl;

      best = min(best, pivotDist + upMoves + downMoves);
    }

    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
