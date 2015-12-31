#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAXN 100

using namespace std;

int n;
string strs[MAXN];
int idxs[MAXN];

int calcMoves() {
  int moves = 0;
  memset(idxs, 0, sizeof(idxs));

  while(idxs[0] < strs[0].length()) {
    char ch = strs[0][idxs[0]];
    vector<int> counts;

    for(int i = 0; i < n; i++) {
      int cnt = 0;
      while(idxs[i] < strs[i].length() && strs[i][idxs[i]] == ch) {
        idxs[i]++; cnt++;
      }
      if(cnt == 0) return -1;
      counts.push_back(cnt);
    }

    sort(counts.begin(), counts.end());
    int med = counts[n / 2];
    for(int i = 0; i < n; i++) {
      moves += abs(counts[i] - med);
    }
  }

  for(int i = 0; i < n; i++) {
    if(idxs[i] != strs[i].length()) return -1;
  }
  return moves;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> strs[i];

    int moves = calcMoves();

    cout << "Case #" << tc << ": ";
    if(moves < 0) cout << "Fegla Won" << endl;
    else cout << moves << endl;
  }
  return 0;
}
