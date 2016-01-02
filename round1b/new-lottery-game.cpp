#include <cstring>
#include <iostream>

#define isBitSet(k, b) ((k) >> (b) & 1)

#define ll long long

#define MAXB 30

using namespace std;

int a, b, k;

ll mem[MAXB][2][2][2];

ll calc(int bit, bool anyA, bool anyB, bool anyRes) {
  if(bit < 0) return 1;
  if(mem[bit][anyA][anyB][anyRes] > 0)
    return mem[bit][anyA][anyB][anyRes];

  int maxA = anyA || isBitSet(a, bit);
  int maxB = anyB || isBitSet(b, bit);
  int maxRes = anyRes || isBitSet(k, bit);

  ll res = 0;
  for(int aBit = 0; aBit <= maxA; aBit++) {
    for(int bBit = 0; bBit <= maxB; bBit++) {
      bool resBit = aBit & bBit;
      if(resBit > maxRes) continue;

      res += calc(bit - 1,
        anyA || (maxA > aBit),
        anyB || (maxB > bBit),
        anyRes || (maxRes > resBit));
    }
  }
  return (mem[bit][anyA][anyB][anyRes] = res);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> a >> b >> k; a--; b--; k--;

    memset(mem, 0, sizeof(mem));
    ll res = calc(MAXB - 1, false, false, false);

    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
