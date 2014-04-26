#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>

#define siterator set<double>::iterator

#define PREC 0.000001

using namespace std;

set<double> naomi;

double kenChoice(set<double>& ken, double chosenNaomi) {
  siterator best = ken.upper_bound(chosenNaomi);
  if(best == ken.end()) best = ken.begin();
  ken.erase(best);
  return *best;
}

void printSet(set<double>& s) {
  cerr << "set(";
  for(siterator it = s.begin(); it != s.end(); it++) {
    cerr << *it << ",";
  }
  cerr << ")" << endl;
}

double naomiTell(set<double>& ken, double chosenNaomi) {
  // double klast = *ken.rbegin();
  // cerr << "  - ken last is " << klast << " ~ " << (klast + PREC) << "/" << (klast - PREC) << endl;
  if(chosenNaomi > *ken.begin()) return *ken.rbegin() + PREC;
  else return *ken.rbegin() - PREC;
}

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

double genWeight() {
  return (rand() % 99999 + 1) / 100000.0;
}

void genCases() {
  srand(time(NULL));

  int t = 1000; cout << t << endl;
  while(t--) {
    int n = rand() % 2 ? 3 : 4; cout << n << endl;

    cout << genWeight();
    for(int i = 1; i < n; i++) cout << " " << genWeight();
    cout << endl;

    cout << genWeight();
    for(int i = 1; i < n; i++) cout << " " << genWeight();
    cout << endl;
  }
}

bool kused[4];

int kenWarBfs(siterator curr, vector<double>& ken, int wins) {
  if(curr == naomi.end()) return wins;

  int best = 0;
  for(int i = 0; i < (int) ken.size(); i++) {
    if(kused[i]) continue;

    siterator ncopy = curr;
    kused[i] = true;
    best = max(best, kenWarBfs(++ncopy, ken, wins + (ken[i] > *curr)));
    kused[i] = false;
  }
  return best;
}

bool nused[4];

int naomiDwarBfs(vector<double>& naomi, vector<double>& kenv, set<double>& ken, int wins) {
  if(ken.empty()) return wins;

  int best = 0;

  for(int i = 0; i < (int) naomi.size(); i++) {
    if(nused[i]) continue;

    double nval = naomi[i];
    nused[i] = true;

    for(int j = 0; j < (int) kenv.size(); j++) {
      for(int sign = -1; sign <= 1; sign += 2) {
        double ntell = kenv[j] + sign * PREC;

        double kval = kenChoice(ken, ntell);

        if((nval > kval) == (ntell > kval)) {
          kused[j] = true;
          best = max(best, naomiDwarBfs(naomi, kenv, ken, wins + (nval > kval)));
          kused[j] = false;
        }
        ken.insert(kval);
      }
    }

    nused[i] = false;
  }

  return best;
}

#define BF

int main() {
  // genCases(); return 0;

  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    naomi.clear();

    double v;
    set<double> ken1;
    for(int i = 0; i < n; i++) { cin >> v; naomi.insert(v); }
    for(int i = 0; i < n; i++) { cin >> v; ken1.insert(v); }
    set<double> ken2 = ken1;

#ifdef BF
    vector<double> kvec(ken1.begin(), ken1.end());
    int warWins = n - kenWarBfs(naomi.begin(), kvec, 0);
#else
    int warWins = 0;
    for(siterator it = naomi.begin(); it != naomi.end(); it++) {
      double nval = *it;
      double kval = kenChoice(ken1, nval);
      if(nval > kval) warWins++;
    }
#endif

    // cerr << "N: ";
    // printSet(naomi);

#ifdef BF
    vector<double> nvec(naomi.begin(), naomi.end());
    int dwarWins = naomiDwarBfs(nvec, kvec, ken1, 0); 
#else

    int dwarWins = 0;
    for(siterator it = naomi.begin(); it != naomi.end(); it++) {
      // cerr << "--" << endl;
      // cerr << "K: ";
      // printSet(ken2);

      double nval = *it;
      double ntell = naomiTell(ken2, nval);
      double kval = kenChoice(ken2, ntell);
      if(nval > kval) dwarWins++;

      // cerr << "N choose " << nval << endl;
      // cerr << "N tell " << ntell << endl;
      // cerr << "K choose " << kval << endl;
      // if((nval > kval) != (ntell > kval)) cerr << "FAIL!" << endl; 
    }
#endif

    cout << "Case #" << tc << ": " << dwarWins << " " << warWins << endl;
  }
  return 0;
}
