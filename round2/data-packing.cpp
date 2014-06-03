#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

#define MAXN 20
#define MAXM 20
#define INF 1e8

#define siterator multiset<int>::iterator

using namespace std;

multiset<int> sizes;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, x; cin >> n >> x;

    while(n--) {
      int sz; cin >> sz;
      sizes.insert(sz);
    }

    int count = 0;
    while(!sizes.empty()) {
      int big = *sizes.rbegin();

      siterator last = sizes.end();
      last--;
      sizes.erase(last);

      siterator lowIt = sizes.upper_bound(x - big);
      if(lowIt != sizes.begin()) {
        lowIt--;
        sizes.erase(lowIt);
      }
      count++;
    }

    cout << "Case #" << tc << ": " << count << endl;
  }
  return 0;
}
