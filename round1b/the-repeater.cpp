#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAXN 100

using namespace std;

vector<int> counts[MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    cerr << n << endl;

    string canon = "";
    vector<int> canonCount;

    bool lost = false;

    for(int i = 0; i < n; i++) {
      string str; cin >> str;
      counts[i].clear();

      if(lost) continue;

      string canon2;

      char last = 0;
      int lastCount = 0;
      for(int j = 0; j < (int) str.length(); j++) {
        if(str[j] != last) {
          if(lastCount > 0)
            counts[i].push_back(lastCount);
          last = str[j];
          lastCount = 1;

          canon2.push_back(str[j]);
        } else {
          lastCount++;
        }
      }
      counts[i].push_back(lastCount);

      if(canon == "") {
        canon = canon2;
      } else if(canon != canon2) {
        lost = true;
      }
    }

    int moves = -1;
    if(!lost) {
      moves = 0;
      for(int i = 0; i < (int) counts[0].size(); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++)
          sum += counts[j][i];

        int avg = round(sum / (double) n);
        for(int j = 0; j < n; j++)
          moves += abs(counts[j][i] - avg);
      }
    }

    cout << "Case #" << tc << ": ";
    if(moves < 0) cout << "Fegla Won" << endl;
    else cout << moves << endl;
  }
  return 0;
}
