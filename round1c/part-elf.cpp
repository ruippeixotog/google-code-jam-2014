#include <cstdio>
#include <iostream>

#define ll long long

using namespace std;

ll gcd(ll u, ll v) {
  while (v != 0) { ll r = u % v; u = v; v = r; }
  return u;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    ll num, denom;
    scanf("%lld/%lld", &num, &denom);

    ll g = gcd(num, denom);
    num /= g;
    denom /= g;

    bool possible = !(denom & (denom - 1));

    int gens = 0;
    if(possible && num != denom) {
      gens++;
      while(num < denom / 2) {
        denom /= 2;
        gens++;
      }
    }

    cout << "Case #" << tc << ": ";
    if(!possible) cout << "impossible" << endl;
    else cout << gens << endl;
  }
  return 0;
}
