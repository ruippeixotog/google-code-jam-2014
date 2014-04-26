#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

#define siterator set<double>::iterator

#define PREC 0.000005

using namespace std;

set<double> naomi;

double kenChoice(set<double>& ken, double chosenNaomi) {
  siterator best = ken.upper_bound(chosenNaomi);
  if(best == ken.end()) best = ken.begin();
  double kc = *best;
  ken.erase(best);
  return kc;
}

double naomiTell(set<double>& ken, double chosenNaomi) {
  if(chosenNaomi > *ken.begin()) return *ken.rbegin() + PREC;
  else return *ken.rbegin() - PREC;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    naomi.clear();

    double v;
    set<double> ken1;
    for(int i = 0; i < n; i++) { cin >> v; naomi.insert(v); }
    for(int i = 0; i < n; i++) { cin >> v; ken1.insert(v); }
    set<double> ken2 = ken1;

    int warWins = 0;
    for(siterator it = naomi.begin(); it != naomi.end(); it++) {
      double nval = *it;
      double kval = kenChoice(ken1, nval);
      if(nval > kval) warWins++;
    }

    int dwarWins = 0;
    for(siterator it = naomi.begin(); it != naomi.end(); it++) {
      double nval = *it;
      double ntell = naomiTell(ken2, nval);
      double kval = kenChoice(ken2, ntell);
      if(nval > kval) dwarWins++;
    }

    cout << "Case #" << tc << ": " << dwarWins << " " << warWins << endl;
  }
  return 0;
}
