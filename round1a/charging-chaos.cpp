#include <iostream>
#include <set>
#include <string>

#define ll long long

#define MAXN 150
#define INF 1e8

using namespace std;

int n, l;
ll devices[MAXN], flows[MAXN];

ll readBin() {
  string str; cin >> str;
  ll b = 0;
  for(int i = 0; i < str.length(); i++) {
    b = (b << 1) + (str[i] == '1');
  }
  return b;
}

int bitCount(ll n) {
  int count = 0;
  while(n) { count++; n &= n - 1; }
  return count;
}

int tryMatch(int d) {
  ll mask = devices[d] ^ flows[0];
  set<ll> deviceSet;
  for(int i = 0; i < n; i++) {
    if(i != d) deviceSet.insert(devices[i]);
  }
  for(int i = 1; i < n; i++) {
    if(!deviceSet.count(flows[i] ^ mask)) return INF;
  }
  return bitCount(mask);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> n >> l;

    for(int i = 0; i < n; i++)
      flows[i] = readBin();

    for(int i = 0; i < n; i++)
      devices[i] = readBin();

    int best = INF;
    for(int i = 0; i < n; i++)
      best = min(best, tryMatch(i));

    cout << "Case #" << tc << ": ";
    if(best == INF) cout << "NOT POSSIBLE" << endl;
    else cout << best << endl;
  }
  return 0;
}
