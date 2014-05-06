#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define ll long long

#define MAXN 100

using namespace std;

vector<int> counts[MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int a, b, k; cin >> a >> b >> k;

    ll count = 0;
    for(int i = 0; i < a; i++) {
      for(int j = 0; j < b; j++) {
        if((i & j) < k) count++;
      }
    }

    cout << "Case #" << tc << ": " << count << endl;
  }
  return 0;
}
